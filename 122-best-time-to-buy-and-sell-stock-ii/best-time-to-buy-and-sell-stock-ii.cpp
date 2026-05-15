class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        int min = INT_MAX;
        int max = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            else {
                if ((i + 1) < n && prices[i + 1] < prices[i]) {
                    max = prices[i];
                    profit = profit + (max - min);
                    min = prices[i];
                    max = 0;
                }
                else {
                    max = prices[i];
                    if (i + 1 == n) {
                        profit = profit + (max - min);
                    }
                }
            }
        }

        return profit;
    }
};