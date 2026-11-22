class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) 
                break;
        }

        if(slow != fast) return NULL;

        ListNode *P = head;

        while(P != slow){
            P = P->next;
            slow = slow->next;
        }
        return P;
    }
};

/*
Approach (Floyd's Cycle Detection Algorithm):
1. Initialize slow and fast pointers at head.
2. Move slow one step and fast two steps at a time.
3. If they meet, a cycle exists. Otherwise, return NULL.
4. Initialize another pointer P at head.
5. Move P and slow one step at a time.
6. They will meet at the starting node of the cycle.
7. Return that node.

TC: O(n) - Each pointer traverses at most O(n) nodes.
SC: O(1) - Only a constant number of pointers are used.
*/