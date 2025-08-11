#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            else{
                char eLeft = (char)tolower(s[left]);
                char eRight = (char)tolower(s[right]);
                if(eLeft != eRight) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};


int main(){
    string s = "Was it a car or a cat I saw?";
    string str2 = "tab a cat";
    Solution s1;
    cout<<s1.isPalindrome(s);
    return 0;
}