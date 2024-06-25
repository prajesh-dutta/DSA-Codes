#include<bits/stdc++.h> 

using namespace std;


int randomizedHiring(const vector<int>& candidates) {
    int bestCandidate = -1; 
    int bestRank = -1;     

    
    for (int candidate : candidates) {
        if (candidate > bestRank) { 
            bestCandidate = candidate;
            bestRank = candidate;      
        }
    }

    return bestCandidate; 
}


int main() {
    srand(time(0)); 

    vector<int> candidates = {5, 8, 2, 10, 3}; 
    int bestCandidate = randomizedHiring(candidates); 

    cout << "The best candidate hired is: " << bestCandidate << endl;

    return 0;
}
