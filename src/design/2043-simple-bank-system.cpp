#include <bits/stdc++.h>

using namespace std;

class Bank {
    using ll = long long;
    int totalAccounts = 0;
    unordered_map<ll, ll> AccountBalance;
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++) {
            AccountBalance[i + 1] = balance[i];
            totalAccounts++;
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 > totalAccounts || account2 > totalAccounts ||
            AccountBalance[account1] < money)
            return false;

        AccountBalance[account1] -= money;
        AccountBalance[account2] += money;

        return true;
    }

    bool deposit(int account, long long money) {
        if (account > totalAccounts) return false;

        AccountBalance[account] += money;
    }

    bool withdraw(int account, long long money) {
        if (account > totalAccounts) return false;

        AccountBalance[account] -= money;
        return true;
    }
};

int main() { return 0; }
