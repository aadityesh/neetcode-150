class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = arr[n - 1];
        int hash[1001] = {0};

        for (int i : arr)
            hash[i]++;

        for (int i = 1; i < 1001; i++) {
            if (hash[i] == 0) {
                k--;
                if (k == 0)
                    return i;
            }
        }
        cout << k << endl;
        return (1000 + k);

    }
};