/*
 * main.cpp / Multiplicative
 *
 *  Created on: 07-Aug-2016
 *      Author: Gourav Siddhad
 */

#include "multiplicative.h"

using namespace std;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher;
	int a = 1;

	plain = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	// Key must be odd for one to one mapping
	cout << " Enter a (Should be odd) : ";
	cin >> a;

	Multiplicative multiplicative;
	cipher = multiplicative.Encrypt(plain, a);
	decipher = multiplicative.Decrypt(cipher, a);

	cout << "\n Plain Text  : " << plain;
	cout << "\n Cipher Text : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	return 0;
}
