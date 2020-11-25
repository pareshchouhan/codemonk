#include <iostream>
#include <vector> 
#include <map>

using namespace std;

void printArray(int A[], int sizeOfA);
int getIndexInArray(int, int, int);

int main() {
	int N, T;
	cin >> T; // Reading input from STDIN
	for (int i = 0; i < T ; i++) {
		cin >> N;
		int A[N*N];
		// for (int t = 0; t < N; t++) {
        //     for (int p = 0; p < N; p++) {
    	// 		cin >> A[t + p];
        //     }
		// }
		for (int k = 0; k < N * N; k++) {
			cin >> A[k];
		}

        // for every matrix A[T][P] find inversion.
        // calculate every combination of (x1, y1) and (x2, y2) such that x1 <= x2 and y1 <= y2
		int inversionCount = 0;
        for (int p = 0; p < N; p++) {
			for (int q = 0; q < N; q++) {
				// find all points, x,y where inversion is possible and check for inversion in all these places.
				for (int x = p; x < N; x++) {
					for (int y = q; y < N; y++) {
						if (A[getIndexInArray(p, q, N)] > A[getIndexInArray(x, y, N)]) {
							inversionCount++;
						}
					}
				}
			}
		}
		cout<< inversionCount << endl;
	}
}

int getIndexInArray(int i, int j, int sizeOfMatrix) {
	return (i * sizeOfMatrix) + j;
}

void printArray(int A[], int sizeOfA) {
	for (int i = 0; i < sizeOfA; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}


// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
