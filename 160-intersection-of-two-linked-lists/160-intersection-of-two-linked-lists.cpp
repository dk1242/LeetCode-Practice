/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first=headA, *second=headB;
        while(first->next && second->next){
            first=first->next;
            second=second->next;
        }
        if(second->next){
            ListNode* start=headB;
            while(second->next){
                if(second==first){
                    break;
                }
                second=second->next;
                start=start->next;
            }
            first=headA;
            while(first!=start){
                start=start->next;
                first=first->next;
            }
            return start;
        }else{
            ListNode* start=headA;
            while(first->next){
                if(second==first){
                    break;
                }
                first=first->next;
                start=start->next;
            }
            first=headB;
            while(first!=start){
                start=start->next;
                first=first->next;
            }
            return start;
        }
    }
};