class Solution {
public:
    int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    vector<int> nextPermutation(vector<int> input) {

        /*
            1. Find break point
            2. swap with the next greater value
            3. call reverse for range (breakpoint+1, n)

            // 2 1 5 4 3
            // 2 3 5 4 1
            // 2 3 1 4 5

        */
        int n = input.size();
        int breakPointIndex = -1;
        for (int i = n-2; i >= 0; i--) {
            if (input[i] < input[i+1]) {
                breakPointIndex = i;
                break;
            }
        }

        if (breakPointIndex == -1) {
            reverse(input.begin(), input.end());
            return input;
        }

        for (int i = n - 1; i > breakPointIndex; i--) {
            if (input[i] > input[breakPointIndex]) {
                swap(input[breakPointIndex], input[i]);
                reverse(input.begin() + breakPointIndex + 1, input.end());
                break;
            }
        }

        return input;
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return {nums};

        int range = factorial(n);
        vector<vector<int>> res;
        vector<int> current = nums;

        // for(int i : current) cout << i << " ";
        for (int i = 0; i < range; i++) {
            vector<int> temp = nextPermutation(current);
            res.push_back(temp);
            current = temp;
        }

        return res;
    }
};
