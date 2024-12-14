
#ifndef __CORE__
#define __CORE__

#include <list>

class CoreModule {
public:
	virtual void print_buffer() = 0;
private:
};

class BufferModule : public CoreModule {
private:
	char* buffer;
	int buffer_len;
	int pointer_position;
public:
	BufferModule();
	void append_at_pointer(char);
	void resize_buffer();
	void at_pointer(char);
	void print_buffer() override;
};

class CompositeModule : public CoreModule {
private:
	std::list<CoreModule*> modules;
public:
	void add_module(CoreModule*); 
	void print_buffer() override;
};

#endif
