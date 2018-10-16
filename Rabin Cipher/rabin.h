/*
 *  rabin.h / Rabin Cipher
 *
 *  Created on: 21-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef RABIN_H_
#define RABIN_H_

#include "iostream"
#include "cstring"
#include "cctype"
#include "cmath"
#include "cstdio"

using namespace std;

class Rabin {
	int cipher;
	long *decipher;
public:
	Rabin() {
		cipher = 0;
		decipher = new long[4];
	}

	int Encrypt(int plain, int pq) {
		cipher = Power(plain, 2) % pq;
		return cipher;
	}

	long* Decrypt(int plain, int p, int q) {
		int a[2], b[2];

		a[0] = Power(plain, (p + 1) / 4) % p;
		a[1] = -a[0];

		b[0] = Power(plain, (q + 1) / 4) % q;
		b[1] = -b[0];

		cout << " " << a[0];
		cout << " " << a[1];
		cout << " " << b[0];
		cout << " " << b[1];


		decipher[0] = ChineseRemainder(a[0], b[0], p, q);
		decipher[1] = ChineseRemainder(a[0], b[1], p, q);
		decipher[2] = ChineseRemainder(a[1], b[0], p, q);
		decipher[3] = ChineseRemainder(a[1], b[1], p, q);

		return decipher;
	}

private:
	int Power(int a, int b) {
		int res = a;
		for (int i = 1; i < b; i++)
			res *= a;
		return res;
	}

	int ChineseRemainder(int a1, int a2, int p, int q) {
		int res = 0;
		int M = p * q;

		int b1 = Inverse(q, p);
		int b2 = Inverse(p, q);
		res = (a1 * b1 * q) + (a2 * b2 * p);
		res %= M;

		while (res < 0)
			res += M;
		return res;
	}

	int Inverse(int number, int modd) {
		for (int i = 1; i < modd; i++) {
			if ((i * number) % modd == 1)
				return i;
		}
		return 1;
	}
};

#endif /* RABIN_H_ */
