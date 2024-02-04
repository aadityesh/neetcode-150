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
    // Brute
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

        // Brute
        /*
            ListNode* curr = head;
            ListNode* prev = NULL;
            int size = sizeOfList(head);

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
        }*/
        
        // Optimal
        
        // ListNode* curr = new ListNode();
        ListNode* slow = head;
        ListNode* fast = head;

        while (n--)
            fast = fast->next;
        
        if(fast == NULL)  
            return head->next;

        while (fast != NULL && fast->next != NULL) {
            // curr = slow;
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};