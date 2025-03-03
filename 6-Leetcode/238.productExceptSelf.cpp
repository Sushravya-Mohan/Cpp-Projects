#include <vector>
using namespace std;

// Function to calculate the product of array elements except self
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();                // Get the number of elements in the input vector
    vector<int> result(n, 1);           // Initialize the result vector with 1s

    // First pass: Calculate the prefix (left) product for each element
    int leftProduct = 1;                // Variable to store the running product from the left
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct;        // Set result[i] as the product of all elements to the left of i
        leftProduct *= nums[i];         // Update the leftProduct to include nums[i]
    }

    // Second pass: Multiply by the suffix (right) product for each element
    int rightProduct = 1;               // Variable to store the running product from the right
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;      // Multiply the current result[i] with the product of all elements to the right of i
        rightProduct *= nums[i];        // Update the rightProduct to include nums[i]
    }
    return result;                      // Return the final result array
}