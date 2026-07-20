#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long knapsack(int N, int W, const vector<pair<int, int>> &items)
    {
        // dp[capacity] stores the maximum value achievable
        // using a knapsack of the given capacity.
        vector<long long> dp(W + 1, 0);

        // Process every item exactly once.
        for (int i = 0; i < N; i++)
        {
            int weight = items[i].first;
            int value = items[i].second;

            // Traverse backwards so that the current item
            // is not selected more than once.
            for (int capacity = W; capacity >= weight; capacity--)
            {
                dp[capacity] = max(dp[capacity],
                                   dp[capacity - weight] + value);
            }
        }

        return dp[W];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<pair<int, int>> items(N);

    for (int i = 0; i < N; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    Solution obj;
    cout << obj.knapsack(N, W, items) << '\n';

    return 0;
}
