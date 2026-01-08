// uses binary search to find the minimum element in a rotated sorted array
// time complexity : O(logN) and space complexity : O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        // *min_element(arr.begin(),arr.end());} built in function to find the minimum element in the array.
        return arr[low];
    }
};