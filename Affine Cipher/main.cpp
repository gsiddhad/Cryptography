/*
 *  main.cpp / Affine Cipher
 *
 *  Created on: 06-Aug-2016
 *      Author: Gourav Siddhad
 */

#include "affine.h"

using namespace std;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher;
	int a = 1, b = 0;

	plain = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	//Should be odd for one to one mapping
	cout << " Enter a (Should be odd) : ";
	cin >> a;
	cout << " Enter b : ";
	cin >> b;

	Affine affine;
	cipher = affine.Encrypt(plain, a, b);
	decipher = affine.Decrypt(cipher, a, b);

	cout << "\n Plain Text  : " << plain;
	cout << "\n Cipher Text : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	return 0;
}
