#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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

vector<int> matrixToSpiral2(vector<vector<int>>& matrix) {
    const array<array<int, 2>, 4> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    vector<int> results;
    int x = 0, y = 0, dir = 0;

    for (int i=0; i < matrix.size()*matrix[0].size(); i++) {
        results.emplace_back(matrix[x][y]);
        matrix[x][y] = 0;
        int next_x = x + dirs[dir][0], next_y = y + dirs[dir][1];

        if (next_x >= matrix.size() || next_x < 0 || next_y < 0 || next_y >= matrix.size() || matrix[next_x][next_y] == 0) {
            dir = (dir+1)%4;
            next_x = x + dirs[dir][0]; next_y = y + dirs[dir][1];
        }
        x = next_x; y = next_y;
    }
    return results;
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

    vector<int> spiralArray = matrixToSpiral2(matrix);
    printArray(spiralArray);
    return 0;
}