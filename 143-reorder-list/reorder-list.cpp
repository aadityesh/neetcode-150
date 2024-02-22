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
    void reorderList(ListNode*& head) {

        // Brute
        /*
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        int times = st.size() / 2;
        if (times == 0)
            return;

        curr = head;
        ListNode* next = NULL;
        while (times--) {
            next = curr->next;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
            curr->next = next;
            curr = curr->next;
        }
        curr->next = NULL;*/

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = slow;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Merge
        ListNode* n1 = head;
        ListNode* n2 = prev;

        ListNode* tmp = nullptr;
        while (n2->next) {
            tmp = n1->next;
            n1->next = n2;
            n1 = tmp;

            tmp = n2->next;
            n2->next = n1;
            n2 = tmp;
        }
    }
};