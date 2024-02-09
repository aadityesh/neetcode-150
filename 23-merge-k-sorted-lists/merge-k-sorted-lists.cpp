class Solution {
public:
    // Optimal - Priority Queue

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        for (auto i : lists) {
            if (i != NULL)
                pq.push({i->val, i});
        }

        while (!pq.empty()) {

            auto it = pq.top();
            int elem = it.first;

            ListNode* curr = new ListNode(elem);
            tail->next = curr;
            tail = curr;

            pq.pop();

            if (it.second->next != NULL) {
                int nextVal = it.second->next->val;
                pq.push({nextVal, it.second->next});
            }
        }

        return dummy->next;
    }

    /*
     vector<int> ans;

     ListNode* mergeLL(ListNode* l1, ListNode* l2) {

         // t.c. -> O(N*k*k)

         if(l1 == NULL)
             return l2;

         if(l2 == NULL)
             return l1;

         ListNode* h1 = l1;
         ListNode* h2 = l2;

         ListNode* res = new ListNode();
         ListNode* tail = res;

         while (h1 && h2) {

             ListNode* curr = new ListNode();
             if (h1->val <= h2->val) {
                 curr->val = h1->val;
                 tail->next = curr;
                 tail = curr;
                 h1 = h1->next;
             } else {
                 curr->val = h2->val;
                 tail->next = curr;
                 tail = curr;
                 h2 = h2->next;
             }
         }

         while (h1) {
             ListNode* curr = new ListNode();
             curr->val = h1->val;
             tail->next = curr;
             tail = curr;
             h1 = h1->next;
         }

         while (h2) {
             ListNode* curr = new ListNode();
             curr->val = h2->val;
             tail->next = curr;
             tail = curr;
             h2 = h2->next;
         }
         cout << "end" << endl;
         return res->next;
     }

     ListNode* mergeKLists(vector<ListNode*>& lists) {

         // Brute - Using an Array
         for (auto i : lists) {        // O(M)
              ListNode* temp = i;
              while (temp != NULL) {
                  ans.push_back(temp->val);
                  temp = temp->next;
              }
          }

          sort(ans.begin(), ans.end()); // O(nlogn)

          ListNode* temp = new ListNode();
          ListNode* tail = temp;

          for (auto i : ans) {          // O(M)
              ListNode* curr = new ListNode(i);
              tail->next = curr;
              tail = curr;
          }

          return temp->next;


     // Better

     int n = lists.size();

     if(n == 0)
         return NULL;

     for (int i = 1; i < n; i++) {
         lists[0] = mergeLL(lists[0], lists[i]);
     }

     return lists[0];

     }
     */
};