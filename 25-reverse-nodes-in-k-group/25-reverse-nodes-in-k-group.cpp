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
    // ListNode* reverse(ListNode* a, ListNode* b){
    //     ListNode* prev=b, *nextp;
    //     while(a!=b){
    //         nextp=a->next;
    //         a->next=prev;
    //         prev=a;
    //         a=nextp;
    //     }
    //     return prev;
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head=NULL, *prev=NULL, *curr=head, *temp, *lastcurr, *lastprev, *nex;
        while(curr){
            temp=curr;
            for(int i=0;i<k;i++){
                if(!temp)
                    return new_head;
                temp=temp->next;
            }
            lastcurr=curr, lastprev=prev;
            for(int i=0;i<k;i++){
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
            }
            if(lastprev){
                lastprev->next=prev;
            }else{
                new_head=prev;
            }
            lastcurr->next=curr;
            prev=lastcurr;
        }
        return new_head;
    }
};