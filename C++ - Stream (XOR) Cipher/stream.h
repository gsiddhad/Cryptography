/*
 *  stream.h / Stream Cipher (XOR)
 *
 *  Created on: 19-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef STREAM_H_
#define STREAM_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Stream {
	char *cipher, *decipher;
public:
	Stream() {
		cipher = new char[MAX];
		decipher = new char[MAX];
	}

	char* Encrypt(char *plain, char *key) {
		unsigned int position = 0;
		unsigned int i = 0;
		for (i = 0; i < strlen(plain); i++) {
			cipher[i] = (plain[i] ^ key[position]);
			position++;
			if (position == strlen(key))
				position = 0;
		}
		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char *plain, char *key) {
		unsigned int position = 0;
		unsigned int i = 0;
		for (i = 0; i < strlen(plain); i++) {
			decipher[i] = (plain[i] ^ key[position]);
			position++;
			if (position == strlen(key))
				position = 0;
		}
		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}
};

#endif /* STREAM_H_ */
