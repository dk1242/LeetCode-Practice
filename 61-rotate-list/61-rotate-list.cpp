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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head, *last;
        while(temp){
            if(temp->next==NULL){
                last=temp;
            }
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0||len==0 || len == 1){
            return head;
        }
        temp=head;
        for(int i=0;i<len-k-1;i++){
            temp=temp->next;
        }
        ListNode* temp2=temp->next;
        temp->next=NULL;
        last->next=head;
        return temp2;
    }
};