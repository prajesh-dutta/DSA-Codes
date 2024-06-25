#include <bits/stdc++.h>
using namespace std;


int findMinOperations(int dims[], int numMatrices) {
    int costs[numMatrices][numMatrices];

   
    for (int i = 0; i < numMatrices; i++) {
        costs[i][i] = 0;
    }

   
    for (int len = 2; len <= numMatrices; len++) { 
        for (int i = 0; i <= numMatrices - len; i++) {
            int j = i + len - 1;
            costs[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int tempCost = costs[i][k] + costs[k + 1][j] +
                               dims[i] * dims[k + 1] * dims[j + 1];

                costs[i][j] = min(costs[i][j], tempCost);
            }
        }
    }

    return costs[0][numMatrices - 1];
}

int main() {
    int dimensions[] = {10, 20, 50, 1, 100}; 
    int numMatrices = sizeof(dimensions) / sizeof(dimensions[0]) - 1;

    int minOps = findMinOperations(dimensions, numMatrices);
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    cout << "Minimum multiplications needed: " << minOps << endl;

    return 0;
}
