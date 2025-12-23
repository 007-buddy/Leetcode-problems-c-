// 3Sum Problem: Find all unique triplets in the array which gives the sum of zero
// using two-pointer technique and set to avoid duplicates
// time complexity : O(N^2) and space complexity : O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());  // Missing sort!
        set<vector<int>> s; 
        
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0) {
                    s.insert({arr[i], arr[j], arr[k]});  // Store VALUES, not indices
                    j++;
                    k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        
        return vector<vector<int>>(s.begin(), s.end());
    }
};