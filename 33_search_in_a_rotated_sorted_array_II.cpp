/* the below function uses the tipical binary search
 approach to search an element in a rotated sorted array
 that may contain duplicates.
Works for rotated sorted arrays by first identifying the sorted
 half containing mid, then deciding which half to discard based
on where the key fits. Worst case examines all log n levels
 */
// time complexity: O(log n)
// space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[low] <= arr[mid])
            {
                if (arr[low] <= key && arr[mid] > key)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (arr[mid] < key && arr[high] >= key)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};