/*
 * additive.h / Additive Cipher
 *
 *  Created on: 31-Jul-2016
 *      Author: Gourav Siddhad
 */

#ifndef ADDITIVE_H_
#define ADDITIVE_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Additive {
	char *cipher, *decipher;

public:
	Additive() {
		cipher = new char[MAX];
		decipher = new char[MAX];
	}

	char* Encrypt(char* plain, int key) {
		int i = 0;
		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				cipher[i] = (((plain[i] - 65) + key) % 26) + 65;
			else if (islower(plain[i]))
				cipher[i] = (((plain[i] - 97) + key) % 26) + 97;
			else
				cipher[i] = plain[i];
		}

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char* plain, int key) {
		key = 26 - key;
		int i = 0;
		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				decipher[i] = (((plain[i] - 65) + key) % 26) + 65;
			else if (islower(plain[i]))
				decipher[i] = (((plain[i] - 97) + key) % 26) + 97;
			else
				decipher[i] = plain[i];
		}

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}
};

#endif /* ADDITIVE_H_ */
