class Solution {
   private:
   int atoi(string s, int i, int ans, int sign) {
       if (i == s.length() || s[i] < '0' || s[i] > '9') {
           return ans * sign;
       }

       int no = s[i] - '0';
       if ((ans > (INT_MAX / 10)) || (ans * 10 > INT_MAX - no)) {
           return sign == 1 ? INT_MAX : INT_MIN;
       }
       ans = ans * 10 + no;
       return atoi(s, i + 1, ans, sign);
   }
public:
   int myAtoi(string s) {
       int i = 0;
       int ans = 0;
       int sign = 1;  
       for( ; i < s.length() && s[i] == ' '; ) 
           i++; 
       
       if(s[i] == '-' || s[i] == '+') {
           if(s[i] == '-' )
               sign = -1;
           i++;
       }
       return atoi(s, i, ans, sign);
   }
};