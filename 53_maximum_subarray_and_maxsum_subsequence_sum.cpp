// finding maximum subarray sum and maximum subsequence sum
// time complexity : O(N) and space complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubarray(vector<int> arr)
{
    int max_subarray_sum = 0;
    int max_subsequence_sum = 0;
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        max_subarray_sum = max(max_subarray_sum, sum);
        if (arr[i] > 0)
        {
            max_subsequence_sum += arr[i];
        }
    }
    if (max_subarray_sum == 0)
        max_subarray_sum = *max_element(arr.begin(), arr.end());
    if (max_subsequence_sum == 0)
        max_subsequence_sum = *max_element(arr.begin(), arr.end());
    return {max_subarray_sum, max_subsequence_sum};
}
