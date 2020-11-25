
// Sample code to perform I/O:

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll N;
	cin >> N;
	vector<string> A;
	for (ll i = 0; i < N; i++) {
        string temp;
		cin >> temp;
        int len = temp.size();
        int zeroesToadd = 5 - (len % 5);
        A.push_back((string(zeroesToadd, '0') + temp));
        // A.push_back(temp);
        // B.push_back(temp);
	}
    // for (auto x : A) {
    //     cout << x << " ";
    // }
    bool isWeightSumZero = false;
    int k = 1;
    // int maxIndexToSkip = 0;
    int maxSkipNum = 0;

    while (!isWeightSumZero) {
        ll weightSum = 0;
        // vector<int> ithChunks;
        int localMaxSkip = 0;
        for (ll i = maxSkipNum; i < N; i++) {
            // get ith chunk of all eleements
            string temp = A[i];
            int startIndex = temp.size() - (5 * (k));
            try {
                // cout << stoi(temp.substr(startIndex, 5)) << " ";
                weightSum += stoi(temp.substr(startIndex, 5));
            } catch (...) {
                // cout << 0 << " ";
                weightSum += 0;
                localMaxSkip++;
            }
        }
        if (weightSum == 0) {
            isWeightSumZero = true;
            return 0;
        }
        stable_sort(A.begin() + maxSkipNum, A.end(), [k](string a, string b) {
            int startIndexA = a.size() - (5 * (k));
            int startIndexB = b.size() - (5 * (k));
            int weightA = 0;
            int weightB = 0;
            try {
                // cout << stoi(temp.substr(startIndex, 5)) << " ";
                weightA = stoi(a.substr(startIndexA, 5));
            } catch (...) {
                // cout << 0 << " ";
                weightA = 0;
            }
            try {
                // cout << stoi(temp.substr(startIndex, 5)) << " ";
                weightB = stoi(b.substr(startIndexB, 5));
            } catch (...) {
                // cout << 0 << " ";
                weightB = 0;
            }
            return weightA < weightB;
        });
        if (localMaxSkip > maxSkipNum) {
            maxSkipNum = localMaxSkip;
        }
        for (auto x : A) {
            cout << stoll(x) << " ";
        }
        k++;
        cout << endl;
    }
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
