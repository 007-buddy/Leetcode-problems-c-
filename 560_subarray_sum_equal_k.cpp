// implementingng a function to find the number of subarrays that sum to a given value k
// the below function uses an unordered_map to store the cumulative sums and their frequencies

// time complexity: O(n) and space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
long countNumberOfSubarrays(vector<int> arr, int k)
{
    long long total = 0;
    long count = 0;
    unordered_map<int, int> subnum;
    subnum[0] = 1;
    for (int i : arr)
    {
        total += i;
        if (subnum.find(total - k) != subnum.end())
        {
            count += subnum[total - k];
        }
        subnum[total]++;
    }
    return count;
}
