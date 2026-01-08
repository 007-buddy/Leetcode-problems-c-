// uses a sliding window technique  and a set to keep track of characters in the current window
// time complexity: O(n) and space complexity: O(min(m,n)) where m is the size of the character set

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> ch;
        int len = 0, l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (ch.find(s[i]) != ch.end())
            {
                ch.erase(s[l]);
                l++;
            }
            ch.insert(s[i]);
            len = max(len, i - l + 1);
        }
        return len;
    }
};
