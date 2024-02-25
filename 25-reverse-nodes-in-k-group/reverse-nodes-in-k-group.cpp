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
    vector<int> ans;

public:
    /*
    void reverseArr(vector<int>& a, int start, int end) {
        while (start <= end) {
            swap(a[start++], a[end--]);
        }
    }*/

    ListNode* findKth(ListNode* begin, int k) {
        k -= 1;
        while (k-- && begin) {
            begin = begin->next;
            // k--;
        }
        return begin;
    }

    ListNode* reverseLL(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        /*
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
        */

        ListNode* temp = head;
        ListNode* kth_node = nullptr;
        ListNode* prev = nullptr;
        // ListNode* next = nullptr;

        while (temp) {

            kth_node = findKth(temp, k);
            
            if (kth_node == NULL) {

                if (prev)
                    prev->next = temp;
                
                break;
            }
            
            // Break the section of the list
            ListNode* next = kth_node->next;
            kth_node->next = nullptr;
            reverseLL(temp);

            // Reassign head for the first iteration.
            if (temp == head) {
                head = kth_node;
            } else {
                prev->next = kth_node;
            }

            prev = temp;
            temp = next;
        }
        return head;
    }
};