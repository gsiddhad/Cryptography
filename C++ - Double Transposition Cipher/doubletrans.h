/*
 *  doubletrans.h / Double Transposition Cipher
 *
 *  Created on: 18-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef DOUBLETRANS_H_
#define DOUBLETRANS_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 101
using namespace std;

class Transposition {
	char *cipher, *decipher;
	int counter;

public:
	Transposition() {
		cipher = new char[MAX];
		decipher = new char[MAX];
		counter = 0;
	}

	char* Encrypt(char* plain, char* key) {
		counter = strlen(plain);
		float len = (float) strlen(plain) / strlen(key);
		unsigned int length = len;
		if (len > length)
			length++;

		char **mat = new char*[length];
		for (unsigned int i = 0; i < length; i++)
			mat[i] = new char[strlen(key)];

		unsigned int count = 0;
		for (unsigned int i = 0; i < length; i++)
			for (unsigned int j = 0; j < strlen(key); j++) {
				if (count < strlen(plain))
					mat[i][j] = plain[count];
				else
					mat[i][j] = '.';
				count++;
			}

		cout << endl;
		for (unsigned int i = 0; i < strlen(key); i++)
			cout << " " << key[i];
		cout << endl;
		for (unsigned int i = 0; i < strlen(key); i++)
			cout << "--";
		cout << endl;

		for (unsigned int i = 0; i < length; i++) {
			for (unsigned int j = 0; j < strlen(key); j++) {
				cout << " " << mat[i][j];
			}
			cout << endl;
		}

		int *num = new int[strlen(key)];
		for (unsigned int i = 0; i < strlen(key); i++) {
			if (isupper(key[i]))
				num[i] = key[i] - 65;
			else if (islower(key[i]))
				num[i] = key[i] - 97;
		}

		count = 0;
		for (unsigned int i = 0; i < strlen(key); i++) {
			int min = 0;
			for (unsigned int j = 1; j < strlen(key); j++)
				if (num[j] < num[min])
					min = j;

			for (unsigned int k = 0; k < length; k++) {
				cipher[count] = mat[k][min];
				count++;
			}
			num[min] = 99;
		}

		if (count < MAX)
			cipher[count] = '\0';
		else
			cipher[MAX - 1] = '\0';

		cout << endl << " Cipher Text : " << cipher;
		return cipher;
	}

	char* Decrypt(char* plain, char *key) {
		float len = (float) strlen(plain) / strlen(key);
		unsigned int length = len;
		if (len > length)
			length++;

		char **mat = new char*[length];
		for (unsigned int i = 0; i < length; i++)
			mat[i] = new char[strlen(key)];

		int *num = new int[strlen(key)];
		for (unsigned int i = 0; i < strlen(key); i++) {
			if (isupper(key[i]))
				num[i] = key[i] - 65;
			else if (islower(key[i]))
				num[i] = key[i] - 97;
		}

		unsigned int count = 0;
		for (unsigned int i = 0; i < strlen(key); i++) {
			int min = 0;
			for (unsigned int j = 1; j < strlen(key); j++)
				if (num[j] < num[min])
					min = j;

			for (unsigned int k = 0; k < length; k++) {
				mat[k][min] = plain[count];
				count++;
			}
			num[min] = 99;
		}

		count = 0;
		for (unsigned int i = 0; i < length; i++)
			for (unsigned int j = 0; j < strlen(key); j++) {
				if (count < strlen(plain))
					decipher[count] = mat[i][j];
				else if (count > strlen(plain)) {
					decipher[count] = '\0';
					break;
				}
				count++;
			}

		if (count < MAX)
			decipher[count] = '\0';
		else
			decipher[MAX - 1] = '\0';

		decipher[counter] = '\0';
		cout << endl << " Decipher Text : " << decipher;
		return decipher;
	}

	void printMatrix(char **mat, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << " " << mat[n][m];
			}
			cout << endl;
		}
	}
};

#endif /* DOUBLETRANS_H_ */
