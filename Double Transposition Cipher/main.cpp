/*
 *  main.cpp / Double Transposition Cipher
 *
 *  Created on: 18-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "doubletrans.h"
using namespace std;

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher1, *cipher2, *decipher1, *decipher2, *key[2];
	plain = new char[MAX];
	key[0] = new char[MAX];
	key[1] = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter First Key  : ";
	gets(key[0]);
	cout << " Enter Second Key : ";
	gets(key[1]);

	Transposition transposition;

	cipher1 = transposition.Encrypt(plain, key[0]);
	cipher2 = transposition.Encrypt(cipher1, key[1]);
	decipher1 = transposition.Decrypt(cipher2, key[1]);
	decipher2 = transposition.Decrypt(decipher1, key[0]);

	return 0;
}
