#include <bits/stdc++.h>

using namespace std;

int numSquares(vector<int>& squares, int n) {
    int count = 0;
    while (n) {
        auto it = find_if(squares.begin(), squares.end(), [&](int i) { return i >= n; });
        if (*it == n)
            n -= *it;
        else {
            n -= *(--it);
        }
        count++;
    }

    return count;
}

int main() {
    static vector<int> squares(100);
    iota(squares.begin(), squares.end(), 1);

    transform(squares.begin(), squares.end(), squares.begin(), [](int i) { return i * i; });

    cout << numSquares(squares, 10) << endl;
    return 0;
}
