#include<iostream>
#include<string.h>

#include "core.h"

using namespace std;

BufferModule::BufferModule(void){
	buffer = (char*)malloc(sizeof(char)*2);
	pointer_position = 0;
	buffer_len = 2;
}

void BufferModule::append_at_pointer(char new_char){
	this->at_pointer(new_char);	
	pointer_position++;
	if (pointer_position == buffer_len){
		this->resize_buffer();
	}
}

void BufferModule::resize_buffer(){
	buffer_len*=2;
	char* new_buff = (char*)malloc(sizeof(char)*buffer_len);
	strcpy(new_buff, buffer);
	buffer = new_buff;
}

void BufferModule::at_pointer(char new_char){
	buffer[pointer_position] = new_char;
}

void BufferModule::print_buffer(){
	cout<<buffer<<endl;
}
