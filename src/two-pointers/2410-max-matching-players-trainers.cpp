#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int numTrainers = trainers.size();
        int numPlayers = players.size();
        int maxMatchings = 1;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for (int i = 0, j = 0; j < numTrainers && i < numPlayers;) {
            if (players[i] >= trainers[j])
                j++;
            else {
                i++;
                maxMatchings++;
            }
        }
        return maxMatchings;
    }
};

int main() { return 0; }
