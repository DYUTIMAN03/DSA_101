#include <vector>
#include <queue>
#include <numeric> // For std::iota if needed for all methods

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Step 1: Build the graph using an adjacency list.
        std::vector<std::vector<int>> adj(n);
        for (const auto& invocation : invocations) {
            int invoker = invocation[0];
            int invoked = invocation[1];
            adj[invoker].push_back(invoked);
        }

        // Step 2: Identify all suspicious methods using BFS starting from k.
        std::vector<bool> is_suspicious(n, false);
        std::queue<int> q;

        q.push(k);
        is_suspicious[k] = true;

        while (!q.empty()) {
            int current_method = q.front();
            q.pop();

            for (int neighbor_method : adj[current_method]) {
                if (!is_suspicious[neighbor_method]) {
                    is_suspicious[neighbor_method] = true;
                    q.push(neighbor_method);
                }
            }
        }

        // Step 3: Check the removal condition.
        bool removal_possible = true;
        for (const auto& invocation : invocations) {
            int invoker = invocation[0];
            int invoked = invocation[1];

            // If a non-suspicious method (invoker) invokes a suspicious method (invoked),
            // then the group of suspicious methods cannot be removed.
            if (is_suspicious[invoked] && !is_suspicious[invoker]) {
                removal_possible = false;
                break; // No need to check further, removal is impossible.
            }
        }

        // Step 4: Construct the result.
        std::vector<int> result;
        if (removal_possible) {
            // If removal is possible, return all non-suspicious methods.
            for (int i = 0; i < n; ++i) {
                if (!is_suspicious[i]) {
                    result.push_back(i);
                }
            }
        } else {
            // If removal is not possible, return all original methods.
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        }

        return result;
    }
};