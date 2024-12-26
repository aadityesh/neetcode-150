class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        Brute
        - nested loops, stand on the elem and look to its right
        for(i <- o to n) {
            for(j <- i + 1 to n)
        }

        Better
        - create a hashmap and then store all elems
        - return elem with freq == 1

        */
        int res = 0;
        for(int i : nums) res = res ^ i;
        return res; 

    }
};