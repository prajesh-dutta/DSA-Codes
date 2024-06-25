#include <bits/stdc++.h>
using namespace std;


struct Result {
    int leftSum;
    int rightSum;
    int totalSum;  
};


Result findMaxSum(int arr[], int low, int high) {
    if (low == high) { 
        
        return {arr[low], arr[low], arr[low]};
    }

    int mid = (low + high) / 2;

    
    Result leftResult = findMaxSum(arr, low, mid);
    Result rightResult = findMaxSum(arr, mid + 1, high);

    
    int leftCrossSum = 0, currentSum = 0;
    for (int i = mid; i >= low; i--) {
        currentSum += arr[i];
        leftCrossSum = max(leftCrossSum, currentSum);
    }

    int rightCrossSum = 0, currentSum2 = 0; 
    for (int i = mid + 1; i <= high; i++) {
        currentSum2 += arr[i];
        rightCrossSum = max(rightCrossSum, currentSum2);
    }

   
    Result result;
    result.leftSum = max(leftResult.leftSum, leftResult.totalSum + leftCrossSum);
    result.rightSum = max(rightResult.rightSum, rightResult.totalSum + rightCrossSum);
    result.totalSum = max({leftResult.totalSum, rightResult.totalSum, leftCrossSum + rightCrossSum});

    return result;
}

int main() {
    int myArray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    Result maxSub = findMaxSum(myArray, 0, size - 1);
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    cout << "Maximum subarray sum: " << maxSub.totalSum << endl;

    return 0;
}
