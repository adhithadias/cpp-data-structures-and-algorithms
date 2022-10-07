#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    int profit = 0;
    int min = prices[0];

    for (int i : prices) {
        if (i < min) {
            min = i;
        }
        else if (i - min >= 0 && profit < i - min) {
            profit = i-min;
        }
    }

    return profit;

}


int main (int argc, char *argv[]) {

    vector<int> prices{7,6,4,3,1};

    cout << maxProfit(prices) << endl;

    return 0;
}