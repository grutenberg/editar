#include<iostream>
#include "core.h"
#include <termios.h>
#include <unistd.h>

using namespace std;

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= (ECHO) & ~ICANON;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
	enableRawMode();

	BufferModule module1 = BufferModule();
	BufferModule module2 = BufferModule();
	CompositeModule cont = CompositeModule();

	cont.add_module(&module1);
	cont.add_module(&module2);

	char input; 

	while (read(STDIN_FILENO, &input, 1) == 1 && input != 'q'){
		module1.append_at_pointer(input);
	}
	while (read(STDIN_FILENO, &input, 1) == 1 && input != 'q'){
		module2.append_at_pointer(input);
	}
	module1.print_buffer();
	module2.print_buffer();

	cont.print_buffer();	

	cout<<"Hola mundo"<<endl;
	return 0;
}
