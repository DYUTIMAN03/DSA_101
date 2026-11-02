class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

/*
Approach: Bit Manipulation

1. Check whether n is positive.
2. Subtract 1 from n.
3. Perform bitwise AND between n and n-1.
4. If the result is 0, n is a power of 2.

TC: O(1)
SC: O(1)
*/

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        while(n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }
};

/*
Approach: Repeated Division

1. Reject zero and negative numbers.
2. Keep dividing n by 2 while it is even.
3. If n eventually becomes 1, it is a power of 2.
4. Otherwise, it isn't.

TC: O(log n), because n is halved in every iteration.
SC: O(1), because we use only a few variables.
*/