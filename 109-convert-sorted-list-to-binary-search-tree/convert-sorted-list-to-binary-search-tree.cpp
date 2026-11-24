class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;

        while(fast != NULL && fast->next != NULL){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        slow_prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// Approach:
// 1. Find the middle node using slow and fast pointers.
// 2. Make the middle node the root of the BST.
// 3. Disconnect the left half from the middle node.
// 4. Recursively construct the left subtree using the left half.
// 5. Recursively construct the right subtree using the right half.
// 6. Return the root to form a height-balanced BST.

// T.C: O(n log n) - Finding the middle takes O(n) at each recursive level.
// S.C: O(log n) - Recursion stack for a balanced BST.