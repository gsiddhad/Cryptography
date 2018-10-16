/*
 *  main.cpp / Enigma Machine
 *
 *  Created on: 18-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "enigma.h"
using namespace std;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n[3], orin[3];
	char *plain, *cipher, *decipher;
	plain = new char[MAX];

	char key[3][27] = { "NOATRBECFUXDQGYLKHVIJMPZSW",
			"BDFHJLCPRTXVZNYEIWGAKMUSQO", "EKMFLGDQVZNTOWYHXUSPAIBRCJ" };

	char oriKey[3][27];
	strcpy(oriKey[0], key[0]);
	strcpy(oriKey[1], key[1]);
	strcpy(oriKey[2], key[2]);

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);

	cout << " Enter Initial Positions of Enigma : ";
	for (int i = 0; i < 3; i++) {
		cin >> n[i];
		orin[i] = n[i];
	}

	Enigma enigma;
	cipher = enigma.Encrypt(plain, key, n);
	decipher = enigma.Decrypt(cipher, oriKey, orin);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Position No.  : ";
	for (int i = 0; i < 3; i++)
		cout << n[i] << " ";
	cout << "\n Decipher Text : " << decipher;
	return 0;
}
