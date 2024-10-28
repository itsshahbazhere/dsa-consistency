// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//approach -2  beats 100%
// TIME COMPLEXITY = O(n)
// SPACE COMPLEXITY = O(1)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){

            if(prices[i] < buy){
                buy = prices[i];
            }
            else if(prices[i] - buy > maxProfit){
                maxProfit = prices[i] - buy;
            }
        }

        return maxProfit;
    }
};




//approach -1 
// TIME COMPLEXITY = O(n^2)
// SPACE COMPLEXITY = O(1)

 class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                int sellPrice=prices[j] - prices[i];
                maxProfit = max(maxProfit,sellPrice);
            }
        }
        
        return maxProfit;
        
    }
};