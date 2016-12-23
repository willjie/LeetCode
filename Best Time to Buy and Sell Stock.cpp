/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.\
*/

/*这道题最开始一直没读懂题目，他的意思就是怎么买卖股票赚的最多*/
/*这道题相当简单，感觉达不到Medium的难度，只需要遍历一次数组，
用一个变量记录遍历过数中的最小值，然后每次计算当前值和这个最小值之间的差值最为利润，
然后每次选较大的利润来更新。当遍历完成后当前利润即为所求，*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }
        /*本题的主要思想就是一次卖出的价格-一次买入的价格=利润尽量大（重点是只能买一次）*/
        int minp = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size();i++)
        {
          minp = min(minp,prices[i]);                             /*这个方法比传统方法的时间复杂度低*/
          maxProfit = max(maxProfit,prices[i] - minp);           
        }
        
        return maxProfit;
        
        
        
    }
};