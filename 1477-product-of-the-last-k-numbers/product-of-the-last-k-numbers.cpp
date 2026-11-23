// // Approach-1: Brute Force
// class ProductOfNumbers {
// public:
//     vector<int> nums;
//     int n;

//     ProductOfNumbers() {
//     }

//     void add(int num) {
//         nums.push_back(num);
//     }

//     int getProduct(int k) {
//         int prod = 1;
//         int n = nums.size();

//         for(int i = n-k; i < n; i++) {
//             prod *= nums[i];
//         }
//         return prod;
//     }
// };

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

// Approach-2: Prefix Product (Optimal)
class ProductOfNumbers {
public:
    vector<int> nums;
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        if(num == 0) {
            nums = {};
            n = 0;
        } else {
            if(nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n-1] * num);
            }
            n++;
        }
    }

    int getProduct(int k) {
        if(k > n) {
            return 0;
        } else if(k == n) {
            return nums[n-1];
        }
        return nums[n-1] / nums[n-k-1];
    }
};

/*
Approach:
1. Maintain a vector to store cumulative (prefix) products.
2. In add(), if the incoming number is 0, clear the vector
   and reset n because any product containing 0 is 0.
3. If the number is non-zero, multiply it with the previous
   cumulative product and store the result.
4. In getProduct(k):
   - If k > n, a zero exists in the last k numbers, so return 0.
   - If k == n, return the last cumulative product.
   - Otherwise, divide the total prefix product by the prefix
     product before the last k elements.
5. Return the calculated product.

TC:
- add(): O(1) amortized.
- getProduct(): O(1).

SC: O(n) - Stores cumulative products since the last zero.
*/