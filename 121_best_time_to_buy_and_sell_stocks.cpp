// simple way to solve the problem in O(n) time and O(1) space complexity
// this approach keeps track of the minimum price seen so far and calculates
// the maximum profit that can be achieved by selling on each day.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};

// Here's an alternative O(n) solution using a prefix minimum array
// approach, which explicitly tracks the minimum price up to each
// index before computing profit.
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prefixMin(n);
        prefixMin[0] = prices[0];

        // Build prefix minimum array
        for (int i = 1; i < n; i++)
        {
            prefixMin[i] = min(prefixMin[i - 1], prices[i]);
        }

        // Find maximum profit using prefix mins
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            profit = max(profit, prices[i] - prefixMin[i]);
        }
        return profit;
    }
};