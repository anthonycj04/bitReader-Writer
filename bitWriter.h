#include <iostream>
#include <fstream>

using namespace std;

class BitWriter{
private:
	ofstream fileHandler;
	char buffer;
	int writtenBits;

public:
	BitWriter(){
	}

	void open(const char* fileName){
		fileHandler.open(fileName, ios::out | ios::binary | ios::trunc);
		buffer = '\0';
		writtenBits = 0;
	}

	BitWriter(const char * fileName){
		open(fileName);
	}
	

	void writeBits(bool* bits, int length){

	}

	void writeBit(bool bit){
		buffer <<= 1;
		if (bit)
			buffer |= 1;
		if (++writtenBits >= 8){
			fileHandler.put(buffer);
			// fileHandler.flush();
			buffer = '\0';
			writtenBits = 0;
		}
	}

	void close(){
		if (writtenBits > 0){
			buffer <<= (8 - writtenBits);
			fileHandler.put(buffer);
		}
		fileHandler.close();
	}
};
