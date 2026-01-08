/*uses two-pointer technique to move all zeroes in the array
 to the end while maintaining the order of non-zero elements
 */

// uses two loops first will move all the non-zero elements to the front and the last one will fill the rest of the array with zeroes
// time complexity: O(n) and space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

void pushZerosToEnd(vector<int> &arr)
{
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    while (i < arr.size())
    {
        arr[i] = 0;
        i++;
    }
}