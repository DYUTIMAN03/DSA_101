class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};

/*
Approach (Floyd's Cycle Detection Algorithm):
1. Initialize slow and fast pointers at head.
2. Move slow one step and fast two steps at a time.
3. If both pointers meet, a cycle exists, so return true.
4. If fast reaches NULL or fast->next reaches NULL,
   the linked list has no cycle, so return false.

TC: O(n) - The pointers traverse the linked list at most linearly.
SC: O(1) - Only two pointers are used.
*/