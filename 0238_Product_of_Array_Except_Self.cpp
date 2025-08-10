#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> nums2;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = 1;
            for (int j = 0; j < nums.size(); j++)
            {
                
                if (j != i)
                {
                    temp*=nums[j];
                }
            }
            nums2.push_back(temp);
        }
        return nums2;
    }
};

int main()
{
    vector<int> v = {1,2,4,6};
    Solution1 s;
    vector<int> result = s.productExceptSelf(v);
    for (auto x : result)
    {
        cout<<x<<" ";
    }
    

    return 0;
}