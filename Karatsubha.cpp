#include <bits/stdc++.h>
using namespace std;


int getLength(long long num) {
    int digits = 0;
    while (num > 0) {
        num /= 10;
        digits++;
    }
    return digits;
}


long long getSplitVal(long long num, int splitPosition) {
    return num / pow(10, splitPosition);
}

long long karatsuba(long long x, long long y) {
    
    if (x < 10 || y < 10) {
        return x * y;
    }

    int len = max(getLength(x), getLength(y));
    int mid = len / 2; 

    
    long long a = getSplitVal(x, mid);
    long long b = x % (long long)pow(10, mid);
    long long c = getSplitVal(y, mid);
    long long d = y % (long long)pow(10, mid);

    
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

     
    return ac * pow(10, 2 * mid) + ad_plus_bc * pow(10, mid) + bd;
}

int main() {
    long long num1 = 1234;
    long long num2 = 5678;
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    long long result = karatsuba(num1, num2);
    cout << "Product of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
