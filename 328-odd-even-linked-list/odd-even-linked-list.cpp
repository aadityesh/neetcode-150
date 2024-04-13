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
    }
};