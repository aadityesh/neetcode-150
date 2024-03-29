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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        /* ListNode* res = new ListNode();
         ListNode* tail = res;

         ListNode* h1 = l1;
         ListNode* h2 = l2;

         int carry = 0;

         while (h1 && h2) {

             int sum = h1->val + h2->val + carry;

             if ((sum / 10) > 0)
                 carry = sum / 10;
             else
                 carry = 0;

             ListNode* curr = new ListNode(sum % 10);
             tail->next = curr;
             tail = curr;

             h1 = h1->next;
             h2 = h2->next;
         }

         while (h1) {

             int sum = h1->val + carry;
             if ((sum / 10) > 0)
                 carry = sum / 10;
             else
                 carry = 0;

             ListNode* curr = new ListNode(sum % 10);
             tail->next = curr;
             tail = curr;

             h1 = h1->next;
         }

         while (h2) {

             int sum = h2->val + carry;

             if ((sum / 10) > 0)
                 carry = sum / 10;
             else
                 carry = 0;

             ListNode* curr = new ListNode(sum % 10);
             tail->next = curr;
             tail = curr;

             h2 = h2->next;
         }

         if (carry != 0) {
             ListNode* curr = new ListNode(carry);
             tail->next = curr;
             tail = curr;
         }

         return res->next;*/

        // Clean

        ListNode* res = new ListNode();
        ListNode* tail = res;

        ListNode* h1 = l1;
        ListNode* h2 = l2;

        int carry = 0;

        while (h1 || h2) {

            int val1 = (h1 != NULL) ? h1->val : 0;
            int val2 = (h2 != NULL) ? h2->val : 0;

            int sum = (val1 + val2 + carry);
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = newNode;

            if (h1 != NULL)
                h1 = h1->next;
            if (h2 != NULL)
                h2 = h2->next;
        }

        if (carry != 0) {
            tail->next = new ListNode(carry);
        }

        return res->next;
    }
};