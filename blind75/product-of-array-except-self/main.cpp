#include <iostream>
#include <vector>

using namespace std;


vector<int> productExceptSelf(vector<int> &nums) {

    vector<int> f(nums.size());
    vector<int> b(nums.size());
    vector<int> r(nums.size());

    f[0] = nums[0];
    for (int i=1; i<nums.size(); i++) {
        f[i] = nums[i] * f[i-1];
        // cout << f[i] << " " << endl;
    }

    b[nums.size()-1] = nums[nums.size()-1];
    for (int i=nums.size()-2; i>=0; i--) {
        b[i] = b[i+1] * nums[i];
        // cout << b[i] << " " << endl;
    }

    r[0] = b[1];
    r[nums.size()-1] = f[nums.size()-2];

    for (int i=1; i< nums.size()-1; i++) {
        r[i] = f[i-1] * b[i+1];
        // cout << r[i] << " " << endl;
    }

    return r;
}

int main(int argc, char* argv[]) {

    // vector<int> nums{1,2,3,4};
    vector<int> nums{-1,1,0,-3,3};

    vector<int> r = productExceptSelf(nums);
    for (int i=0; i<r.size(); i++ ) {
        cout << r[i] << " " << endl;
    }

    return 0;
}