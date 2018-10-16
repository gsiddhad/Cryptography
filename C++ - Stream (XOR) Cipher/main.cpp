/*
 *  main.cpp / Stream Cipher (XOR)
 *
 *  Created on: 19-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "stream.h"
#include "bitset"
using namespace std;

void printBinary(char);

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher, *key = 0;
	plain = new char[MAX];
	key = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter Key : ";
	gets(key);

	Stream stream;

	cipher = stream.Encrypt(plain, key);
	decipher = stream.Decrypt(cipher, key);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Decipher Text : " << decipher << endl;

	cout << endl;
	for (unsigned int i = 0; i < strlen(plain); i++) {
		cout << " ";
//		printBinary(plain[i]);
		cout << std::bitset<8>(plain[i]);
	}
	cout << endl;
	unsigned int position = 0;
	for (unsigned int i = 0; i < strlen(plain); i++) {
		cout << " ";
//		printBinary(key[position]);
		cout << std::bitset<8>(key[position]);
		position++;
		if (position == strlen(key))
			position = 0;
	}
	cout << endl;
	for (unsigned int i = 0; i < strlen(plain); i++) {
		cout << " ";
//		printBinary(cipher[i]);
		cout << std::bitset<8>(cipher[i]);
	}

	return 0;
}

void printBinary(char c) {
	for (int i = 7; i >= 0; --i) {
		std::cout << ((c & (1 << i)) ? '1' : '0');
	}
}
