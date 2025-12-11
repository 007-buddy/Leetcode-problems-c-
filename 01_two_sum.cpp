// 1. Brute Force (Nested Loops)
// Check every pair with two nested loops.
#include<bits/stdc++.h>
using namespace std;
pair<int,int> twoSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
        if(nums[i]+nums[j]==target) return {i,j};
}

// 2. Hash Map (Optimal)
// Store complements in unordered_map for 
pair<int,int> twosum_optimal(const vector<int>& nums, int target) {
int n = nums.size();
unordered_map<int,int> mp;
for(int i=0; i<n; i++) {
    int comp = target - nums[i];
    if(mp.count(comp)) return {mp[comp], i};
    mp[nums[i]] = i;
}
}


// 3. Two Pointers (Sorted)
// Sort first, then left/right pointers converge.

pair<int,int> twoSum_sorted(const vector<int>& nums, int target) {
sort(nums.begin(), nums.end());
int n = nums.size();
int l=0, r=n-1;
while(l<r) {
    int sum = nums[l]+nums[r];
    if(sum==target) return {l,r};
    else if(sum<target) l++;
    else r--;
}
}
