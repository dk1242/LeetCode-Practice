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
    ListNode *start;
    int size=0;
    Solution(ListNode* head) {
        start = head;
        ListNode *curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
    }
    
    int getRandom() {
        ListNode *curr=start;
        // int len=size;
        // cout<<start->val;
        int l=rand()%size;
        while(l--){
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */