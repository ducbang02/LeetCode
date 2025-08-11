#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxSell = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice) minPrice = prices[i];
            if(maxSell < prices[i] - minPrice) maxSell = prices[i] - minPrice;
        }
        return maxSell;
    }
};


int main(){
    vector<int> prices = {10,8,7,5,2};
    Solution s;
    int result = s.maxProfit(prices);
    cout<<result;
    return 0;
}