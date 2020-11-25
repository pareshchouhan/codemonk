#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char ** argv) {
    string a;
    int k;
    cin >> a >> k;
    vector<string> suffices = vector<string>();
    for (int i = 0; i < a.length(); i++) {
        suffices.push_back(a.substr(i, a.length()));
    }
    sort(suffices.begin(), suffices.end());
    // for (vector<string>::iterator it=suffices.begin(); it!=suffices.end(); ++it)
        // cout << ' ' << *it;
    cout << suffices[k - 1];
    
}