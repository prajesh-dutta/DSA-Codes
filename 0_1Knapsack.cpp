#include <bits/stdc++.h>
using namespace std;


struct Item {
    int value; 
    int weight;
};


int findMaxValue(Item items[], int numItems, int capacity) {
    int K[numItems + 1][capacity + 1];

 
    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                K[i][w] = max(items[i - 1].value + K[i - 1][w - items[i - 1].weight],
                              K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];  
            }
        }
    }

    return K[numItems][capacity];
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int numItems = sizeof(items) / sizeof(items[0]);

    int maxVal = findMaxValue(items, numItems, capacity);
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    cout << "Maximum value we can get: " << maxVal << endl;

    return 0;
}
