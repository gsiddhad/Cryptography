/*
 *  main.cpp / Rotor Cipher
 *
 *  Created on: 17-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "rotor.h"
using namespace std;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n = 0;
	char *plain, *cipher, *decipher;
	plain = new char[MAX];

	char key[] = "NOATRBECFUXDQGYLKHVIJMPZSW";
	char oriKey[27];
	strcpy(oriKey, key);

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);

	cout << " Enter Initial Position of Rotor : ";
	cin >> n;

	Rotor rotor;
	cipher = rotor.Encrypt(plain, key, n);
	decipher = rotor.Decrypt(cipher, oriKey, n);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Position No.  : " << n;
	cout << "\n Decipher Text : " << decipher;
	return 0;
}
