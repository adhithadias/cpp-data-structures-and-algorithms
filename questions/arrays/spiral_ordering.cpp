#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> matrixToSpiral(vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    for (int i=0; i < n/2 + 1; i++) {
        if (i == n-1-i) {
            result.emplace_back(matrix[i][i]);
            break;
        }
        for (int j = i; j < n-1-i; j++) {
            result.emplace_back(matrix[i][j]);
        }
        for (int j = i; j < n-1-i; j++) {
            result.emplace_back(matrix[j][n-1-i]);
        }
        for (int j = n-1-i; j > i; j--) {
            result.emplace_back(matrix[n-1-i][j]);
        }
        for (int j = n-1-i; j > i; j--) {
            result.emplace_back(matrix[j][i]);
        }
    }
    return result;
}

void printArray(vector<int>& arr) {
    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // vector< vector<int>> matrix = { 
    //     {1, 2, 3}, 
    //     {4, 5, 6}, 
    //     {7, 8, 9}
    // };
    vector< vector<int>> matrix = { 
        {1, 2}, 
        {4, 5}
    };

    vector<int> spiralArray = matrixToSpiral(matrix);
    printArray(spiralArray);
    return 0;
}