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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* curr = head;
        int flag = 1;

        ListNode* newOdd = new ListNode(-1);
        ListNode* tailOdd = newOdd;

        ListNode* newEven = new ListNode(-1);
        ListNode* tailEven = newEven;

        while (curr) {
            if (flag % 2) {
                tailOdd->next = new ListNode(curr->val);
                tailOdd = tailOdd->next;
            } else {
                tailEven->next = new ListNode(curr->val);
                tailEven = tailEven->next;
            }
            curr = curr->next;
            flag++;
        }

        tailOdd->next = newEven->next;
        return newOdd->next;
    }
};