#include <vector>       // Include the vector header to use the std::vector container
#include <limits>       // Include limits to use std::numeric_limits for initializing minPrice
using namespace std;    // Use the standard namespace to avoid prefixing std::

// Function to compute the maximum profit from stock prices
int maxProfit(vector<int>& prices) {
    // Initialize the minPrice with largest possible integer value
    // This ensures that any price in the array will be less than this initial value
    int minPrice = numeric_limits<int>::max();

    // Initialize the maxProfit to 0. This variable will keep track of the maximum profit found
    int maxProfit = 0;

    // Loop through each price in the vector 'prices'
    for (int i = 0; i < prices.size(); i++) {
        // If the current price is lower than the minPrice seen so far,
        // update the minPrice to be this new lower price.
        if (prices[i] < minPrice) 
            minPrice = prices[i];
        else {
            // Calculate profit if selling at current price with the minPrice as the buying price
            int profit = prices[i] - minPrice;
            // Update the maxProfit if the current profit is greater than the maxProfit seen so far
            if (profit > maxProfit)
                maxProfit = profit;
        }
    }
    // Return the maximum profit calculated. If no profit is possible, it returns 0
    return maxProfit;
}