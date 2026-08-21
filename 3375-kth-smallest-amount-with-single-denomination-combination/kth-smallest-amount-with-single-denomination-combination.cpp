class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long multiple = 1;
                int selected = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        multiple = lcm(multiple, coins[i]);
                        selected++;

                        if (multiple > x)
                            break;
                    }
                }

                long long curr = x / multiple;

                if (selected % 2 == 1)
                    cnt += curr;
                else
                    cnt -= curr;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * k * *min_element(coins.begin(), coins.end());

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};