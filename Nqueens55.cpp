#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n=4;
int chess[4][4]={0};
bool found=false;

bool isSafe(int r, int c){
    for(int j=c; j>=0; j--){
        if((chess[r][j])==1)
            return false;
    }
    for(int i=r, j=c; i>=0 && j>=0; i--, j-- ){
        if(chess[i][j]==1)
            return false;
    }
    for(int i=r, j=c; i<n && j>=0; i++, j--){
        if(chess[i][j]==1)
            return false;
        
    }
      return true;
    }
    void print(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(chess[i][j]==1){
                    cout<<"Q";
                }
                else{
                    cout<<"-";
                }
            }
            cout<<endl;
        }

        cout<<endl;
    }

    bool solve(int c){
        if (c >= n) return true;
        for (int i = 0; i < n; i++) {
            if (isSafe(i, c)) {
                chess[i][c] = 1;
                if (solve(c + 1)) return true;
                chess[i][c] = 0;
            }
        }
        return false;
    }
 int main(){
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    bool x = solve(0);
    print();
    return 0;
 }