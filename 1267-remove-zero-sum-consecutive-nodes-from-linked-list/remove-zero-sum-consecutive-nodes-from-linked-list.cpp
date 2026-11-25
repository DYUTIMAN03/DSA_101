class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> mp;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;
        
        while(head != NULL) {
            prefixSum += head->val;
            if(mp.find(prefixSum) != mp.end()) {

                ListNode* P     = mp[prefixSum];
                ListNode* start = P;
                int pSum        = prefixSum;

                while(start != head) {      
                    start = start->next;
                    pSum += start->val;
                    if(start != head)
                        mp.erase(pSum);
                }
                P->next = start->next;   
            } else {
                mp[prefixSum] = head;
            } 
            head = head->next;
        }
        return dummy->next;
    }
};

/*
Approach
1. Create a dummy node and initialize the prefix sum map with mp[0] = dummy.
2. Traverse the linked list and calculate the prefix sum.
3. If the prefix sum is already present in the map, a zero-sum sublist exists between the previous occurrence and the current node.
4. Remove the intermediate prefix sums from the map.
5. Update the previous node's next pointer to skip the zero-sum sublist.
6. Otherwise, store the current prefix sum and node in the map.
Complexity
- Time: \(O(n)\)
- Space: \(O(n)\)
*/