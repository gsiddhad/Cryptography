/*
 * File:   vigenere.h / Vigenere Cipher
 * Author: Gourav Siddhad
 * Created on 2 October, 2016, 1:30 PM
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Vigenere {
	char *cipher, *decipher, *newkey;

public:
	Vigenere() {
		cipher = new char[MAX];
		decipher = new char[MAX];
		newkey = new char[MAX];
	}

	char* Encrypt(char* plain, char* key) {
		int i = 0;

		newkey = GenNewKey(key, plain);

		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				cipher[i] = (((plain[i] - 65) + (newkey[i] - 65)) % 26) + 65;
			else if (islower(plain[i]))
				cipher[i] = (((plain[i] - 97) + (newkey[i] - 65)) % 26) + 97;
			else
				cipher[i] = plain[i];
		}

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char* plain, char* key) {
		int i = 0;
		newkey = GenNewKey(key, plain);

		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				decipher[i] = (((plain[i] - 65) + 26 - (newkey[i] - 65)) % 26)
						+ 65;
			else if (islower(plain[i]))
				decipher[i] = (((plain[i] - 97) + 26 - (newkey[i] - 65)) % 26)
						+ 97;
			else
				decipher[i] = plain[i];
		}

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

	char* GenNewKey(char* key, char* plain) {
		int i = 0, j = 0;
		for (i = 0; plain[i] != '\0'; i++, j++) {
			if (key[j] == '\0')
				j = 0;
			newkey[i] = toupper(key[j]);
		}
		newkey[i] = '\0';
		return newkey;
	}

	char* Getkey() {
		return newkey;
	}

};

#endif /* VIGENERE_H */
