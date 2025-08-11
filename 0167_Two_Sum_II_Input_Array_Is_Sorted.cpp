#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            if(numbers[left] + numbers[right] < target){
                left++;
            }else if(numbers[left] + numbers[right] > target){
                right--;
            }else return {left + 1, right + 1};
        }
        return {-1, -1};
    }
};


int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    vector<int> v = s.twoSum(nums, 3);
    cout<<v[0]<<" "<<v[1];
    return 0;
}