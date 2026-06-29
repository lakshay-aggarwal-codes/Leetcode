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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        vector<int>arr1;
        ListNode* temp = head;
        while(temp){
            arr1.push_back(temp->val);
            temp = temp -> next;
        }
        vector<int>arr2;
        int n = arr1.size();
        int j=0;
        for(int i =0;i<n;i++){
            if(arr1[i] < x){
                arr2.push_back(arr1[i]);j++;
            }
        } 
        for(int i = 0;i< n;i++){
            if(arr1[i] >=x){
                arr2.push_back(arr1[i]);
            }
        }
         head = new ListNode(arr2[0]);
        ListNode* curr= head;
        for(int i = 1; i< arr2.size();i++){
            curr->next = new ListNode(arr2[i]);
            curr=curr->next;
        }
        return head;
    }
};