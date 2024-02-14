class Solution {
public:
    // pref, suff -> Brute (min(L, R) - height[i])
    /*
    vector<int> pref(vector<int> a) {

        int n = a.size();
        int maxi = 0;
        int idx = 0;
        vector<int> p(n, 0);

        for (auto i : a) {
            p[idx++] = maxi;
            maxi = max(maxi, i);
        }

        return p;
    }

    vector<int> suff(vector<int> a) {

        int n = a.size();
        int maxi = 0;
        int idx = n - 1;
        vector<int> p(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            p[idx--] = maxi;
            maxi = max(maxi, a[i]);
        }

        return p;
    }
    */

    int trap(vector<int>& height) {

        int n = height.size();
        /*
        vector<int> prefix = pref(height);
        vector<int> suffix = suff(height);
        int res = 0;

        for (int i = 0; i < n; i++) {
            int curr = min(prefix[i], suffix[i]) - height[i];
            if(curr >= 0) res += curr;

            cout << curr << endl;
        }

        return res;
        */

        int res = 0;
        int left = 0;
        int right = n - 1;
        int leftMax = height[0];
        int rightMax = height[n - 1];

        while (left < right) {

            if(leftMax <= rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                res += (leftMax - height[left]);

            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                res += (rightMax - height[right]);
            }

        }
        return res;
    }
};