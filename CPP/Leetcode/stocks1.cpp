/*
121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
premium lock iconCompanies

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104
*/
#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices) {
    auto high = prices.begin();
    auto low = prices.begin();
    int max_diff = 0;

    for (auto elem = prices.begin(); elem != prices.end(); elem++){
        high = elem;

        if (*elem < *low) {
            low = elem;
        }

        if ((*high - *low) > max_diff) {
            max_diff = *high - *low;
        }
    }
    return max_diff;

}

int main(int argc, char** argv) {
    std::vector<int> inp = {7,1,5,3,6,4};
    int res = maxProfit(inp);
    std::cout << res << std::endl << std::flush;
    return 0;
}

