#include<bits/stdc++.h>
using namespace std;
// missinng number from 1 to n( time complexity:O(nlogn)  space complexity)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
 sort(nums.begin(),nums.end());
 int n=nums.size();
       for(int i=0;i<n;i++){
        if(i!=nums[i])
            return i;
       } 
       return n;
    }
};
// optimal approach using sum formula (time complexity: O(n), space complexity: O(1)) 
int missingNumber(vector<int>&a, int N) {
    // sort(a.begin(),a.end())
    N++;
    int expected=(N*(N-1))/2;
    int actual_sum=0;
    for(int i=0;i<N-2;i++){
actual_sum+=a[i];
    }
    return expected-actual_sum;
}

// problem for finding two missing numbers from 1 to n (time complexity: O(nlogn), space complexity: O(n))
vector<int> findMissingNumbers(vector<int> &arr, int n)
{
	 vector<int> v;
    sort(arr.begin(), arr.end());
    int expected = 1;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i]< expected) {
            continue; // All good, move to next expected
        } 
            // Missing numbers until we hit current arr[i]
            while(expected < arr[i]) {
                v.push_back(expected);
                expected++;
            }
            expected++;
        }
        // Skip duplicates silently (arr[i] < expected case)
    
    
    // Handle missing after last element
    while(expected <n) {
        v.push_back(expected);
        expected++;
    }
    return v;

} 
// problem for findig all the missing numbers from 1 to n (time complexity: O(nlogn), space complexity: O(n))
vector<int> missingNumbers(vector<int> &arr, int n) {
    vector<int> v;
    sort(arr.begin(), arr.end());
    int expected = arr[0];
    
    for(int i = 0; i < n; i++) {
        if(arr[i]< expected) {
            continue; // All good, move to next expected
        } 
            // Missing numbers until we hit current arr[i]
            while(expected < arr[i]) {
                v.push_back(expected);
                expected++;
            }
            expected++;
        }
        // Skip duplicates silently (arr[i] < expected case)
    
    
    // Handle missing after last element
    while(expected <= n) {
        v.push_back(expected);
        expected++;
    }
    return v;
}