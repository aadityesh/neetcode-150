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
    ListNode* oddEvenList(ListNode* head) {

        // Brute
        /*
         vector<int> even;
         vector<int> odd;

         ListNode* curr = head;
         int idx = 1;
         while (curr) {
             if (idx % 2 == 0) {
                 even.push_back(curr->val);
                 idx++;
             } else {
                 odd.push_back(curr->val);
                 idx++;
             }
             curr = curr->next;
         }

         curr = head;
         for (int i = 0; i < odd.size(); i++) {
             curr->val = odd[i];
             curr = curr->next;
         }
         for (int i = 0; i < even.size(); i++) {
             curr->val = even[i];
             curr = curr->next;
         }

         return head;
         */

        // Better
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> data;
        // adding odd elems first
        ListNode* curr = head;
        while (curr && curr->next) {
            data.push_back(curr->val);
            curr = curr->next->next;
        }

        if (curr) {
            data.push_back(curr->val);
        }

        // adding even elems second
        curr = head->next;
        while (curr && curr->next) {
            data.push_back(curr->val);
            curr = curr->next->next;
        }

        curr = head;
        int i = 0;
        for (int i = 0; i < data.size(); i++) {
            curr->val = data[i];
            curr = curr->next;
        }

        return head;
    }
};