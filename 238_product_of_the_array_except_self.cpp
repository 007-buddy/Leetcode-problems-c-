// using two vecotors to store left and right products
//  time complexity : O(N) and space complexity : O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        vector<int> left_product(arr.size(), 1);
        vector<int> right_product(arr.size(), 1);
        int product = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            left_product[i] = product * arr[i - 1];
            product = left_product[i];
        }
        product = 1;
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            right_product[i] = product * arr[i + 1];
            product = right_product[i];
        }
        vector<int> product_array(arr.size(), 1);
        for (int i = 0; i < arr.size(); i++)
        {
            product_array[i] = left_product[i] * right_product[i];
        }
        return product_array;
    }
};