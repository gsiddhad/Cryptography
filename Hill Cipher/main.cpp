/*
 *  main.cpp / Hill Cipher
 *  Created on: 14-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "hillcipher.h"

using namespace std;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char *plain, *cipher, *decipher;
	int key = 0;
	plain = new char[MAX];

	cout << " Enter Plain Text (Max " << MAX - 1 << "): ";
	gets(plain);
	cout << " Enter Key Matrix Size (Greater than 0) : ";
	cin >> key;
	int **kmatrix = new int *[key];
	for (int i = 0; i < key; i++)
		kmatrix[i] = new int[key];

	cout << " Enter Key Matrix ( " << key * key << " Values ) : ";
	for (int i = 0; i < key; i++)
		for (int j = 0; j < key; j++)
			cin >> kmatrix[i][j];

	for (int i = 0; i < key; i++)
	{
		for (int j = 0; j < key; j++)
		{
			cout << " " << kmatrix[i][j];
		}
		cout << endl;
	}

	char *newtext = new char[MAX];
	int j = 0;
	for (unsigned int i = 0; i <= strlen(plain); i++)
	{
		if (isupper(plain[i]) || islower(plain[i]))
		{
			newtext[j] = plain[i];
			j++;
		}
	}

	strcpy(plain, newtext);

	Hillcipher hillcipher;
	cipher = hillcipher.Encrypt(plain, key, kmatrix);
	decipher = hillcipher.Decrypt(cipher, key, kmatrix);

	cout << "\n Plain Text    : " << plain;
	cout << "\n Cipher Text   : " << cipher;
	cout << "\n Decipher Text : " << decipher;

	return 0;
}
