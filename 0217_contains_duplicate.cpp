#include <bits/stdc++.h>

using namespace std;


class Solution2 {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        if(s.size()== size){
            return false;
        }
        return true;
    }
};

class Solution3 {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto x : nums)
        {
            if(us.count(x)){
                return true;
            }
            us.insert(x);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 3};
    vector<int> nums2 = {1, 2, 3, 4};
    Solution3 s;
    bool result = s.hasDuplicate(nums);
    bool result2 = s.hasDuplicate(nums2);

    cout<<result<<endl;
    cout<<result2<<endl;
    return 0;
}