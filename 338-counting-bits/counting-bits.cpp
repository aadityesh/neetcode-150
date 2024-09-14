class Solution {
public:
    // int numberOfOnes(int n) {
    //     int cnt = 0;
    //     while (n) {
    //         if (n & 1)
    //             cnt++;
    //         n = n >> 1;
    //     }
    //     return cnt;
    // }
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            res[i] = res[i / 2] + (i % 2);
        }
        return res;
    }
};