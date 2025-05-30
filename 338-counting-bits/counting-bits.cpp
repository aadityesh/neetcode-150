class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            result[i] = result[i / 2] + (i % 2);
        }

        return result;
    }
};