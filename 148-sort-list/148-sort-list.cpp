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
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *l=new ListNode(), *p=l;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                p->next=l1;
                l1=l1->next;
            }else{
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if(l1)
            p->next=l1;
        if(l2)
            p->next=l2;
        return l->next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode *l1, *l2;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *slow=head, *prev, *fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        l1=sortList(head);
        l2=sortList(slow);
        return merge(l1, l2);
    }
};