#include<bits/stdc++.h>
using namespace std;
// using additional vector to strore result(time complexity: O(n), space complexity: O(k))
class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
      vector <int>result;
      result.push_back(arr[0]);
      for(int i=1;i<arr.size();i++){
          if(result.back()!=arr[i]){
             result.push_back(arr[i]);
          }
      }
      return result;
    result.push_back(arr[0]);
    }
};


// optimal approach without using extra space (time complexity: O(n), space complexity: O(1))
class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
    
 int j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[j]!=arr[i]){
        arr[++j]=arr[i];
        }
    }
    // resize the array to remove the extra elements
    arr.erase(arr.begin()+j+1,arr.end());
    return arr;
    }
};