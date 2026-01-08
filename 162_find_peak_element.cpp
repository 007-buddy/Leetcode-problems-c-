// using binary search approach to find a peak element in an array
// time complexity: O(log n)  space complexity: O(1)
/*
the below logic uses the fact that if mid element is less than its next element
then there must be a peak element on the right side of mid element and vice versa
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }
        if (arr[0] >= arr[1])
        {
            return 0;
        }
        if (arr[n - 1] >= arr[n - 2])
        {
            return n - 1;
        }
        int low = 1;
        int high = n - 2;
        int ans = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid - 1])
            {
                high = mid - 1;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};