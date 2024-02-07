class Solution
{
    public:
        string srtWithFrequency(string s)
        {

            int freq[26] = { 0 };
            for (char i: s)
                freq[i - 'a']++;

            string t;
            for (int i = 0; i < 26; i++)
            {
                t += freq[i]; //5a3b2c
                t += (i + 'a');
            }
            return t;
        }
    vector<vector < string>> groupAnagrams(vector<string> &strs)
    {

        int n = strs.size();
        unordered_map<string, vector < string>> mpp;
        vector<vector < string>> ans;

        if (n == 1)
        {
            return {
                {
                    strs[0]
                }
            };
        }

        for (int i = 0; i < n; i++)
        {
           	// string curr = strs[i];
           	// sort(curr.begin(), curr.end());
            string curr = srtWithFrequency(strs[i]);
            mpp[curr].push_back(strs[i]);
           	// mpp[curr].push_back(strs[i]);
        }

        for (auto i: mpp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};