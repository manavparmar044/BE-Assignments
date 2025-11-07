#include <iostream>
#include<vector>
using namespace std;

int knapsack2D(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cout << "Enter number of items and capacity (n W): ";
    if (!(cin >> n >> W)) return 0;

    vector<int> wt(n), val(n);
    cout << "Enter weights:\n";
    for (int i = 0; i < n; ++i) cin >> wt[i];
    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i) cin >> val[i];

    int maxValue = knapsack2D(W, wt, val);

    cout << "\nMaximum value that can be obtained: " << maxValue << "\n";

    return 0;
}
