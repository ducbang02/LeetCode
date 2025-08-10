#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        for (auto x : nums)
        {
            int length = 0;
            while(find(nums.begin(), nums.end(), x + length) != nums.end()){
                length++;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
        
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int dem = 1;
        int maxDem = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1){
                dem++;
            }
            if(nums[i] != nums[i-1] + 1) dem = 0; 
            maxDem = max(maxDem, dem);
        }
        return maxDem;
    }
};



int main(){
    vector<int> nums = {0,3,2,5,4,6,1,1};

    Solution2 s;
    cout<<s.longestConsecutive(nums);

    return 0;
}

