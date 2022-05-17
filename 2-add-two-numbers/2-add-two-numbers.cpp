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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode();
        ListNode* temp=res;
        int sum=0, carry=0;
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            
            if(sum>=10){
                temp->next=new ListNode(sum%10);
                temp=temp->next;
                carry=sum/10;
            }
            else {
                temp->next=new ListNode(sum);
                temp=temp->next;
                carry=0;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1 && carry){
                sum=l1->val+carry;
                if(sum>=10){
                    temp->next=new ListNode(sum%10);
                    temp=temp->next;
                    carry=sum/10;
                }else{
                    temp->next=new ListNode(sum);
                    temp=temp->next;
                    carry=0;
                }
                l1=l1->next;
            }
            if(l1)temp->next=l1;
            if(carry){
                temp->next=new ListNode(carry);
            }
        }else if(l2){
            while(l2 && carry){
                sum=l2->val+carry;
                if(sum>=10){
                    temp->next=new ListNode(sum%10);
                    temp=temp->next;
                    carry=sum/10;
                }else{
                    temp->next=new ListNode(sum);
                    temp=temp->next;
                    carry=0;
                }
                l2=l2->next;
            }
            if(l2)temp->next=l2;
            if(carry){
                temp->next=new ListNode(carry);
            }
        }else if(carry){
            temp->next=new ListNode(carry);
        }
        
        return res->next;
    }
};