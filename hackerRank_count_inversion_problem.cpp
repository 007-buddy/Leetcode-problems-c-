/* this method uses modified merge sort algorithm to count inversions in an array
 Time complexity : O(nlogn)
 Space complexity: O(n)
 an inversion is a pair (i,j) such that i<j and arr[i]>arr[j]
*/

/* Also this method alter the original array to a sorted array that was to recommended to alte the input
therefore you should create the copy of the oroginal array to keep the original array intact.
*/
#include <bits/stdc++.h>
using namespace std;

long merge(vector<int> &arr, int low, int mid, int high)
{
    // Create temp arrays
    long count = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    // Merge two sorted halves
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
        {
            // just a shuttle one line change in the merge sort algorithm to count inversions
            count += mid - left + 1; // Count whenever an element from right half is smaller than left half

            temp.push_back(arr[right++]);
        }
    }

    // Copy remaining elements from left half
    while (left <= mid)
        temp.push_back(arr[left++]);

    // Copy remaining elements from right half
    while (right <= high)
        temp.push_back(arr[right++]);

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return count;
}

// Recursive merge sort function
long mergeSort(vector<int> &arr, int low, int high)
{
    long count = 0;
    if (low >= high)
        return count;

    // Find the middle index
    int mid = (low + high) / 2;

    // Recursively sort left half
    count += mergeSort(arr, low, mid);

    // Recursively sort right half
    count += mergeSort(arr, mid + 1, high);

    // Merge the two sorted halves
    count += merge(arr, low, mid, high);

    return count;
}

long countInversions(vector<int> arr)
{
    long count = 0;
    int n = arr.size();
    count = mergeSort(arr, 0, n - 1);
    return count;
}
