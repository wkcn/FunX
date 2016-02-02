#include "streamx.h"

streamx::streamx(){
	eofed = true;
}

void streamx::next(){
	c = ss.get();
	if (ss.eof()){
		c = fin.get();
		if (fin.eof()){
			eofed = true;
			c = 0;
		}
	}
}

char streamx::get(){
	char o = c;
	next();
	return o;
}

char streamx::peek(){
	return c;
}

bool streamx::eof() const{
	return eofed;
}

void streamx::open(string filename){
	fin.open(filename.c_str());
	eofed = false;
	next();
}

streamx& streamx::operator<<(string s){
	ss << s;
	eofed = false;
	next();
	return *this;
}
