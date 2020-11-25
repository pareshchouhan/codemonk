
// Sample code to perform I/O:

#include <iostream>
#include <limits>
#include <sstream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int sizeOfA);
int minimumAndXorOr(int A[], int sizeOfA, map<string, int> calcMap);
int minXOR(int arr[], int n) 
{ 
    // Sort given array 
    sort(arr, arr + n); 
  
    int minXor = INT_MAX; 
    int val = 0; 
  
    // calculate min xor of consecutive pairs 
    for (int i = 0; i < n - 1; i++) { 
        val = arr[i] ^ arr[i + 1]; 
        minXor = min(minXor, val); 
    } 
  
    return minXor; 
} 
int main() {
	int N, T;
	cin >> T; // Reading input from STDIN
    map<string, int> calcMap = map<string, int>();
	for (int i = 0; i < T ; i++) {
		cin >> N;
		int A[N];
		for (int t = 0; t < N; t++) {
			cin >> A[t];
		}
		cout << minXOR(A, N) << endl;
	}


	// cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

int minimumAndXorOr(int A[], int sizeOfA, map<string, int> calcMap) {
    int minimum = numeric_limits<int>::max();
    // cout << minimum << endl;
    for (int i = 0; i < sizeOfA; i++) {
        for (int t = i + 1; t < sizeOfA; t++) {
            int potentialMinValue = 0;
            // stringstream ss;
            // ss << A[i]<<"&"<<A[t]<<"^"<<A[i]<<"|"<<A[t];
            // string key = ss.str();
            // try {
            //     int cachedMinValue = calcMap.at(key);
            //     if (cachedMinValue) {
            //         potentialMinValue = cachedMinValue;
            //     } else {
            //         potentialMinValue = ((A[i] & A[t]) ^ (A[i] | A[t]));
            //         calcMap.insert(make_pair(key, potentialMinValue));
            //     }
            // } catch (...) {
            //     potentialMinValue = ((A[i] & A[t]) ^ (A[i] | A[t]));
            //     calcMap.insert(make_pair(key, potentialMinValue));
            // }
            // cout << ((A[i] & A[t]) ^ (A[i] | A[t])) << endl;
            // cout<< "min" << potentialMinValue << endl;
            // potentialMinValue = ((A[i] & A[t]) ^ (A[i] | A[t]));
            
            potentialMinValue = A[i] ^ A[t];
            if (potentialMinValue < minimum) {
                minimum = potentialMinValue;
            }
        }
    }
    return minimum;
}

void printArray(int A[], int sizeOfA) {
	for (int i = 0; i < sizeOfA; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
