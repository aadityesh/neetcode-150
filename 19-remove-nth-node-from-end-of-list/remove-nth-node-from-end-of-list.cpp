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
    int sizeOfList(ListNode* head) {

        int cnt = 1;
        ListNode* curr = head;

        while (curr->next != NULL) {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;
        ListNode* prev = NULL;
        int size = sizeOfList(head);
        // cout << move << endl;
        // cout << size << endl;
        int move = sizeOfList(head) - n;
        if (n == 1 && size == 1) {
            head = NULL;
            return head;
        }

        if (n == 1 && size == 2) {
            head->next = NULL;
            return head;
        }

        if (move == 0) {
            head = head->next;
            return head;
        }

        while (move-- && curr != NULL) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
            prev->next = NULL;
        else
            prev->next = curr->next;

        return head;
    }
};