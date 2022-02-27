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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode(0);
        ListNode *fast=start, *slow=start;
        slow->next=head;
        // cout<<slow->val<<" "<<fast->val<<" "<<head->val;
        for(int i=1;i<=n;i++){
            cout<<fast->val<<" ";
            fast=fast->next;
        }
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        // ListNode *temp=slow->next;
        if(slow && slow->next)
        slow->next=slow->next->next;
        
        // delete(temp);
        return start->next;
    }
};