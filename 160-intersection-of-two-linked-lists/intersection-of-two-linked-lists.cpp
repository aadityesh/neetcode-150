/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            ListNode* curr1 = headA;
            ListNode* curr2 = headB;

            set<ListNode*> ss;
            while(curr1) {
                ss.insert(curr1);
                curr1 = curr1->next;
            }

            while(curr2) {
                if(ss.find(curr2) != ss.end()) break;
                curr2 = curr2->next;
            }

            return curr2;

    }
};