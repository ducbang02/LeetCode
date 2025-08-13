#include <bits/stdc++.h>

using namespace std;

//Use HashSet: Time O(n), Space O(n)
int findDuplicate(vector<int>& nums) {
    unordered_set<int> hashSet;
    for (auto x : nums)
    {
        if(hashSet.count(x)){
            return x;
        }
        hashSet.insert(x);
    }
    return -1;    
}

//Use Floyd’s Tortoise and Hare: Time O(n), Space O(1)
int findDuplicate(vector<int>& nums) {
     int slow = nums[0];
    int fast = nums[0];

    // Pha 1: tìm điểm gặp nhau
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Pha 2: tìm duplicate
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // hoặc fast, cùng giá trị       
}

int main(){
    vector<int> nums = {3,3,3,3,3};
    cout<<findDuplicate(nums);
    return 0;
}