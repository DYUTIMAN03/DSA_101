class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};

/*
Approach:
1. Maintain two pointers: odd and even, starting at the first and second nodes.
2. Store the starting node of the even list in evenStart.
3. Connect odd nodes together using odd->next = even->next.
4. Connect even nodes together using even->next = even->next->next.
5. Move both pointers forward to their respective next nodes.
6. Once traversal is complete, connect the last odd node to evenStart.
7. Return head.

TC: O(n) - Traverse the linked list once.
SC: O(1) - Only a constant number of pointers are used.
*/