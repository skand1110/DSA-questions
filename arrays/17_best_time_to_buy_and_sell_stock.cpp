// Approach 1: using max and min elements
// Time Complexity: O(n) Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
//-----------------------------------------------
// Approach 2: Sliding Window
// Time Complexity: ; Space Complexity:
