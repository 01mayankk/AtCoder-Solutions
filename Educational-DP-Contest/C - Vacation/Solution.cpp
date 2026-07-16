#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int numberOfDays)
    {
        // If there are no vacation days, no happiness can be earned.
        if (numberOfDays == 0)
        {
            cout << 0;
            return;
        }

        // dp[day][activity] represents the maximum happiness that can be
        // achieved up to the current day if the chosen activity on this day
        // is:
        // 0 -> Swimming
        // 1 -> Bug Catching
        // 2 -> Homework
        vector<vector<int>> dp(numberOfDays, vector<int>(3, 0));

        for (int currentDay = 0; currentDay < numberOfDays; currentDay++)
        {
            int swimmingHappiness;
            int bugCatchingHappiness;
            int homeworkHappiness;

            cin >> swimmingHappiness
                >> bugCatchingHappiness
                >> homeworkHappiness;

            // Base case:
            // On the first day, each activity contributes only its own
            // happiness value since there are no previous days.
            if (currentDay == 0)
            {
                dp[currentDay][0] = swimmingHappiness;
                dp[currentDay][1] = bugCatchingHappiness;
                dp[currentDay][2] = homeworkHappiness;

                continue;
            }

            // Choose Swimming today.
            // Yesterday's activity must be Bug Catching or Homework.
            dp[currentDay][0] =
                swimmingHappiness +
                max(dp[currentDay - 1][1], dp[currentDay - 1][2]);

            // Choose Bug Catching today.
            // Yesterday's activity must be Swimming or Homework.
            dp[currentDay][1] =
                bugCatchingHappiness +
                max(dp[currentDay - 1][0], dp[currentDay - 1][2]);

            // Choose Homework today.
            // Yesterday's activity must be Swimming or Bug Catching.
            dp[currentDay][2] =
                homeworkHappiness +
                max(dp[currentDay - 1][0], dp[currentDay - 1][1]);
        }

        // The answer is the best happiness obtainable regardless of the
        // activity chosen on the final day.
        cout << max({
            dp[numberOfDays - 1][0],
            dp[numberOfDays - 1][1],
            dp[numberOfDays - 1][2]
        });
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfDays;
    cin >> numberOfDays;

    Solution solver;
    solver.solve(numberOfDays);

    return 0;
}
