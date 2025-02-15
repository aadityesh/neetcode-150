class Solution {
public:
    int kadaneMax(vector<int>& arr) {

        int n = arr.size();

        int sum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxSum = max(sum, maxSum);

            if (sum < 0)
                sum = 0;
        }

        return maxSum;
    }

    int kadaneMin(vector<int>& res) {
        int sum = 0;
        int minSum = INT_MAX;

        for (int& i : res) {
            sum += i;
            minSum = min(minSum, sum);

            if (sum > 0)
                sum = 0;
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& arr) {

        int n = arr.size();

        int maxSum = kadaneMax(arr);
        if (maxSum < 0)
            return maxSum;
        int minSum = kadaneMin(arr);
        int circularSum = accumulate(arr.begin(), arr.end(), 0) - (minSum);
        int res = max(maxSum, circularSum);

        cout << maxSum << " " << minSum << " " << circularSum << endl;

        return res;
    }
};