class Solution {
public:
    /*

    int getMaxElement(int& i, int& j, vector<int>& nums) {

       int elem = INT_MIN;
       for (int idx = i; idx <= j; idx++) {
           elem = max(elem, nums[idx]);
       }

       return elem;
   }

       vector<int> maxSlidingWindow(vector<int>& nums, int k) {

           int n = nums.size();
           vector<int> res;

           for (int i = 0; i <= n - k; i++) {
               int windowSizeIndex = (k + i) - 1;
               // cout << i << " " << windowSizeIndex << endl;
               int elem = getMaxElement(i, windowSizeIndex, nums);
               res.push_back(elem);
           }

           return res;
       }
       */

    int getMaxElement(int& maxIndex, int& i, int& j, vector<int>& nums) {

        int elem = INT_MIN;
        for (int idx = i; idx <= j; idx++) {
            if (nums[idx] >= elem) {
                elem = nums[idx];
                maxIndex = idx;
            }
            // cout << "@"<< nums[i] << " ";
        }

        return elem;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        int n = nums.size();

        // int maxIndex = -1;
        // int maxi = INT_MIN;

        // if (n == k)
        //     return nums;

        /*for (int i = 0; i < k; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i;
            }
        }
        res.push_back(maxi);
        // cout << maxIndex << endl;

        for (int i = k; i < n; i++) {

            // new window mein included hai?
            if (maxIndex == ((i - k) + 1)) {

                if (nums[i] >= maxi) {
                    maxi = nums[i];
                    maxIndex = i;
                }
                res.push_back(maxi);

            }
            // included
            else {
                maxi = INT_MIN;
                // cout << "* " << i << endl;
                int startOfWindow = (i - k) + 1;
                // cout << "#" << startOfWindow << " " <<  i << endl;
                int elem = getMaxElement(maxIndex, startOfWindow, i, nums);
                maxi = elem;
                res.push_back(maxi);
            }

            // cout << maxIndex << endl;
            // for (int& i : res) {
            //     cout << i << " ";
            // }
            // cout << endl;
        }

        return res;*/
        
        // Optimal
        deque<int> dq;
        for(int i = 0; i < n; i++) {

            // remove elements outside of windowSize
            while(!dq.empty() && i-k >= dq.front())
                dq.pop_front();
            // remove smaller elements (part of currentWindow) as they are useless
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            
            // push the current element
            dq.push_back(i);

            // dq's front will always give max element
            // start adding elements as soon as 
            // we pass our first window
            if(i>=k-1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;

    }
};