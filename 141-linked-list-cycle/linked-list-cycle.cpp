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

        // Brute
        /*
        unordered_set<ListNode*> ss;
        ListNode* curr = head;
        while (curr != NULL) {

            if (ss.find(curr) != ss.end())
                return true;

            ss.insert(curr);
            curr = curr->next;
        }

        return false;*/

        // Optimal

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};