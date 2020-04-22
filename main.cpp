#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

std::string encrypt(std::string plaintextt, std::string key, int eord);

int main() {
	std::cout << "INSTRUCTIONS:: Please do not include numbers in the inputs, they do not encrypt properly. Write them out in plain english \n if you must include them.";
	std::cout << "function used is of the form FUNCTION(plaintext,ukey,encryptordecrypt)\n. Plaintext and ukey are strings, they are separated by a comma.\n";
	std::cout << " Spaces in keys are removed in this implementation. For example, the input (attack at dawn, secret ukey) is a valid\n";
	std::cout << "Input for plaintext and ukey, respectively, and will be interpreted as (attack at dawn,secretkey) \n";
	std::cout << " To encrypt, set encryptordecrypt >0. To decrypt, set it <0.\n Press CTRL+Z to exit the program\n\n" << std::endl;
	std::string plaintext = "", ukey = "";
	int enorde = 0, ed = 0;
	std::cout << "Please input your message, ukey, and whether to encrypt or decrypt according to the instructions above\n" << std::endl;

	/*
	THINGS TO IMPLEMENT:

		12/29/19:
			Figure out how to make it so inputting an incorrect input (ie, just hitting enter, or t enter without key and eorde, resets the plaintest buffer so errors
			don't occur. For example, when the input is a enter b enter c enter  test, ab,1, just have the input be considered as test,ab,1, ignoring/clearing/overwriting
			the previous entries "a enter b enter c enter" part

	*/
	while (std::getline(std::cin, plaintext, ',') && std::getline(std::cin, ukey, ',') && std::cin >> enorde) {
		if (enorde > 0) {
			ed = 1;
		}
		else if (enorde < 0) {
			ed = -1;
		}
		else if (enorde == 0) {
			ed = 0;
		};
		switch (ed) {
		case 1:
			std::cout << "Encrypting with ukey: " << ukey << "...\n\n" << std::endl;
			break;
		case -1:
			std::cout << "Decrypting with ukey: " << ukey << "...\n\n" << std::endl;
			break;
		case 0:
			std::cout << "\nError: Entered 0 as option for encrypt or decrypt. Please try again.\n" << std::endl;
			goto new_iteration;
			break;
		};
		std::cout << encrypt(plaintext, ukey, ed) << "\n" << std::endl;

		std::cout << "\n\n Operation Complete!\n" << std::endl;

		std::cin.ignore(1, '\n');

	new_iteration:
		continue;
	};
	return 0;
}