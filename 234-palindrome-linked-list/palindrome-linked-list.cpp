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
    ListNode* reverse(ListNode*& head) {

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // aabaa

        // curr = prev;
        // while(curr) {
        //     cout << curr->val << " " << endl;
        //     curr = curr->next;
        // }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // tortoise-hare method to find the middle
        // reverse using mid
        // traverse from L-R and R-L
        // reverse using mid

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverseHead = reverse(slow);

        ListNode* curr1 = head;
        ListNode* curr2 = reverseHead;

        while (curr2) {
            if (curr1->val != curr2->val)
                return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        reverse(slow);
        return true;
    }
};