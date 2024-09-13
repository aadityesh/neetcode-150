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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;
        ListNode* temp = head;

        while (curr) {
            while (temp && (curr->val == temp->val))
                temp = temp->next;
            curr->next = temp;
            curr = curr->next;
        }

        return head;
    }
};