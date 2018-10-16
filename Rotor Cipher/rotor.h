/*
 *  rotor.h / Rotor Cipher
 *
 *  Created on: 17-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef ROTOR_H_
#define ROTOR_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Rotor {
	char *cipher, *decipher;
	int count;
public:
	Rotor() {
		cipher = new char[MAX];
		decipher = new char[MAX];
		count = 0;
	}

	char* Encrypt(char* plain, char* key, int n) {
		int i = 0;

		for (i = 0; i < n; i++)
			RightShift(key);

		cout << "\n Key : " << key;
		for (i = 0; plain[i] != '\0'; i++) {
			if (isupper(plain[i])) {
				cipher[i] = key[plain[i] - 65];
				RightShift(key);
			} else if (islower(plain[i])) {
				cipher[i] = key[plain[i] - 97] - 65 + 97;
				RightShift(key);
			}
			else
				cipher[i] = plain[i];
		}

		cout << "\n Key : " << key;
		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char* plain, char* key, int n) {
		int i = 0, pos = 0;

		for (i = 0; i < n; i++)
			RightShift(key);

		cout << "\n Key : " << key;
		for (i = 0; plain[i] != '\0'; i++) {

			for (int j = 0; j < 26; j++)
				if (toupper(plain[i]) == key[j])
					pos = j;

			if (isupper(plain[i])) {
				decipher[i] = char(pos) + 65;
				RightShift(key);
			} else if (islower(plain[i])) {
				decipher[i] = char(pos) + 97;
				RightShift(key);
			} else
				decipher[i] = plain[i];
		}
		cout << "\n Key : " << key;

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

	int getPosition() {
		return count;
	}

private:
	void RightShift(char* key) {
		int temp = key[25];
		for (int i = 25; i > 0; i--)
			key[i] = key[i - 1];
		key[0] = temp;
		count++;
	}

	void Leftshift(char* key) {
		int temp = key[0];
		for (int i = 0; i < 26; i++)
			key[i] = key[i + 1];
		key[25] = temp;
		cout << key << endl;
		count--;
	}
};

#endif /* ROTOR_H_ */
