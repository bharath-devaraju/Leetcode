#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end(), greater<int>());

        const auto binSearch = [&](int spell) -> int {
            int left = 0;
            int right = potions.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                ll prod = static_cast<ll>(spell) * static_cast<ll>(potions[mid]);

                if (prod >= success)
                    left = mid + 1;

                else
                    right = mid - 1;
            }

            return left;
        };

        for (size_t j = 0; j < spells.size(); j++) {
            spells[i] = binSearch(spells[i]);
        }

        return spells;
    }
};

int main() { return 0; }
