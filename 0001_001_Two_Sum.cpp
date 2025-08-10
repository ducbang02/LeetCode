#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

    class Solution2 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> mp;
            for (int i = 0; i < nums.size(); i++)
            {
                mp[nums[i]] = i;
            }
            
            for(int i = 0; i < nums.size(); i++){
                int temp = target - nums[i];
                if(mp.count(temp) && mp[temp] != i){
                    return {i, mp[temp]};
                }
            }
            return {};
        }
    };


int main(){
    vector<int> nums = {4, 5, 6};

    Solution2 s;
    vector<int> r = s.twoSum(nums, 10);
    cout<<r[0]<<", "<<r[1];

    return 0;
}