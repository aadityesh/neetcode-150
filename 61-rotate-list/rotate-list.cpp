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
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reverseK(ListNode*& head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // return prev;
    }

    int length(ListNode* head) {

        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

    ListNode* kth(ListNode* head, int k) {

        k = k - 1;
        ListNode* curr = head;
        while (k-- && curr) {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        /*

        int n = length(head);
        if(n > 0) k = k % n;

        if (head == NULL || head->next == NULL || k <= 0)
            return head;


        head = reverse(head);

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* kthNode = kth(curr, k);

        if (kthNode) {
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseK(curr);
            head = kthNode;
            prev = curr;
            curr->next = nextNode;
            curr = nextNode;
            kthNode = kth(curr, n-k);
            reverse(curr);
            if(prev)
                prev->next = kthNode;
        }
        return head;

        */
        if (head == NULL || head->next == NULL || k <= 0)
            return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }
         if(n > 0) k = k % n;

        ListNode* temp = head;
        int times = n - k - 1;
        while (times--) {
            temp = temp->next;
        }

        tail->next = head;

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};