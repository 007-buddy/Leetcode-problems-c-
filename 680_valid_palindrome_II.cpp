// implementing a function to check if a string can be a palindrome by removing at most one character

// the below solution uses a two-pointer approach to compare characters from both ends of the string
// time complexity: O(n) and space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
    bool val(string s, int left, int high) {
        while (left < high) {
            if (s[left] != s[high]) return false;
            left++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int high = n - 1;

        while (left < high) {
            if (s[left] != s[high]) {
                return val(s, left + 1, high) || val(s, left, high - 1);
            }
            left++;
            high--;
        }

        return true;
    }