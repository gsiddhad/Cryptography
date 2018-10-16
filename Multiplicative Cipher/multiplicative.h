/*
 * multiplicative.h / Multiplicative
 *
 *  Created on: 07-Aug-2016
 *      Author: Gourav Siddhad
 */

#ifndef MULTIPLICATIVE_H_
#define MULTIPLICATIVE_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"
#include "cmath"
using namespace std;

#define MAX 51

class Multiplicative {
	char *cipher, *decipher;

public:
	Multiplicative() {
		cipher = new char[MAX];
		decipher = new char[MAX];
	}

	char* Encrypt(char* plain, int a) {
		int i = 0;
		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				cipher[i] = (((plain[i] - 65) * a) % 26) + 65;
			else if (islower(plain[i]))
				cipher[i] = (((plain[i] - 97) * a) % 26) + 97;
			else
				cipher[i] = plain[i];
		}

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char* plain, int a) {
		int i = 0;
		int inv = Inverse(a);

		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i]))
				decipher[i] = (inv * ((plain[i] - 65) + 104) % 26) + 65;
			else if (islower(plain[i]))
				decipher[i] = (inv * ((plain[i] - 97) + 104) % 26) + 97;
			else
				decipher[i] = plain[i];
		} // 104 = 26*4 for not letting negative numbers

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

private:
	int Inverse(int number) {
		for (int i = 1; i < 26; i++) {
			if ((i * number) % 26 == 1)
				return i;
		}
		return 1;
	}

};

#endif /* MULTIPLICATIVE_H_ */
