class Solution {
    int gcd(int a, int b) {
        // gcd(a,b) = gcd(b, a%b)
        while (b) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i : nums) {
            if (i > maxi) {
                maxi = i;
            }
            if (i < mini) {
                mini = i;
            }
        }

        return gcd(mini, maxi);
    }
};