/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        // Set - Node*
        unordered_set<ListNode*> stt;
        ListNode* curr = head;
        while (curr) {
            if (stt.find(curr) != stt.end())
                return curr;

            stt.insert(curr);
            curr = curr->next;
        }

        return NULL;
    }
};