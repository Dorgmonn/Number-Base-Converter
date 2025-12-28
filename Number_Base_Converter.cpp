#include <iostream>
#include <windows.h>
using namespace std;
int main() {

	string num, cloneNum, FResult, SCIN = "1", banList = "qwrtyuiopsghjklzxvnmQWRTYUIOPSGHJKLZXVNM`~!@#$%^&*()_-=+;:'/?.>,<";
	int syst, checker, convert, filler;
	char CCIN;
	long long resultIn10, cloneResultIn10;
	bool negative, badChar;
	do {
		do {
			resultIn10 = 0; //the final result, only in base 10.
			FResult = ""; //saving the final result that the user needs.
			negative = false; //needed for correct display of negative numbers.
			badChar = false; // needed to check for a match with the banlist.
			checker = -1; //Validates the characters in the string entered by the user. The value -1 is assigned to detect errors or inconsistencies.
			// A banlist is needed to check a string for invalid characters.
			if (SCIN == "1") {
				do {
					cout << "Enter the number you want to convert: ";
					cin >> num;
					cout << "Is number <" << num << "> entered correctly (Y - yes, N - no): ";
					cin >> CCIN;
				} while (CCIN != 'Y' && CCIN != 'y');
				cloneNum = num; //creating a clone of a number for future return.
			}

			if (num[0] == '-') { //If there is a minus sign at the beginning of a line,
				num.erase(0, 1); //it is removed in this part to display a negative result at the end.
				negative = true;
			}
			if (num.empty())
				checker = -1;

			do {
				if (SCIN == "2")
					cout << "Write in what system number " << num << " is written(available systems from 2 to 16) : ";
				else
					cout << "Write in what system this number is written (available systems from 2 to 16): ";

				cin >> syst;
				if (syst < 2 || syst > 16)
					cout << "! Error : such a number system is not provided or does not exist, try again." << endl;
			} while (syst < 2 || syst > 16);

			//! START CHECKING THE CORRECTNESS OF THE NUMBER ENTRY !
			//   This block checks:
            // - invalid characters.
            // - digits out of range for the selected base.
 

			for (int i = 0; i < num.length(); i++) {

				for (int j = 0; j < banList.length(); j++) {
					if (num[i] == banList[j]) { //check if each element of the string matches each element of the banlist.
						cout << "! Error : invalid or unexpected character in number, please try again." << endl;
						badChar = true;
						break;
					}
				}

				checker = -1;
				if (badChar == true) //If there are invalid elements in the line,
					break;           //then the song ends at this point and the input is returned to the very beginning.

				switch (num[i]) { //checking whether the entered number can be recorded in the system submitted by the user.

				case 'A':
				case 'a':
					checker = 10;
					break;

				case 'B':
				case 'b':
					checker = 11;
					break;

				case 'C':
				case 'c':
					checker = 12;
					break;

				case 'D':
				case 'd':
					checker = 13;
					break;

				case 'E':
				case 'e':
					checker = 14;
					break;

				case 'F':
				case 'f':
					checker = 15;
					break;

				case '0': checker = 0; break;
				case '1': checker = 1; break;
				case '2': checker = 2; break;
				case '3': checker = 3; break;
				case '4': checker = 4; break;
				case '5': checker = 5; break;
				case '6': checker = 6; break;
				case '7': checker = 7; break;
				case '8': checker = 8; break;
				case '9': checker = 9; break;
				}
				if (checker >= syst) {
					cout << "! Error : This number cannot be written in this number system, please try again." << endl;
					checker = -1;
					break;
				}
			}
			if (checker == -1) { //If the check fails at least at one stage, the system returns to entering the number.
				cout << "Press Enter to return...";
				cin.ignore();
				cin.get();
				system("cls");
			}
		} while (checker == -1);

		//! END OF INPUT VALIDITY CHECK AND START OF THE ALGORITHM !

		do {
			cout << "Write in which system this number needs to be converted (available systems from 2 to 16): ";
			cin >> convert;
			if (convert < 2 || convert > 16)
				cout << "! Error : such a number system is not provided or does not exist, try again.";
		} while (convert < 2 || convert > 16);

		if (syst != 10) { //if the number is not written in the decimal system.
			for (int i = 0; i < num.length(); i++) { //converting the entered number to decimal.
				checker = -1;
				switch (num[i]) {

				case 'A':
				case 'a':
					checker = 10;
					break;

				case 'B':
				case 'b':
					checker = 11;
					break;

				case 'C':
				case 'c':
					checker = 12;
					break;

				case 'D':
				case 'd':
					checker = 13;
					break;

				case 'E':
				case 'e':
					checker = 14;
					break;

				case 'F':
				case 'f':
					checker = 15;
					break;
				case '0': checker = 0; break;
				case '1': checker = 1; break;
				case '2': checker = 2; break;
				case '3': checker = 3; break;
				case '4': checker = 4; break;
				case '5': checker = 5; break;
				case '6': checker = 6; break;
				case '7': checker = 7; break;
				case '8': checker = 8; break;
				case '9': checker = 9; break;

				}
				resultIn10 = resultIn10 * syst + checker;
			}
		}
		else                                        //Here we know for sure that the number is written in the decimal system,
			for (int i = 0; i < num.length(); i++)  //so here the conversion from a string to a variable occurs.
				resultIn10 = resultIn10 * 10 + (num[i] - '0');

		cloneResultIn10 = resultIn10; //creating a copy of the result in decimal.

		if (resultIn10 == 0) {
			FResult = "0";
		}
		else {
			while (resultIn10 > 0) { //converting a decimal number to the number system required by the user.
				filler = resultIn10 % convert;
				switch (filler) {

				case 0: FResult += '0'; break;
				case 1: FResult += '1'; break;
				case 2: FResult += '2'; break;
				case 3: FResult += '3'; break;
				case 4: FResult += '4'; break;
				case 5: FResult += '5'; break;
				case 6: FResult += '6'; break;
				case 7: FResult += '7'; break;
				case 8: FResult += '8'; break;
				case 9: FResult += '9'; break;
				case 10: FResult += 'A'; break;
				case 11: FResult += 'B'; break;
				case 12: FResult += 'C'; break;
				case 13: FResult += 'D'; break;
				case 14: FResult += 'E'; break;
				case 15: FResult += 'F'; break;

				}
				resultIn10 = resultIn10 / convert;
			}
		}  //At the end of this transformation we have a number in the desired system, 
		   //but it is written backwards, so after the cycle it needs to be reversed.
		for (int i = 0; i < FResult.length() / 2; i++)
			swap(FResult[i], FResult[FResult.length() - 1 - i]); //turning a number backwards so it is written correctly.

		if (negative == true) {      //If at the beginning the algorithm determined that the number is negative,
			FResult = '-' + FResult; //then now a minus sign must be added to all displayed results.
			cloneResultIn10 = -cloneResultIn10;
			num = '-' + num;
		}

		cout << endl << "Number <" << num << "> in base (" << convert << ") looks like this: [ " << FResult << " ]" << endl; //output result.
		if (syst != 10) {
			cout << "Also here is this number in base 10: [ " << cloneResultIn10 << " ]" << endl;
		}   //This line is only displayed if the original number was not in the decimal system.

		cout << endl << "Do you want to continue the conversion with the old number or enter a new one?" << endl << "- 1. New" << endl << "- 2. Old" << endl;
		do {
			cout << "-Choose an option: ";
			cin >> SCIN;
			if (SCIN != "1" && SCIN != "2")
				cout << "! Error : invalid option." << endl;
		} while (SCIN != "1" && SCIN != "2");

		if (SCIN == "2") {
			num = cloneNum;
		}
		cout << "Press Enter to continue...";
		cin.ignore();
		cin.get();
		system("cls");

	} while (SCIN == "1" || SCIN == "2");
}