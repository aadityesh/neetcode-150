class Solution {

public:
    void reverse(ListNode*& head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* kth(ListNode* head, int k) {

        k = k - 1;
        ListNode* curr = head;
        while (k-- && curr) {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k == 1)
            return head;

        // int len = length(head);
        // int count = len / k;

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        ListNode* kthNode = NULL;

        ListNode* curr = head;

        while(curr) {

            kthNode = kth(curr, k);

            if(kthNode == NULL) {
                if(prev) prev->next = curr;
                break;
            }
            else {

                nextNode =  kthNode->next;
                kthNode->next = NULL;
                reverse(curr);

                if(curr == head) {
                    head = kthNode;
                }

                else {
                    prev->next = kthNode;
                }

                prev = curr;
                curr = nextNode;

            }


        }

        return head;
    }
};
