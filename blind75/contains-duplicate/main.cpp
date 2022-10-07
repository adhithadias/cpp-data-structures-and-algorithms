#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> ns;

    for (int i : nums) {
        if (ns.find(i) != ns.end()) {
            return true;
        }
        ns.insert(i);
    }
    return false;
}

int main (int argc, char *argv[]) {

    // vector<int> nums{1,2,3,1};
    // vector<int> nums{1,2,3,4};
    vector<int> nums{1,1,1,3,3,4,3,2,4,2};

    cout << containsDuplicate(nums) << endl;

    return 0;
}