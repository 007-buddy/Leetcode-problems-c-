/* implementing the container with most water problem using two
 pointer approach by repeatedly tracking the maximum area  and
 moving the pointer pointing to the smaller height inward.
 */

// time complexity : O(N) and space complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
int maxWater(vector<int> &arr) {
int left=0;
int right=arr.size()-1;
int max_area=0;
while(left<right){
    
    int curr_area=((right-left)*(min(arr[left],arr[right])));
    max_area=max(max_area,curr_area);
    if(arr[left]<arr[right])left++;
    else right--;
}
return max_area;
        
    }
};