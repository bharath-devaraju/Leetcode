// link -
// https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-07

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    using ll = long long;
    long long maxPower(vector<int>& stations, int r, int k) {
        int numCities = stations.size();
        vector<ll> powerOfCity(numCities + 1, 0);
        for (int c = 0; c < numCities; c++) {
            int numStations = stations[c];
            powerOfCity[max(0, c - r)] += numStations;
            powerOfCity[min(numCities, c + r + 1)] -= numStations;
        }

        const auto isPossible = [&](ll val) {
            ll sum = 0;
            ll maxChange = k;
            vector<ll> diff = powerOfCity;

            for (int i = 0; i < numCities; i++) {
                sum += diff[i];
                if (sum < val) {
                    ll augument = val - sum;
                    if (maxChange < augument) return false;

                    maxChange -= augument;
                    diff[min(numCities, i + 2 * r + 1)] -= augument;
                    sum += augument;
                }
            }
            return true;
        };

        ll left = *min_element(stations.begin(), stations.end());
        ll right = accumulate(stations.begin(), stations.end(), 0LL) + k;
        ll res = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (isPossible(mid)) {
                res = mid;
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    vector<int> stations = {1, 2, 4, 5, 0};
    int k = 2, r = 1;
    Solution s1;
    s1.maxPower(stations, r, k);
    return 0;
}
