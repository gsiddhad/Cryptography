/*
 *  main.cpp / One Time Pad Cipher
 *
 *  Created on: 17-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "onetimepad.h"
using namespace std;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	srand((unsigned)time(0));

	char *plain, *key, *cipher, *decipher, *newkey;
	plain = new char[MAX];
	key = new char[MAX];
	newkey = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << ") : ";
	gets(plain);

	cout << " Generating a Random Secret Key ... \n\n";

	unsigned int i = 0;
	bool flag = false;

	for (i = 0; i < strlen(plain); i++)
	{
		flag = rand() % 2;
		if (flag)
			key[i] = rand() % 26 + 65;
		else
			key[i] = rand() % 26 + 97;
	}
	key[i] = '\0';

	cout << " Key : " << key;

	Onetimepad onetimepad;
	cipher = onetimepad.Encrypt(plain, key);
	decipher = onetimepad.Decrypt(cipher, key);
	newkey = onetimepad.Getkey();

	cout << "\n Plain Text    : " << plain;
	cout << "\n Key           : " << newkey;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Decipher Text : " << decipher;
	return 0;
}
