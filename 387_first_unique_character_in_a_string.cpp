/* function implementation to find the first unique character in a string*/
// The  below methhod used two passes first to store the requencies and other to find the first unique character
// time complexity : O(N) and space complexity : O(1) as we are using a fixed size array of 26 elements
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int>ch(26,0);
        for(char it:s){
            ch[it-'a']++;
        }
        for(char it:s){
            if(ch[it-'a']==1){
                return it;
            }
        }
        return '$';
        
    }
};