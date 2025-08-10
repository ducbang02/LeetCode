#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
            //strs = ["act","pots","tops","cat","stop","hat"]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto x : strs){
            string key = x;
            sort(key.begin(), key.end());
            mp[key].push_back(x);
        }
        vector<vector<string>> result;
        for (auto [k, value] : mp)
        {
            result.push_back(value);
        }
        return result;
    }
};



int main(){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    
    Solution s;
    vector<vector<string>> groups = s.groupAnagrams(strs);

    // In kết quả
    for (auto& group : groups) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}