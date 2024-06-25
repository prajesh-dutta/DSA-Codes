#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> computeLPSArray(const string& pattern) {
    int length = 0; 
    int i = 1;
    vector<int> lps(pattern.size(), 0);

  
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


void KMPSearch(const string& text, const string& pattern) {
    vector<int> lps = computeLPSArray(pattern);
    int i = 0; 
    int j = 0; 

    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
