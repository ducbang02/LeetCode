#include <bits/stdc++.h>

using namespace std;


//Time: O(n), space: O(n^2)
vector<int> plusOne(vector<int>& digits) {
    string s = "";
    for(auto x : digits){
        s += to_string(x);
    }
    string s2 = to_string(stol(s) + 1);
    if(s2.size() > s.size()) digits.push_back(0);
    for(int i = 0; i < digits.size(); i++){
        digits[i] = s2[i] - '0';
    }
    return digits;
}


//Time: O(n), space: O(1)
vector<int> plusOne2(vector<int>& digits) {
    int temp;
    for(int i = digits.size() - 1; i >= 0; i--){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){
    vector<int> nums = {9,9};

    vector<int> nums2 = plusOne2(nums);

    for (auto x : nums2)
    {
        cout<<x<<" ";
    }
    
    return 0;
}