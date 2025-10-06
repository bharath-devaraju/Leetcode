#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunkBottles = 0;

        while (numBottles >= numExchange) {
            numBottles = numBottles - numExchange + 1;
            drunkBottles += numExchange;
            numExchange++;
        }

        drunkBottles += numBottles;
        return drunkBottles;
    }
};

int main() {
    string ss, tt;
    cin >> ss;
    cin >> tt;
    Solution s1;
    cout << s1.maxBottlesDrunk(stoi(ss), stoi(tt)) << endl;
    return 0;
}
