// finding the minimum number of radio transmitters needed to cover all houses
// time complexity: O(n log n) due to sorting
// space complexity: O(1)



#include <bits/stdc++.h>
using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
sort(x.begin(), x.end());
    int n = x.size();
    int i = 0;
    int count = 0;
    while (i < n) {
        // Find rightmost house coverable from x[i]
        int j = i;
        while (j < n && x[j] <= x[i] + k) {
            j++;
        }
        j--;  // Last valid j
        
        // Transmitter at x[j] covers up to x[j] + k
        int cover_end = x[j] + k;
        count++;
        
        // Skip covered houses
        while (i < n && x[i] <= cover_end) {
            i++;
        }
    }
    return count;
}