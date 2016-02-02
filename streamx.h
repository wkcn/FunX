#ifndef _STREAMX_H
#define _STREAMX_H

#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class streamx{
	public:
		streamx();
		char get();
		char peek();
		bool eof() const;
		void open(string filename);
		streamx& operator<<(string s);
	private:
		bool eofed;
		stringstream ss;
		ifstream fin;
		char c;
		void next();
};

#endif
