/*
 *  hillcipher.h / Hill Cipher
 *  Created on: 14-Oct-2016
 *      Author: Gourav Siddhad
 */

#ifndef HILLCIPHER_H_
#define HILLCIPHER_H_

#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cctype"
#include "cstdio"

#define MAX 51
using namespace std;

class Hillcipher {
	char *cipher, *decipher;
	int size;
public:
	Hillcipher() {
		cipher = new char[MAX];
		decipher = new char[MAX];
		size = 0;
	}

	char* Encrypt(char* plain, int key, int **kmatrix) {
		size = key;
		int svector[key];

		int *final = new int[strlen(plain + size)];
		unsigned int fcounter = 0;

		bool flag = true;
		while (fcounter < strlen(plain)) {
			for (int i = 0; i < key; i++) {
				flag = true;
				if (plain[fcounter + i] == '\0')
					flag = false;

				if (flag) {
					if (isupper(plain[fcounter + i]))
						svector[i] = plain[fcounter + i] - 65;
					else if (islower(plain[fcounter + i]))
						svector[i] = plain[fcounter + i] - 97;
					else
						svector[i] = plain[fcounter + i];
				} else {
					svector[i] = 23;
				}
			}

			int *res;
			res = Matrixmultiply(kmatrix, svector);

			for (int i = 0; i < size; i++) {
				while (res[i] < 0)
					res[i] += 26;
				final[fcounter] = res[i] % 26;
				fcounter++;
			}
		}

		unsigned int i = 0;
		for (i = 0; i < fcounter; i++)
			cipher[i] = final[i] + 65;

		if (i < MAX)
			cipher[i] = '\0';
		else
			cipher[MAX - 1] = '\0';
		return cipher;
	}

	char* Decrypt(char* plain, int key, int **kmatrix) {
		int det = Matrixdeterminant(kmatrix);
		if (gcd(det, 26) != 1) {
			cout << " Choose a different Matrix" << endl;
//			exit(0);
		}

		int inv = Inverse(det);
		cout << endl << " Inv(Det) : " << inv;
		int** invmatrix = Matrixadjoint(inv, kmatrix);

		cout << endl << " Inverse Matrix : " << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				invmatrix[i][j] = (invmatrix[i][j] * inv) % 26;
				if (invmatrix[i][j] < 0)
					invmatrix[i][j] += 26;
				cout << " " << invmatrix[i][j];
			}
			cout << endl;
		}

		int svector[key];

		int *final = new int[strlen(plain + size)];
		unsigned int fcounter = 0;

		bool flag = true;
		while (fcounter < strlen(plain)) {
			for (int i = 0; i < key; i++) {
				flag = true;
				if (plain[fcounter + i] == '\0')
					flag = false;

				if (flag) {
					if (isupper(plain[fcounter + i]))
						svector[i] = plain[fcounter + i] - 65;
					else
						svector[i] = plain[fcounter + i];
				} else {
					svector[i] = 23;
				}
			}

			int *res;
			res = Matrixmultiply(invmatrix, svector);

			for (int i = 0; i < size; i++) {
				while (res[i] < 0)
					res[i] += 26;
				final[fcounter] = res[i] % 26;
				fcounter++;
			}
		}

		unsigned int i = 0;
		for (i = 0; i < fcounter; i++)
			decipher[i] = final[i] + 65;

		if (i < MAX)
			decipher[i] = '\0';
		else
			decipher[MAX - 1] = '\0';
		return decipher;
	}

private:
	int* Matrixmultiply(int **kmatrix, int svector[]) {
		int *result;
		result = new int[size];

		for (int i = 0; i < size; i++)
			result[i] = 0;

		for (int j = 0; j < size; j++)
		for (int k = 0; k < size; k++)
				result[j] = result[j] + (kmatrix[j][k] * svector[k]);

		return result;
	}

	int Matrixdeterminant(int **kmatrix) {
		int result = 0;
		if (size == 2) {
			result = kmatrix[0][0] * kmatrix[1][1]
					- kmatrix[0][1] * kmatrix[1][0];
		} else if (size == 3) {
			result += kmatrix[0][0]
					* (kmatrix[1][1] * kmatrix[2][2]
							- kmatrix[1][2] * kmatrix[2][1]);
			result -= kmatrix[0][1]
					* (kmatrix[1][0] * kmatrix[2][2]
							- kmatrix[1][2] * kmatrix[2][0]);
			result += kmatrix[0][2]
					* (kmatrix[1][0] * kmatrix[2][1]
							- kmatrix[1][1] * kmatrix[2][0]);
		}

		result %= 26;
		while (result < 0)
			result += 26;

		return result;
	}

	int Inverse(int number) {

		for (int i = 1; i < 26; i++) {
			if ((i * number) % 26 == 1)
				return i;
		}
		return 1;
	}

	int** Matrixadjoint(int inv, int **mat) {
		int **res = new int*[size];
		for (int i = 0; i < size; i++)
			res[i] = new int[size];

		if (size == 2) {
			res[0][0] = mat[1][1];
			res[0][1] = -mat[0][1];
			res[1][0] = -mat[1][0];
			res[1][1] = mat[0][0];
		} else if (size == 3) {
			res[0][0] = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
			res[0][1] = -(mat[0][1] * mat[2][2] - mat[2][1] * mat[0][2]);
			res[0][2] = mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1];
			res[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
			res[1][1] = mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0];
			res[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
			res[2][0] = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];
			res[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);
			res[2][2] = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				while (res[i][j] < 0)
					res[i][j] += 26;
				res[i][j] = res[i][j] % 26;
			}

		return res;
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
};

#endif /* HILLCIPHER_H_ */
