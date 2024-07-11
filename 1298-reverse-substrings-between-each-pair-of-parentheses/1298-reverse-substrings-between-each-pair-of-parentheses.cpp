class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c==')')
            {
                string rev="";
                while(!st.empty() && st.top() != '(')
                {
                    rev+=st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
                for(int j=0;j<rev.length();j++)
                    st.push(rev[j]);
            } 
            else 
                st.push(c);
        }
        string result = "";
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};