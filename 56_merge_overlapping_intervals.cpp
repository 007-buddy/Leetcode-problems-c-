// uses a result vector to store merged intervals
// time complexity : O(NlogN) and space complexity : O(N)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        result.push_back(arr[0]);
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];
            if (result.back()[1] >= start)
            {
                result.back()[1] = max(result.back()[1], end);
            }
            else
            {
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};