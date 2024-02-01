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

    ListNode* reverseList(ListNode* head) {

        vector<int> a;
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
        }
        return curr;
    }
};