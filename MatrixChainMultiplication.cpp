#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    int l[n]={13,5,89,3,34};
    int c[n][n]={0};

    for(int diff=2; diff<=n; diff++){
            for(int i=0; i<n-diff+1; i++){
                int j=i+diff-1;
                int min=INT_MAX;
                for(int k=i; k<=j-1; k++){
                    int q=c[i][k]+c[k+1][j]+(l[i]*l[k+1]*l[j+1]);
                    if(q<min){
                        min=q;
                    }
                    c[i][j]=min;
                }
            }
        cout<<c[0][n-1]<<endl;
        return 0;
    }
}
