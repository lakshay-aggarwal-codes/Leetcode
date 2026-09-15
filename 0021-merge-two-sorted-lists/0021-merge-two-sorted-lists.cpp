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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> temp;
        ListNode* x = list1;
        ListNode* y = list2;
        while (x) {
            int a = x->val;
            temp.push_back(a);
            x = x->next;
        };
        while (y) {
            int a = y->val;
            temp.push_back(a);
            y = y->next;
        };
        sort(temp.begin(), temp.end());
        ListNode* head = nullptr;
        ListNode* tail = head;
        for (int i = 0; i < temp.size(); i++) {
            ListNode* curr = new ListNode(temp[i]);
            if (head == nullptr) {
                head = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }
        return head;
    }
};