class Solution {
public:
    int findDuplicate(vector<int>& a) {

        // Brute
        /*
        int n = a.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == a[j] && i != j)
                    cnt++;
            }

            if (cnt > 0) {
                res = a[i];
                break;
            }
        }

        return res;
        */

        // Optimal
        int slow = a[0];
        int fast = a[0];

        do {
            slow = a[slow];
            fast = a[a[fast]];
        } while (slow != fast);

        slow = a[0];
        while (slow != fast) {
            slow = a[slow];
            fast = a[fast];
        }

        return slow;
    }
};