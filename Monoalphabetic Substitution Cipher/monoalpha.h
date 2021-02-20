/*
 *  monoalpha.h / Monoalphabetic Substitution Cipher
 *
 *  Created on: 16-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef MONOALPHA_H_
#define MONOALPHA_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Monoalpha
{
	char *cipher, *decipher;

public:
	Monoalpha()
	{
		cipher = new char[MAX];
		decipher = new char[MAX];
	}

	char *Encrypt(char *plain, char *key)
	{
		int i = 0;

		for (i = 0; plain[i] != '\0'; i++)
		{
			if (isupper(plain[i]))
				cipher[i] = key[plain[i] - 65];
			else if (islower(plain[i]))
				cipher[i] = key[plain[i] - 97] - 65 + 97;
			else
				cipher[i] = plain[i];
		}

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char *Decrypt(char *plain, char *key)
	{
		int i = 0, pos = 0;
		for (i = 0; plain[i] != '\0'; i++)
		{

			for (int j = 0; j < 26; j++)
				if (toupper(plain[i]) == key[j])
					pos = j;

			if (isupper(plain[i]))
				decipher[i] = char(pos) + 65;
			else if (islower(plain[i]))
				decipher[i] = char(pos) + 97;
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

#endif /* MONOALPHA_H_ */
