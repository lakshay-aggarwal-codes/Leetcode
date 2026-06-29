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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            int v = temp->val;
            arr.push_back(v);
            temp = temp->next;
        }
        int n = arr.size();
        int i = 0;
        while (i < n - 1) {
            swap(arr[i], arr[i + 1]);
            i += 2;
        }
        head = new ListNode(arr[0]);
        ListNode* curr = head ;
        int j = 1;
        while (j < n) {
            curr->next = new ListNode(arr[j]);
            curr = curr->next;
            j++;
        }
        return head;
    }
};