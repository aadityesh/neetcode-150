class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, res = INT_MIN;

        for (int i = 0; i < n; i++) {

            sum += arr[i];
            res = max(res, sum);

            if (sum < 0)
                sum = 0;
        }

        return res;
    }
};