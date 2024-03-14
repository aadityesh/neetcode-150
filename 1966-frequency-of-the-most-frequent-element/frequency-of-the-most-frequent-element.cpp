#include <bits/stdc++.h>
class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {

        int n = a.size();
        long long left = 0;
        long long right = 0;
        long long res = 0;
        long long sum = 0;
        long long multi = 1;

        sort(a.begin(), a.end());
        while (right < n) {
            sum += a[right];
            while ((a[right] * (right - left + 1)) - sum > k) {
                sum -= a[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};