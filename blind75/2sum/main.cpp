#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> visitedNums;

    for (int i=0; i<nums.size(); i++) {
        auto p = visitedNums.find(target-nums[i]);
        if (p != visitedNums.end()) {
            return {p->second, i};
        }
        visitedNums[nums[i]] = i;
    }

    return {-1, -1};
}


int main(int argc, char *args[]) {
    vector<int> nums {3, 1, 2, 0};
    int target = 3;

    vector<int> result = twoSum(nums, target);
    cout << result[0] << ", " << result[1] << endl;

    return 0;
}