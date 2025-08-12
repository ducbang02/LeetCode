#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool Valid(char open, char close){
        return (open == '(' && close == ')') || open == '{' && close == '}' || open == '[' && close == ']';
    }

    bool isValid(string s) {
        stack<char> st;
        for (auto c : s)
        {
            if(c == '[' || c == '{' || c == '('){
                st.push(c);
            }else if(c == ']' || c == '}' || c == ')'){
                if(st.empty() || !Valid(st.top(), c) ){
                    return false;
                }
                st.pop();
            }
        }
        
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};


int main(){
    string s = "([{()}])";

    Solution s1;
    cout<<s1.isValid(s);
    return 0;
}