class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char& i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                
                // here, we check whether for a closing brac, we have a open 
                // brac or not
                if (!st.empty()) { 

                    if (i == ')' && st.top() == '(')
                        st.pop();
                    else if (i == ']' && st.top() == '[')
                        st.pop();
                    else if (i == '}' && st.top() == '{')
                        st.pop();
                    else
                        return false;

                } else
                    return false;
            }
        }

        return st.empty(); // this handles odd lengths of inp
    }
};