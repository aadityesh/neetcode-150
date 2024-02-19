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

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* a = list1;
        ListNode* b = list2;

        while (a != NULL && b != NULL) {

            ListNode* curr = new ListNode();

            if (a->val <= b->val) {
                tail->next = a;
                tail = tail->next;
                a = a->next;
            } else {
                tail->next = b;
                tail = tail->next;
                b = b->next;
            }
        }

        if (a != NULL) {
            tail->next = a;
        }

        if (b != NULL) {
            tail->next = b;
        }

        return merged->next;
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