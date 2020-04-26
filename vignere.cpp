
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "C:/Users/Administrator/.nuget/packages/microsoft.gsl/0.1.2.1/build/native/include/gsl.h"
//#include <random>
std::string encrypt(std::string plaintext, std::string key, int encryptordecrypt) {
	std::string ciphertext = "";
	std::string dekey = "";
	//std::random_device rd;
	//std::uniform_int_distribution<int> distr(0, (1 << 8));

	/*
	Moves all spaces to the end of the string and returns the position of the first space (ie "1 0 1 0 0 0 1" will modify
	*the string to be "1010001     "  and then return the iterator of 7. This is the end of std::remove. key.erase then deletes everything
	*from the iterator returned by std::remove to the end of the string
	*/
	key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
	const unsigned int keylength = gsl::narrow<unsigned int>(key.length());
	for (unsigned int j = 0; j < keylength; j++) {
		dekey += gsl::narrow<char>(div(26 - (toupper(key[j]) - 65), 26).rem + 65);
	};
	for (unsigned int i = 0; i < plaintext.length(); i++) {
		if (islower(plaintext[i])) {
			plaintext[i] = gsl::narrow<char>(toupper(plaintext[i]));
		};
		if (islower(key[i])) {
			key[i] = gsl::narrow<char>(toupper(key[i]));
		};
		if (encryptordecrypt > 0) {
			if (plaintext[i] == ' ') {
				ciphertext += ' ';
			}
			else {
				int rema = div(plaintext[i] + key[i % keylength] - 65 * 2, 26).rem;
				ciphertext += gsl::narrow<char>(rema + 65);
			};
		}
		else if (encryptordecrypt < 0) {
			if (plaintext[i] == ' ') {
				ciphertext += ' ';
			}
			else {
				int rema = div(plaintext[i] + dekey[i % keylength] - 65 * 2, 26).rem;
				ciphertext += static_cast<char>(rema + 65);
			};
		};
	};
	/*for (unsigned int j = 0; j < 10; j++) {
		for (unsigned int i = 0; i < plaintext.length(); i++) {
			plaintext[i] = (distr(rd) << (j+i % (1<<8))) % (1 <<8 );
			key[i % keylength] = (distr(rd) << (j + i % (1 << 3))) % (1 << 8);
			dekey[i % keylength] = (distr(rd) << (j + i % (1 << 3))) % (1 << 8);
		};
	};
	*/
	return ciphertext;
}