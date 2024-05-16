#include <iostream>
#define SIZE 5 // Change the value of SIZE as needed, but keep it less than 10

// Function to print a matrix of size N x N, given a pointer to the first element of the matrix
void printMatrix(int* matrix, int N, int index = 0) {
    // Check if index is within bounds
    if (index >= N * N) return;

    // Print the current element
    std::cout << *(matrix + index) << " ";

    // Check if the next element will be in a new row
    if ((index + 1) % N == 0) {
        std::cout << std::endl;
    }

    // Print the rest of the matrix recursively
    printMatrix(matrix, N, index + 1);
}
int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int* p, * q;

    // Task 1: Assign 0 to all elements of matrix A and print the output
    p = &A[0][0];
    std::fill(p, p + SIZE * SIZE, 0);
    std::cout << "Matrix A with all elements initialized to 0:" << std::endl;
    printMatrix(p, SIZE);
    std::cout << std::endl;

    // Task 2: Update the elements on the edges of matrix A to 1 and print the output
    for (int i = 0; i < SIZE; i++) {
        *(p + i) = 1; // Top row
        *(p + i + SIZE * (SIZE - 1)) = 1; // Bottom row
        *(p + i * SIZE) = 1; // Left column
        *(p + (i + 1) * SIZE - 1) = 1; // Right column
    }
    std::cout << "Matrix A with edges initialized to 1:" << std::endl;
    printMatrix(p, SIZE);
    std::cout << std::endl;

    // Task 3: Assign twice the elements in matrix A to matrix B and print the output
    q = &B[0][0];
    for (int i = 0; i < SIZE * SIZE; i++) {
        *(q + i) = *(p + i) * 2;
    }
    std::cout << "Matrix B with elements twice those of matrix A:" << std::endl;
    printMatrix(q, SIZE);

    return 0;
}
