#include <iostream>
#include <fstream>

using namespace std;

class BitReader{
private:
	int fileLength;
	int currentPosition;
	int bitPosition;
	ifstream fileHandler;
	char buffer;
	
public:
	BitReader(){
	}	

	void open(const char * fileName){
		fileHandler.open(fileName, ios::in | ios::binary);
		fileHandler.seekg(0, fileHandler.end);
		fileLength = fileHandler.tellg();
		fileHandler.seekg(0, fileHandler.beg);
		bitPosition = currentPosition = 0;
		if (fileLength > currentPosition){
			currentPosition++;
			fileHandler.get(buffer);
			bitPosition = 7;
		}
	}

	BitReader(const char * fileName){
		open(fileName);
	}

	int getRemainingBits(){
		return (fileLength - currentPosition) * 8 + bitPosition + 1;
	}

	bool readBit(){
		if (getRemainingBits() > 0){
			bool result = (buffer >> bitPosition-- & 0x01)?true:false;
			if (bitPosition < 0 && fileLength - currentPosition){
				currentPosition++;
				fileHandler.get(buffer);
				bitPosition = 7;
			}
			return result;
		}
		else
			cout << "check remaining bits before reading!!!";
		return false;
	}

	void close(){
		fileHandler.close();
	}

	int getFileLength(){
		return fileLength;
	}
};
