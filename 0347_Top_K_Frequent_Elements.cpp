#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums){
            if(!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
        vector<pair<int, int>> temp;
        for (auto [key, value] : mp)
        {
            temp.push_back({value, key});
        }
        sort(temp.rbegin(), temp.rend());
        vector<int> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(temp[i].second);
        }
        return result;
    }
};




int main(){
    vector<int> v = {1,2};

    Solution s;
    vector<int> v2 = s.topKFrequent(v, 2);

    for(auto x : v2){
        cout<<x<<" ";
    }
    return 0;
}