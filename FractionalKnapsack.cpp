#include <bits/stdc++.h>
using namespace std;


struct Item {
    int value;
    int weight;
};


bool compareItems(const Item &a, const Item &b) {
    double rA = (double)a.value / a.weight;
    double rB = (double)b.value / b.weight;
    return rA > rB;
}


double getMaxValue(Item items[], int n, int capacity) {
   
    sort(items, items + n, compareItems);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remaining = capacity - currentWeight;
            double fraction = ((double)remaining / items[i].weight);
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = getMaxValue(items, n, capacity);
    cout << "Maximum value we can get: " << maxValue << endl;

    return 0;
}
