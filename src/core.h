
#ifndef __CORE__
#define __CORE__

class BufferModule {
private:
	char* buffer;
	int buffer_len;
	int pointer_position;
public:
	BufferModule();
	void append_at_pointer(char);
	void resize_buffer();
	void print_buffer();
	void at_pointer(char);
};

//class CompoundModule;

#endif
