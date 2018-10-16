/*
 *  main.cpp / Transposition Cipher
 *
 *  Created on: 18-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "transposition.h"
using namespace std;

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

	Transposition transposition;

	cipher = transposition.Encrypt(plain, key);
	decipher = transposition.Decrypt(cipher, key);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	return 0;
}
