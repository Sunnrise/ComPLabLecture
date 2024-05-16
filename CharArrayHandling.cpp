//152120201054_Quiz1.cpp-Alperen Güneþ
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main() {
    const int SIZE = 100;                       // Maximum size of the string
    char str[SIZE];                             // String to be entered by the user

    cout << "Enter the string: ";               // Prompt the user to enter the string
    
    cin >> str;                                 // Read the string from the user

                                                // Part 1: Replace lowercase letters with uppercase letters with while loop
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
    cout <<"Output 1(UpperCase): " << str << endl;// Display the string after replacing lowercase letters with uppercase letters
   

                                                // Part 2: Remove numeric characters (0 to 9) with for loop
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';                              // Terminate the string
    cout <<"Output 2(WithoutNumbers): " << str; // Display the string after removing numeric characters

    return 0;
}