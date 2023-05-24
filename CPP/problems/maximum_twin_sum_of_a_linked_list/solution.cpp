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
    int pairSum(ListNode* head) {
        int maxi=0;
        ListNode *slow=head,*fast=head;
        //get middle. slow points to middle
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        //reverse second half
        ListNode *nextNode,*prev= NULL;
        while(slow){
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        //prev points to head of second half
        ListNode* start=head;
        while(prev){
            maxi=max(maxi,start->val+prev->val);
            prev=prev->next;
            start=start->next;
        }
        return maxi;
    }
};