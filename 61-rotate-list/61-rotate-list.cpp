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
        ListNode*temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k=k%len;
        while(k--){
            temp=head;
            while(temp->next->next){
                temp=temp->next;
            }
            // cout<<temp->val;
            temp->next->next=head;
            head=temp->next;
            temp->next=NULL;
        }
        return head;
    }
};