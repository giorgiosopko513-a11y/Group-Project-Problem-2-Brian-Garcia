#include <fstream>

#include <iostream>

#include <string>

#include <cctype>


using namespace std;



//*******BEGINNING OF PART C ********

//

//

//This is to encode the text by visiting each character and moving foward

//It adds the encrypted text back to the whole string

string encrypt(string text, int shift) {

	string encoded_text;

	for (int i = 0; i < text.size(); i++) {

		if (isalpha(text[i])) {

			char encoded;

			encoded = text[i] + shift;

			encoded_text = encoded_text + encoded;

		}

		else {

			encoded_text = encoded_text + text[i];

		}

	}

	return encoded_text;

}


//This is decrypt the text by visiting each character and moving backward

//It adds the decrypted text back to the whole string

string decrypt(string text, int shift) {

	string decoded_text;

	for (int i = 0; i < (int)text.size(); i++) {

		if (isalpha(text[i])) {

			char decoded = text[i] - shift;

			decoded_text = decoded_text + decoded;

		}

		else {

			decoded_text = decoded_text + text[i];

		}

	}

	return decoded_text;

}

//

//

//******** END OF PART C *********

//

//



//

//

//******** BEGINNING OF PART A ********

//

//


int main() {

	//Prompt user to Enter "E" to encrypt or "D" to decrypt

	//Error will prompt if user enters other letter

	char choice;

	cout << "Enter E to encrypt or D to decrypt: ";

	cin >> choice;

	string input_filename;
	string output_filename;

	if (choice == 'E') {
		input_filename = "input.txt";
		output_filename = "output.txt";

	}

	else if (choice == 'D') {
		input_filename = "output.txt";
		output_filename = "decrypted.txt";
	}

	else {

		cout << "Invalid choice \n";

		return 1;

	}

	if (choice == 'D') {															// This will test if the input file exists before decrypting, as this file contains the encrypted data
		ifstream test(input_filename);
		if (!test.is_open()) {														// If it doesnt exist, sends an error message and exits the program.
			cout << "Error: Cannot decrypt because no encrypted file exists.\n";	
			cout << "Try running the program in Encrypt mode (E) first.\n";
			return 1;
		}
	}


	//Prompt user to enter "Shift" quantity

	int shift = 0;

	cout << "Shift: ";

	cin >> shift;


	//

	//

	//********* END OF PART A *********

	//

	//


	//

	//

	//********* BEGINNING OF PART B **********

	//

	//


	//Open input.txt file

	//Print error if file doesn't open

	ifstream input_file(input_filename);

	if (input_file.fail()) {

		cout << "Error: cannot open input.txt\n";

		return 1;

	}


	//read file into 'text'

	string text, line;

	while (getline(input_file, line)) {

		text = text + line;

		text = text + '\n';

	}

	input_file.close();


	//

	//

	//*********** END OF PART B ************

	//

	//


	//

	//

	//*********** BEGINNING OF PART C **********

	//

	//


	//transform text

	string result;

	if (choice == 'E') {

		result = encrypt(text, shift);

	}

	else {

		result = decrypt(text, shift);

	}


	//

	//

	//********* END OF PART C **********

	//

	//


	//

	//

	//********* BEGINNING OF PART D ***********

	//

	//



	//Write text into output.txt file

	ofstream output_file(output_filename);

	if (output_file.fail()) {

		cout << "Error: Cannot open output.txt\n";

		return 1;

	}


	output_file << result;

	output_file.close();


	return 0;

}