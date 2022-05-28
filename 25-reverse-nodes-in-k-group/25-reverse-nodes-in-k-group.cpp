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
    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode* prev=b, *nextp;
        while(a!=b){
            nextp=a->next;
            a->next=prev;
            prev=a;
            a=nextp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp)
                return head;
            temp=temp->next;
        }
        ListNode* new_head=reverse(head, temp);
        head->next=reverseKGroup(temp, k);
        return new_head;
    }
};