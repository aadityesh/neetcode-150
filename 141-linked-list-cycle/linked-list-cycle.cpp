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
    // int cnt = 0;

    bool hasCycle(ListNode* head) {

        unordered_set<ListNode*> ss;
        ListNode* curr = head;
        while (curr != NULL) {

            if (ss.find(curr) != ss.end())
                return true;

            ss.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};