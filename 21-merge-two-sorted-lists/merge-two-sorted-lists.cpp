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
    ListNode* merged = new ListNode();
    ListNode* tail = merged;
    int cnt = 0;

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* a = list1;
        ListNode* b = list2;

        while (a != NULL && b != NULL) {

            ListNode* curr = new ListNode();

            if (a->val <= b->val) {
                if (cnt == 0) {
                    tail->val = a->val;
                    cnt++;
                } else {
                    curr->val = a->val;
                    tail->next = curr;
                    tail = curr;
                }
                a = a->next;
            } else {

                if (cnt == 0) {
                    tail->val = b->val;
                    cnt++;
                } else {
                    curr->val = b->val;
                    tail->next = curr;
                    tail = curr;
                }

                b = b->next;
            }
            cout << "one" << endl;
        }

        while (a != NULL) {

            ListNode* curr = new ListNode();

            curr->val = a->val;
            tail->next = curr;
            tail = curr;

            a = a->next;
            cout << "two" << endl;
        }

        while (b != NULL) {

            ListNode* curr = new ListNode();
            curr->val = b->val;
            tail->next = curr;
            tail = curr;

            b = b->next;
            cout << "three" << endl;
        }

        return merged;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1 == NULL && list2 == NULL)
            return NULL;

        return merge(list1, list2);
    }
};