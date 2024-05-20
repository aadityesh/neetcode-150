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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        /*
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
        */

        int n1 = 0;
        int n2 = 0;

        while (curr1) {
            n1++;
            curr1 = curr1->next;
        }

        while (curr2) {
            n2++;
            curr2 = curr2->next;
        }

        curr1 = headA;
        curr2 = headB;
        int diff = 0;

        if (n1 > n2) {
            diff = n1 - n2;
            while (diff-- && curr1) curr1 = curr1->next;
        }
        else {
            diff = n2 - n1;
            while (diff-- && curr2) curr2 = curr2->next;
        }

        while(curr1 && curr2) {
            if(curr1 == curr2) break;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr1;
    }
};