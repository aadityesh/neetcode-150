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
    vector<int> ans;
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        for (auto i : lists) {
            ListNode* temp = i;
            while (temp != NULL) {
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(ans.begin(), ans.end());

        ListNode* temp = new ListNode();
        ListNode* tail = temp;

        for (auto i : ans) {
            ListNode* curr = new ListNode(i);
            tail->next = curr;
            tail = curr;
        }

        return temp->next;
    }
};