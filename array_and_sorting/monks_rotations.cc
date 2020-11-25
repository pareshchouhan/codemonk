
// Sample code to perform I/O:

#include <iostream>

using namespace std;

void rotate(int A[], int rotations, int sizeOfA);
void printArray(int A[], int sizeOfA);
void prependArray(int A[], int B[], int sizeOfA, int sizeOfB);
int main() {
	int N, K, T;
	cin >> T; // Reading input from STDIN
	for (int i = 0; i < T ; i++) {
		cin >> N >> K;
		int A[N];
		for (int t = 0; t < N; t++) {
			cin >> A[t];
		}
		// read array A
		rotate(A, K, N);
		// for (int t = 0; t < N; t++) {
		// 	cout << A[t] << " ";
		// }
		// cout << endl;
	}


	// cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

void printArray(int A[], int sizeOfA) {
	for (int i = 0; i < sizeOfA; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void rotate(int A[], int rotations, int sizeOfA) {
	int tempArr[rotations % sizeOfA];
    // cout << rotations % sizeOfA;
	for (int i = 0; i < rotations % sizeOfA; i++) {
		tempArr[i] = A[sizeOfA - (rotations % sizeOfA) + i];
	}
    // printArray(tempArr, rotations % sizeOfA);
    prependArray(A, tempArr, sizeOfA, rotations % sizeOfA);
	// for (int rot = 0; rot < rotations; rot++) {
	// 	int temp = A[sizeOfA - 1];
	// 	for (int i = sizeOfA - 1; i > 0; i--) {
	// 		A[i] = A[i - 1];
	// 	}
	// 	A[0] = temp;
	// }
}

void prependArray(int A[], int B[], int sizeOfA, int sizeOfB) {
    int temp[sizeOfA];
    for (int i = 0; i < sizeOfB; i++) {
        temp[i] = B[i];
    }
    for (int i = 0; i < sizeOfA - sizeOfB; i++) {
        temp[sizeOfB + i] = A[i];
    }
    printArray(temp, sizeOfA);
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
