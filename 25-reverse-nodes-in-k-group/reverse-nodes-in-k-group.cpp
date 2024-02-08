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

    void reverseArr(vector<int>& a, int start, int end) {
        while (start <= end) {
            swap(a[start++], a[end--]);
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int n = ans.size();
        int i = 0;

        int times = n / k;
        while (times--) {
            reverseArr(ans, i, i + k - 1);
            i = i + k;
        }

        temp = new ListNode();
        ListNode* tail = temp;

        for (auto i : ans) {
            ListNode* curr = new ListNode(i);
            tail->next = curr;
            tail = curr;
        }

        return temp->next;
    }
};