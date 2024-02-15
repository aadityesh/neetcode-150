class Solution
{
    public:
        bool isAnagram(string s, string t)
        {

            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
           
            /*
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
            */
        }
};