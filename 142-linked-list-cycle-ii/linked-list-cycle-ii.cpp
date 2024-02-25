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
        // Brute - Keeping Track of Visited Nodes.
        /*
        unordered_set<ListNode*> stt;
        ListNode* curr = head;
        while (curr) {
            if (stt.find(curr) != stt.end())
                return curr;

            stt.insert(curr);
            curr = curr->next;
        }

        return NULL;
        */

        // 2 * (dis of slow) = dis of fast
        ListNode* slow = head;
        ListNode* fast = head;
        bool res = false;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                res = true;
                break;
            }
        }

        if (res) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        return NULL;
    }
};