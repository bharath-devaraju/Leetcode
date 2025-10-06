#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int>::iterator highIndex = max_element(height.begin(), height.end());
        int result = 0;
        int size = static_cast<int>(height.size());

        int tall = 0;
        for (vector<int>::iterator i = height.begin(); i != highIndex; i++) {
            if (tall < *i)
                tall = *i;
            else
                result += (tall - *i);
        }

        tall = 0;
        for (vector<int>::iterator i = height.begin() + size - 1; i != highIndex; i--) {
            if (tall < *i)
                tall = *i;
            else
                result += (tall - *i);
        }

        return result;
    }
};

int main() {
    Solution s1;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s1.trap(height) << endl;
    return 0;
}
