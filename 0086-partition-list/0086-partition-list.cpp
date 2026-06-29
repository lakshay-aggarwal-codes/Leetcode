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
        if (!head)
            return NULL;

        ListNode largeDummy(0);
        ListNode smallDummy(0);
        ListNode* large = &largeDummy;
        ListNode* small = &smallDummy;

        ListNode* temp = head;

        while (temp) {
            ListNode* nextNode = temp->next;
            temp->next=NULL;
            if (temp->val >= x) {
                large->next = temp;
                large = large->next;
            }
            else{
                small->next = temp;
                small = small->next;
            }
            temp = nextNode;
        } 
        small->next=largeDummy.next;
        return smallDummy.next;
    }
};