#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s)); // số
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(a / b);
            }
        }
        return st.top();
    }
};


int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    Solution s;
    cout<<  s.evalRPN(tokens); 

    return 0;
}