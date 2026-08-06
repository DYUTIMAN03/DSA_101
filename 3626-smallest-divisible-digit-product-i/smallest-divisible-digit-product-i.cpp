class Solution {
public:
    // Helper function to calculate the product of digits of a given number
    long long getDigitProduct(int num) {
        if (num == 0) {
            // While 'n' is >= 1, this case might be reached internally if num becomes 0
            // but for positive numbers containing 0, the check below handles it.
            return 0; 
        }
        long long product = 1;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0) {
                // If any digit is 0, the product of digits is 0.
                // 0 is divisible by any positive integer 't'.
                return 0;
            }
            product *= digit;
            temp /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        // Based on the hint, we only need to check at most 10 numbers.
        // So, we iterate from 'n' up to 'n + 9'.
        for (int i = n; i <= n + 9; ++i) {
            long long product = getDigitProduct(i);
            // Check if the digit product is divisible by 't'
            if (product % t == 0) {
                return i; // Return the first number that satisfies the condition
            }
        }
        // This part should ideally not be reached given the problem constraints and hint.
        // A solution is guaranteed to be found within the loop.
        return -1; 
    }
};