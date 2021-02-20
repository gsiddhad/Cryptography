/*
 * File:   main.cpp / Vigenere Cipher
 * Author: Gourav Siddhad
 * Created on 2 October, 2016, 1:18 PM
 */

#include "vigenere.h"
using namespace std;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *key, *cipher, *decipher, *newkey;
	plain = new char[MAX];
	key = new char[MAX];
	newkey = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter Key Text (Max " << MAX - 1 << "): ";
	gets(key);

	Vigenere vigenere;
	cipher = vigenere.Encrypt(plain, key);
	decipher = vigenere.Decrypt(cipher, key);
	newkey = vigenere.Getkey();

	cout << "\n Plain Text  :   " << plain;
	cout << "\n New Key :       " << newkey;
	cout << "\n Cipher Text :   " << cipher;
	cout << "\n Decipher Text : " << decipher;
	return 0;
}
