/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        if(!head->next) return slow;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // cout << slow->val << " " << fast->val << endl; 
        }

        return slow;



    }
};