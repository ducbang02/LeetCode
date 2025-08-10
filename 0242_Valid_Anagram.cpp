#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> um;

        for (int i = 0; i < s.size(); i++){
            um[s[i]]++;
            um[t[i]]--;
        }

        for (auto [c, count] : um)
        {
            if(count != 0) return false;
        }
        return true;
    }
};



int main(){
    string s1 = "hello123";
    string s2 = "321olleh2";
    Solution2 s;
    bool result = s.isAnagram(s1, s2);
    cout<<result;

    return 0;
}