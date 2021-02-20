/*
 *  enigma.h / Enigma Machine
 *
 *  Created on: 18-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef ENIGMA_H_
#define ENIGMA_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 101
using namespace std;

class Enigma
{
	char *cipher, *decipher;
	int count[3];

public:
	Enigma()
	{
		cipher = new char[MAX];
		decipher = new char[MAX];
		count[0] = 0;
		count[1] = 0;
		count[2] = 0;
	}

	char *Encrypt(char *plain, char key[3][27], int n[3])
	{
		int i = 0;
		bool flag = false;

		for (i = 0; i < n[0]; i++)
			RightShift((char *)key[0]);
		for (i = 0; i < n[1]; i++)
			RightShift((char *)key[1]);
		for (i = 0; i < n[2]; i++)
			RightShift((char *)key[2]);

		char temp = 0;
		for (i = 0; plain[i] != '\0'; i++)
		{
			if (isupper(plain[i]))
			{
				temp = (char)(key[0][plain[i] - 65]);
				temp = (char)(key[1][temp - 65]);
				cipher[i] = (char)(key[2][temp - 65]);
				flag = true;
			}
			else if (islower(plain[i]))
			{
				temp = (char)(key[0][plain[i] - 97] - 65 + 97);
				temp = (char)(key[1][temp - 97] - 65 + 97);
				cipher[i] = (char)(key[2][temp - 97] - 65 + 97);
				flag = true;
			}
			else
			{
				cipher[i] = plain[i];
				flag = false;
			}

			if (flag)
			{
				RightShift((char *)key[2]);
				n[2]++;

				if (n[2] > 25)
				{
					n[2] = n[2] % 26;
					RightShift((char *)key[1]);
					n[1]++;

					if (n[1] > 25)
					{
						n[1] = n[1] % 26;
						RightShift((char *)key[0]);
						n[0]++;

						if (n[0] > 25)
						{
							n[0] = n[0] % 26;
						}
					}
				}
			}

			cout << n[0] << " " << n[1] << " " << n[2] << endl;
			for (int i = 0; i < 26; i++)
				cout << (char)(i + 65);
			cout << endl;
			cout << key[0] << endl;
			cout << key[1] << endl;
			cout << key[2] << endl
				 << endl;
		}

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char *Decrypt(char *plain, char key[3][27], int n[3])
	{
		int i = 0, pos = 0;
		bool flag = false;

		for (i = 0; i < n[0]; i++)
			RightShift((char *)key[0]);
		for (i = 0; i < n[1]; i++)
			RightShift((char *)key[1]);
		for (i = 0; i < n[2]; i++)
			RightShift((char *)key[2]);

		for (i = 0; plain[i] != '\0'; i++)
		{
			int tempos = 0;
			pos = 0;

			for (int j = 0; j < 26; j++)
				if (toupper(plain[i]) == key[2][j])
					pos = j;
			for (int j = 0; j < 26; j++)
				if ((char)(pos + 65) == key[1][j])
					tempos = j;
			for (int j = 0; j < 26; j++)
				if ((char)(tempos + 65) == key[0][j])
					pos = j;

			if (isupper(plain[i]))
			{
				decipher[i] = char(pos) + 65;
				flag = true;
			}
			else if (islower(plain[i]))
			{
				decipher[i] = char(pos) + 97;
				flag = true;
			}
			else
			{
				decipher[i] = plain[i];
				flag = false;
			}

			if (flag)
			{
				RightShift((char *)key[2]);
				n[2]++;

				if (n[2] > 25)
				{
					n[2] = n[2] % 26;
					RightShift((char *)key[1]);
					n[1]++;

					if (n[1] > 25)
					{
						n[1] = n[1] % 26;
						RightShift((char *)key[0]);
						n[0]++;

						if (n[0] > 25)
						{
							n[0] = n[0] % 26;
						}
					}
				}
			}
		}

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

private:
	void RightShift(char *key)
	{
		int temp = key[25];
		for (int i = 25; i > 0; i--)
			key[i] = key[i - 1];
		key[0] = temp;
	}
};
#endif /* ENIGMA_H_ */
