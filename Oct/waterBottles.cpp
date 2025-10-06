#include <bits/stdc++.h>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int result = numBottles;

    while (numBottles >= numExchange) {
        result += (numBottles / numExchange);
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }

    return result;
}

int main() {
    cout << numWaterBottles(9, 3) << endl;
    return 0;
}
