class Solution {
public:
    vector<int> arr;

    Solution(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    int getRandom() {
        int n = arr.size();
        int random_index = rand() % n;

        return arr[random_index];
    }
};
// Approach: Store all linked list elements in a vector.
// Traverse the linked list and push each node's value into the vector.
// For getRandom(), generate a random index between 0 and n-1
// and return the element at that index.
// This allows O(1) random access.

// T.C: O(n) for constructor, O(1) for getRandom()
// S.C: O(n)
