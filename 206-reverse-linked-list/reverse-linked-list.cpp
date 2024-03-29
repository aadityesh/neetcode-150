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
    // void insertAtHead(ListNode*& head, int val) {

    //     ListNode* temp = new ListNode();
    //     temp->val = val;
    //     temp->next = head;
    //     head = temp;
    // }

    ListNode* reverseNode(ListNode*& head) {

         if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newHead = reverseNode(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;

    }

    ListNode* reverseList(ListNode* head) {

        /*vector<int> a;
        ListNode* temp = head;

        while (temp != NULL) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        for(auto i : a) cout << i << endl;


        int n = a.size();

        ListNode* curr = head;
        // curr->val = a[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            head->val = a[i];
            head = head->next;
        }*/
        /*

        // Optimal - Iterative
        ListNode * next, * prev = NULL;
        ListNode *curr = head;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

        */

        // Optimal - Recursive
      

       return reverseNode(head);

    }
};