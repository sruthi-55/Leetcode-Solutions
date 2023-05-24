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
    ListNode* reverseList(ListNode* head) {
        return helper(NULL,head);
    }
    ListNode* helper(ListNode* prev, ListNode* cur){
        if(!cur)    return prev;
        ListNode* head=helper(cur,cur->next);
        cur->next=prev;
        return head;
    }
};