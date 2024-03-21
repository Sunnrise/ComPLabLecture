#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main() {
    int ArraySize;
    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> ArraySize;
    // Dynamically allocate memory for the array
    int* array = new int[ArraySize];
    cout << "Enter the elements one by one with Enter until you reach ArraySize : " << endl;
    for (int i = 0; i < ArraySize; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> array[i];
    }
    bool ascending = true;
    bool descending = true;
    for (int i = 1; i < ArraySize; i++) {
        if (array[i] < array[i - 1]) {
            ascending = false;
        }
        if (array[i] > array[i - 1]) {
            descending = false;
        }
    }
    if (ascending && ArraySize != 1) {
        cout << "The array is sorted in ascending order." << endl;
    }
    else if (descending && ArraySize != 1) {
        cout << "The array is sorted in descending order." << endl;
    }
    else if (ArraySize == 1) {
		cout << "The array has only one element. I need more than once element" << endl;
	}
    else {
        cout << "The array is not sorted." << endl;
    }
    // deallocate memory when done
    delete[] array;

    return 0;
}