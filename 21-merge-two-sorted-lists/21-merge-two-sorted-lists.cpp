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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* t1;
        if(l1==NULL && l2==NULL)
            return l1;
        else if(l2==NULL){
            head=l1;
            return head;
        }else if(l1==NULL){
            head=l2;
            return head;
        }else{
            if(l1->val<=l2->val){
            head=l1;
            t1=l1;
            l1=l1->next;
        }else {
            head=l2;
            t1=l2;
            l2=l2->next;
        }
        
        while(l1 && l2){
            if(l2->val<l1->val){
                t1->next=l2;
                t1=l2;
                l2=l2->next;
            }else{
                t1->next=l1;
                t1=l1;
                l1=l1->next;
            }
        }
        if(l1){
            t1->next=l1;
        }
        if(l2){
            t1->next=l2;
        }
        }
        
        return head;
    }
};