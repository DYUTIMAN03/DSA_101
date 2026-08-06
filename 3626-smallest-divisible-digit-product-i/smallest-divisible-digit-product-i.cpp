class Solution {
    int prod(int n) {
        int ans = 1;

        while (n) {
            ans = ans * (n%10);
            n /= 10;
        }
        return ans;
    }

public:
    int smallestNumber(int n, int t) {
        for (int i = n;; i++) {
            if (prod(i) % t == 0)
                return i;
        }

        return 0; // Never reached
    }
};