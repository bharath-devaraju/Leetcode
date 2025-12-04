#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int nextBeautifulNumber(int n) {
        int len = 0;
        int temp = n;
        array<string, 6> bucket = {"1", "22", "333", "4444", "55555", "666666"};
        set<int> possibleCombs;

        while (temp) {
            temp /= 10;
            len++;
        }

        // len + 1 because if at most there can be next beautiful number 10 times greater than the
        // n.
        Generate(0, "", len + 1, bucket, possibleCombs);

        set<int> totalCombs = possibleCombs;
        for (int i : possibleCombs) permute(0, to_string(i), totalCombs);

        return *lower_bound(totalCombs.begin(), totalCombs.end(), n);
    }

   private:
    void Generate(int index, string curr, int len, array<string, 6>& bucket, set<int>& nums) {
        if (len <= 1) {
            nums.insert(stoi(curr));
            return;
        }

        for (int i = index; i < 6; i++) {
            string temp = curr + bucket[i];
            if (len - (int)bucket[i].size() >= 0) {
                Generate(i + 1, temp, len - (int)bucket[i].size(), bucket, nums);
            }
        }
    }

    void permute(int index, string s, set<int>& nums) {
        if (index >= s.size()) nums.insert(stoi(s));
        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);
            permute(index + 1, s, nums);
            swap(s[index], s[i]);
        }
    }
};

int main() {
    Solution s1;
    cout << s1.nextBeautifulNumber(300);
    return 0;
}
