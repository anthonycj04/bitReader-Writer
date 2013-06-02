#include <iostream>

#include "bitReader.h"
#include "bitWriter.h"

using namespace std;

int main(){
	// ifstream inFile("HW4.pdf", ios::in | ios::binary);
	// ofstream outFile("new", ios::out | ios::binary | ios::trunc);
	BitWriter bitWriter("new");
	BitReader bitReader("HW4.pdf");
	// inFile.seekg(0, inFile.end);
	// int length = inFile.tellg();
	// inFile.seekg(0, inFile.beg);
	
	char c, outC;
	int count = 0;
	while (bitReader.getRemainingBits()){
		bitWriter.writeBit(bitReader.readBit());
	}
	// while (count < length){
		// count++;
		// inFile.get(c);
		// int value = c & 0x01;
		// cout << value;
		// value = c >> 1 & 0x01;
		// cout << value;
		// cout << count << ": ";
		// outC = 0;
		// for (int i = 7; i >= 0; i--){
			// value = c >> i & 0x01;
			// cout << value;
			// if (value)
				// bitWriter.writeBit(true);
			// else
				// bitWriter.writeBit(false);
			// outC <<= 1;
			// outC |= value;
		// }
		// outFile.put(outC);
		// outFile.flush();
		// cout << endl;
	// }
	// cout << "length: " << length << endl;
	// cout << "count: " << count << endl;
	
	// inFile.close();
	bitWriter.close();
	bitReader.close();
	// outFile.close();
	return 0;
}
