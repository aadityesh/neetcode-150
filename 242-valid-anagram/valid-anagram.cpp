class Solution
{
    public:
        bool isAnagram(string s, string t)
        {

            int n = s.size();

            if (n != t.size()) return false;

            unordered_map<char, int> mpp;

            for (int i = 0; i < n; i++)
            {
                mpp[s[i]]++;
                mpp[t[i]]--;
            }

            for(auto i : mpp) {
                if(i.second)
                    return false;
            }
            return true;
        }
};