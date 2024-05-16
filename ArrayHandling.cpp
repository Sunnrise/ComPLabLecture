#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int findMode(int* array, int ArraySize) {
	int mode = 0;
	int maxCount = 0;
    for (int i = 0; i < ArraySize; i++) {
		int count = 0;
        for (int j = 0; j < ArraySize; j++) {
            if (array[j] == array[i]) {
				count++;
			}
		}
        if (count > maxCount) {
			maxCount = count;
			mode = array[i];
		}
	}
	return mode;
}

int main() {
    int ArraySize;
	int i = 0;
    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> ArraySize;
    // Dynamically allocate memory for the array
    int* array = new int[ArraySize];
	// Get the elements of the array from the user
    for (int i = 0; i < ArraySize; i++) {
        cout << "Enter element at index " << i << ": ";
        
        cin >> array[i];
    }
	// Call the findMode function and store the result in the variable mode
	int mode = findMode(array, ArraySize);
	// Output the mode
	cout << "The mode of the array is: " << mode << endl;
    
    // deallocate memory when done
    delete[] array;

    return 0;
}