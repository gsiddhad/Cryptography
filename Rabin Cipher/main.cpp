/*
 * main.cpp / Rabin Cipher
 *
 *  Created on: 21-Oct-2016
 *      Author: Gourav Siddhad
 */

#include "rabin.h"
using namespace std;

bool isprime(int);

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int cipher = 0, plain = 0;
	long *decipher;
	int p = 0, q = 0;

	// 7, 11, 19
	cout << " Enter Two Prime Numbers = 3(mod 4) : ";
	cin >> p;
	cin >> q;

	cout << " Enter Number to Encrypt ( 0 to " << p * q << " ) : ";
	cin >> plain;

	if (isprime(p) && isprime(q))
	{
		cout << " Public Key is : " << p * q << endl;
		Rabin rabin;
		cipher = rabin.Encrypt(plain, p * q);
		decipher = rabin.Decrypt(cipher, p, q);

		cout << "\n Plain Text    : " << plain;
		cout << "\n Cipher Text   : " << cipher;
		cout << "\n p : " << p << " q : " << q;
		cout << "\n Decipher Text : ";
		for (int i = 0; i < 4; i++)
			cout << " " << decipher[i];
	}
	else
	{
		cout << p << " or " << q << " is/both not Prime";
	}
	return 0;
}

bool isprime(int number)
{
	bool flag = true;
	for (int i = 2; i <= number / 2; i++)
		if (number % i == 0)
			return false;
	return flag;
}
