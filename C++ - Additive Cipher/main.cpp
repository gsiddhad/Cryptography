/*
 * main.cpp / Additive Cipher
 *
 *  Created on: 31-Jul-2016
 *      Author: Gourav Siddhad
 */

#include "additive.h"
#include "conio.h"

using namespace std;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher;
	int key = 0;
	plain = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter Shift Number : ";
	cin >> key;

	while (key < 0) {
		key += 26;
	}

	Additive additive;
	cipher = additive.Encrypt(plain, key);
	decipher = additive.Decrypt(cipher, key);

	cout << "\n Plain Text  : " << plain;
	cout << "\n Cipher Text : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	getch();
	return 0;
}
