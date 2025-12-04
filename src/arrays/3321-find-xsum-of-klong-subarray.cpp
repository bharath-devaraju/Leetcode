#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    using ll = long long;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<ll> answer(n - k + 1, 0);
        BalanceSet bSet(x);

        for (int i = 0; i < n; i++) {
            bSet.Insert(nums[i]);
            if (i >= k) {
                bSet.Remove(nums[i - k]);
            }

            if (i >= k - 1) {
                answer[i - (k - 1)] = bSet.get();
            }
        }

        return answer;
    }

   private:
    class BalanceSet {
       private:
        const int setSize;
        ll result = 0;
        set<pair<int, int>> top, rest;
        unordered_map<int, int> occ;

        void internalInsert(const pair<int, int>& p) {
            if (top.size() < setSize || p > *(top.begin())) {
                result += (long long)(p.first) * (p.second);
                top.insert(p);
                if (top.size() > setSize) {
                    result -= (long long)(top.begin()->first) * (top.begin()->second);
                    auto exchange = *top.begin();
                    top.erase(exchange);
                    rest.insert(exchange);
                }
            }

            else {
                rest.insert(p);
            }
        }

        void internalRemove(const pair<int, int>& p) {
            if (p >= *top.begin()) {
                result -= (long long)(p.first) * p.second;
                top.erase(p);

                if (!rest.empty()) {
                    result += (long long)(rest.rbegin()->first) * (rest.rbegin()->second);
                    auto exchange = *rest.rbegin();
                    rest.erase(exchange);
                    top.insert(exchange);
                }
            }

            else {
                rest.erase(p);
            }
        }

       public:
        BalanceSet(int x) : setSize(x) {}
        void Insert(int num) {
            if (occ[num]) {
                pair<int, int> p = {occ[num], num};
                internalRemove({occ[num], num});
            }

            occ[num]++;
            internalInsert({occ[num], num});
        }

        void Remove(int num) {
            internalRemove({occ[num], num});
            occ[num]--;
            if (occ[num]) {
                internalInsert({occ[num], num});
            }
        }

        long long get() { return result; }
    };
};

int main() { return 0; }
