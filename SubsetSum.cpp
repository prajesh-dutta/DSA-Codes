#include <iostream>
#include <vector>

using namespace std; 


void findSubsets(int arr[], int size, int index, int targetSum, int curSum, vector<int>& subset) {
    if (curSum == targetSum) {
        cout << "Subset found: {";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "}\n";
        return;
    }

    if (index == size || curSum > targetSum) {
        return; 
    }

    
    subset.push_back(arr[index]);
    findSubsets(arr, size, index + 1, targetSum, curSum + arr[index], subset);

    
    subset.pop_back();
    findSubsets(arr, size, index + 1, targetSum, curSum, subset);
}

int main() {
    int set[] = {3, 2, 7, 1};
    int targetSum = 6;
    vector<int> subset; 
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    findSubsets(set, 4, 0, targetSum, 0, subset);

    return 0;
}
