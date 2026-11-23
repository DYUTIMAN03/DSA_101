// Approach-1: Brute Force
class ProductOfNumbers {
public:
    vector<int> nums;
    int n;

    ProductOfNumbers() {
    }

    void add(int num) {
        nums.push_back(num);
    }

    int getProduct(int k) {
        int prod = 1;
        int n = nums.size();

        for(int i = n-k; i < n; i++) {
            prod *= nums[i];
        }

        return prod;
    }
};

/*
Approach 1: (BRUTE FORCE)
1. Maintain a vector to store all the incoming numbers.
2. In the add() function, simply push the new number into the vector.
3. In getProduct(k), calculate the product of the last k elements.
4. Start from index n-k and multiply all elements until the end.
5. Return the calculated product.

TC:
- add(): O(1) amortized.
- getProduct(): O(k), as we traverse the last k elements.

SC: O(n) - Store all incoming numbers in the vector.
*/

