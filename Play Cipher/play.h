/*
 *  play.h / Play Cipher
 *
 *  Created on: 21-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef PLAY_H_
#define PLAY_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Play
{
	char *cipher, *decipher;
	int mat[26][2];

public:
	Play()
	{
		cipher = new char[MAX];
		decipher = new char[MAX];
	}

	char *Encrypt(char *plain, char keymat[5][5])
	{
		unsigned int i = 0;
		int length = 0;
		char *newtext = new char[MAX];
		for (i = 0; i < strlen(plain); i++)
		{
			if (islower(plain[i]))
				newtext[length++] = plain[i];
			if (isupper(plain[i]))
				newtext[length++] = tolower(plain[i]);
		}
		newtext[length] = '\0';

		for (i = 1; i < strlen(newtext); i++)
		{
			if (newtext[i - 1] == newtext[i])
			{
				newtext[i] = 'x';
			}
		}

		length = strlen(newtext);
		if (length % 2 == 1)
		{
			newtext[length++] = 'x';
			newtext[length] = '\0';
		}
		strcpy(plain, newtext);

		for (i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				mat[keymat[i][j] - 97][0] = i;
				mat[keymat[i][j] - 97][1] = j;
			}
		}
		mat[9][0] = mat[8][0];
		mat[9][1] = mat[8][1];

		int ch[2];
		for (i = 0; i < strlen(plain); i += 2)
		{
			ch[0] = plain[i] - 97;
			ch[1] = plain[i + 1] - 97;

			// Test 1 (Not Row or Column Match)
			if (mat[ch[0]][0] != mat[ch[1]][0] && mat[ch[0]][1] != mat[ch[1]][1])
			{
				cipher[i] = (char)keymat[mat[ch[0]][0]][mat[ch[1]][1]];
				cipher[i + 1] = (char)keymat[mat[ch[1]][0]][mat[ch[0]][1]];
			}
			else if (mat[ch[0]][0] == mat[ch[1]][0])
			{ // Test 2 (Same Row)
				cipher[i] =
					(char)keymat[mat[ch[0]][0]][(mat[ch[0]][1] + 1) % 5];
				cipher[i + 1] = (char)keymat[mat[ch[1]][0]][(mat[ch[1]][1] + 1) % 5];
			}
			else if (mat[ch[0]][1] == mat[ch[1]][1])
			{ // Test 3 (Same Column)
				cipher[i] =
					(char)keymat[(mat[ch[0]][0] + 1) % 5][mat[ch[0]][1]];
				cipher[i + 1] =
					(char)keymat[(mat[ch[1]][0] + 1) % 5][mat[ch[1]][1]];
			}
		}

		i++;
		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char *Decrypt(char *plain, char keymat[5][5])
	{
		unsigned int i = 0;

		int ch[2];
		for (i = 0; i < strlen(plain); i += 2)
		{
			ch[0] = plain[i] - 97;
			ch[1] = plain[i + 1] - 97;

			// Test 1 (Not Row or Column Match)
			if (mat[ch[0]][0] != mat[ch[1]][0] && mat[ch[0]][1] != mat[ch[1]][1])
			{
				decipher[i] = (char)keymat[mat[ch[0]][0]][mat[ch[1]][1]];
				decipher[i + 1] = (char)keymat[mat[ch[1]][0]][mat[ch[0]][1]];
			}
			else if (mat[ch[0]][0] == mat[ch[1]][0])
			{ // Test 2 (Same Row)
				decipher[i] =
					(char)keymat[mat[ch[0]][0]][mod(
						mat[ch[0]][1] - 1, 5)];
				decipher[i + 1] = (char)keymat[mat[ch[1]][0]][mod(
					mat[ch[1]][1] - 1, 5)];
			}
			else if (mat[ch[0]][1] == mat[ch[1]][1])
			{ // Test 3 (Same Column)
				decipher[i] =
					(char)keymat[mod(mat[ch[0]][0] - 1, 5)][mat[ch[0]][1]];
				decipher[i + 1] =
					(char)keymat[mod(mat[ch[1]][0] - 1, 5)][mat[ch[1]][1]];
			}
		}

		i++;

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

	int mod(int a, int b)
	{
		int res = a % b;
		while (res < 0)
			res += b;
		return res;
	}
};

#endif /* PLAY_H_ */
