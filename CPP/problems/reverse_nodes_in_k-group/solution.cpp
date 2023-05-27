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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after=head;
        ListNode *prev=NULL, *cur=NULL;
        while(true){
            ListNode *end=after;
            for(int i=0;i<k;i++){
                if(!end)    return dummy->next;
                end=end->next;
            }
            cur=after;
            prev=before;
            for(int i=0;i<k;i++){
                ListNode *next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            after->next=cur;
            before->next=prev;
            before=after;
            after=cur;
        }
    }
};