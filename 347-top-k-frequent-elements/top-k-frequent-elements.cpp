class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mpp;
        vector<int> temp;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int cnt = 0;
        int currElem = -1;

        while(k--) {
            
            for(auto i : mpp) {

                if(i.second > cnt) {
                    cnt = i.second;
                    currElem = i.first;

                }
                
            }

           
                temp.push_back(currElem);
            
            cnt = 0;
            mpp[currElem] = -1;
            currElem = -1;

        }

        return temp;     


    }
};