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
    void insertionSort(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            int j = i - 1;
            int key = arr[i];
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        vector<int>arr;
        ListNode* temp = head;
        while(temp){
            int data = temp->val;
            arr.push_back(data);
            temp=temp->next;
        }
        insertionSort(arr);
        ListNode* a = new ListNode(arr[0]);
        ListNode *tail = a;
        for(int i=1;i< arr.size();i++){
            ListNode * curr = new ListNode(arr[i]); 
            tail->next = curr;
            tail = curr;
        }
        return a;
    }
};