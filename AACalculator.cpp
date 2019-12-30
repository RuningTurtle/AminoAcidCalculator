#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Choose which calculation to do.
int chooseOption() {
	int option = 0;
	cout << "Welcome to the Amino Acid Calculator.\n";
	cout << "Pleaes enter:\n";
	cout << "1 for calculating charge at certain pH.\n";
	cout << endl;
	cin >> option;
	cout << endl;
	return option;
}
void chargeCalculator() {
	string oneLetterChain = " ";
	double pH = 7.0;
	int charge = 0;
	cout << "Please enter amino acid one-letter sequence (all caps): ";
	cin >> oneLetterChain;
	cout << "You entered: " << oneLetterChain << endl << endl;
	cout << "Please enter pH: ";
	cin >> pH;
	cout << "You entered: " << pH << endl << endl;
	//carboxyl terminus.
	if (pH > 3.1) {
		charge -= 1;
	}
	//amino terminus.
	if (pH < 8.0) {
		charge += 1;
	}
	for (unsigned int i = 0; i < oneLetterChain.size(); i += 1) {
		//Aspartic and Glutamic acid.
		if (oneLetterChain.at(i) == 'D' || oneLetterChain.at(i) == 'E') {
			if (pH > 4.1) {
				charge -= 1;
			}
		}
		//Histidine.
		if (oneLetterChain.at(i) == 'H' && pH < 6) {
			charge += 1;
		}
		//Cysteine.
		if (oneLetterChain.at(i) == 'C' && pH > 8.3) {
			charge -= 1;
		}
		//Lysine.
		if (oneLetterChain.at(i) == 'K' && pH < 10.8) {
			charge += 1;
		}
		//Tyrosine.
		if (oneLetterChain.at(i) == 'Y' && pH > 10.9) {
			charge -= 1;
		}
		//Arginine.
		if (oneLetterChain.at(i) == 'R' && pH < 12.5) {
			charge += 1;
		}
	}
	cout << "Charge is: " << charge << endl;
}
int main() {
	int option = chooseOption();
	if (option == 1) {
		chargeCalculator();
	}
	return 0;
}
