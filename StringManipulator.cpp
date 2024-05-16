//152120201054_Hw1.cpp-Alperen Güneþ
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

 class StringManipulator {
 public:
    static void capitalizeFirstLetters(string& str) {
        // Function to convert first letters of words to uppercase
		bool newWord = true;
        for (char& c : str) {
            if (newWord && islower(c)) {
				c = toupper(c);
				newWord = false;
			}
            else if (isspace(c)) {
				newWord = true;
			}
		}
	}
    static void duplicateUppercase(string& str) {
// Function to duplicate uppercase letters in the string
        string result;
        for (char c : str) {
            if (isupper(c)) {
                result += c;
            }
            result += c;
        }
        str = result;
    }
    static void removeExtraSpaces(string& str) {
         // Function to remove extra spaces
        string result;
        bool prevSpace = false;
        for (char c : str) {
            if (isspace(c)) {
                if (!prevSpace) {
                    result += c;
                }
                prevSpace = true;
            }
            else {
                result += c;
                prevSpace = false;
            }
        }
        str = result;
    }
    static int countVowels(const string& str) {
		// Function to count vowels
		int count = 0;
        for (char c : str) {
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
				count++;
			}
		}
		return count;
	}
    static int countWords(const string& str) {
		// Function to count words
		int count = 0;
		bool inWord = false;
        for (char c : str) {
            if (isspace(c)) {
				inWord = false;
			}
            else if (!inWord) {
				count++;
				inWord = true;
			}
		}
		return count;
	}
};
int main() {
    string input;

    // Step 1: Convert the first letters of the words to uppercase
    cout << "Enter the string: ";
    getline(cin, input);
    StringManipulator::capitalizeFirstLetters(input);
    cout << "1) " << input << endl;

    // Step 2: Duplicate uppercase letters in the string
    StringManipulator::duplicateUppercase(input);
    cout << "2) " << input << endl;

    // Step 3: Remove extra spaces
    StringManipulator::removeExtraSpaces(input);
    cout << "3) " << input << endl;

    // Step 4: Count vowels
    int vowels = StringManipulator::countVowels(input);
    cout << "4) Total number of vowels: " << vowels << endl;

    // Step 5: Count words
    int words = StringManipulator::countWords(input);
    cout << "5-) Total number of words: " << words << endl;

    return 0;
}