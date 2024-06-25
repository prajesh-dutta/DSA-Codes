#include <iostream>
#include <cstring>
using namespace std;
bool isSafe(int board[][100], int n, int row, int col) {
 for (int i = 0; i < col; i++) {
 if (board[row][i] == 1) {
 return false;
 }
 }
 for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 return true;
}
bool solveNQUtil(int board[][100], int n, int col) {
 if (col >= n) {
 return true;
 }
 for (int i = 0; i < n; i++) {
 if (isSafe(board, n, i, col)) {
 board[i][col] = 1;
 if (solveNQUtil(board, n, col + 1)) {
 return true;
 }
 board[i][col] = 0;
 }
 }
 return false;
}
bool solveNQ(int n) {
 int board[100][100];
 memset(board, 0, sizeof(board));
 if (solveNQUtil(board, n, 0)) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cout << board[i][j] << " ";
 }
 cout << endl;
 }
 return true;
 } else {
 cout << "Solution does not exist" << endl;
 return false;
 }
}
int main() {
 int n;
 cin >> n;
 solveNQ(n);
 return 0;
}