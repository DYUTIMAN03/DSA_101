/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != NULL) {
            ListNode* next = curr->next;

            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if (first == -1) {
                    first = position;
                } 
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, position - last);
                }

                // Update last critical point
                last = position;
            }

            prev = curr;
            curr = next;
            position++;
        }

        // Need at least two critical points
        if (first == last) {
            return ans;
        }

        ans[0] = minDist;          // Minimum distance
        ans[1] = last - first;     // Maximum distance

        return ans;
    }
};