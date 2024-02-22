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
    void reorderList(ListNode*& head) {

        // vector<int> a;
        // ListNode* temp = head;
        // while (temp != NULL) {
        //     a.push_back(temp->val);
        //     temp = temp->next;
        // }

        // int i = 0;
        // int j = a.size() - 1;

        // ListNode* newList = new ListNode(0);
        // ListNode* tail = newList;

        // while (i <= j) {

        //     if (i < j && i != 0) {
        //         ListNode* newNode = new ListNode(a[j]);
        //         tail->next = newNode;
        //         tail = newNode;
        //         j--;
        //     }

        //     if (i <= j) {
        //         ListNode* newNode = new ListNode(a[i]);
        //         tail->next = newNode;
        //         tail = newNode;
        //         i++;
        //     }
        // }

        // // ListNode* p = newList;
        // // while(p != NULL) {
        // //     cout << p->val << " ";
        // //     p = p->next;
        // // }
        // cout << head->val << endl;
        // head->next = newList->next->next;

        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        int times = st.size() / 2;
        if (times == 0)
            return;

        curr = head;
        ListNode* next = NULL;
        while (times--) {
            next = curr->next;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
            curr->next = next;
            curr = curr->next;
        }
        curr->next = NULL;
    }
};