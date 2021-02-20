/*
 *  main.cpp / Monoalphabetic Substitution Cipher
 *
 *  Created on: 16-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "monoalpha.h"
using namespace std;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher;
	char key[] = "NOATRBECFUXDQGYLKHVIJMPZSW";

	plain = new char[MAX];
	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);

	Monoalpha monoalpha;
	cipher = monoalpha.Encrypt(plain, key);
	decipher = monoalpha.Decrypt(cipher, key);

	cout << "\n Plain Text  :   " << plain;
	cout << "\n Cipher Text :   " << cipher;
	cout << "\n Decipher Text : " << decipher;
	return 0;
}
