class Solution {
public:
    int missingNumber(vector<int>& a) {

        int n = a.size();
        int required_sum = (n * (n + 1)) / 2;

        int sum = 0;
        for (int i : a)
            sum += i;

        return (required_sum - sum);
    }
};