#include <bits/stdc++.h>
using namespace std;


int findLCSLength(const string &str1, const string &str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    
    int LCS[len1 + 1][len2 + 1];

    
    for (int i = 0; i <= len1; i++) LCS[i][0] = 0;
    for (int j = 0; j <= len2; j++) LCS[0][j] = 0;

    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1; 
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    return LCS[len1][len2];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int result = findLCSLength(X, Y);
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    cout << "Length of the Longest Common Subsequence: " << result << endl;

    return 0;
}
