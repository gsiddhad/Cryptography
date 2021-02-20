/*
 *  main.cpp / Play Cipher
 *
 *  Created on: 21-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "play.h"
using namespace std;

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher, *key;
	plain = new char[MAX];
	key = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter Cipher Key : ";
	gets(key);

	for (unsigned int i = 0; i < strlen(key); i++)
		key[i] = tolower(key[i]);

	bool flag = true;
	int length = strlen(key);
	for (int i = 0; i < 26; i++)
	{
		char ch = i + 97;
		for (int j = 0; j < length; j++)
		{
			if (key[j] == ch || ch == 'j')
			{
				flag = true;
				break;
			}
			flag = false;
		}
		if (!flag)
		{
			key[length] = ch;
			length++;
			key[length] = '\0';
		}
	}

	int count = 0;
	char keymat[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			keymat[i][j] = key[count++];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << " " << keymat[i][j];
		}
		cout << endl;
	}

	Play play;
	cipher = play.Encrypt(plain, keymat);
	decipher = play.Decrypt(cipher, keymat);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Key           : " << key;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	return 0;
}
