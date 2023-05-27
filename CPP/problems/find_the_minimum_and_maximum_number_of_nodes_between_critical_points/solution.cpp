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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head;
        head=head->next;
        int i=1,prevI=-1,firstI=-1;
        int mini=INT_MAX;
        while(head->next){
            if( (prev->val < head->val && head->val > head->next->val) 
                || (prev->val > head->val && head->val < head->next->val)){
                if(prevI!=-1) 
                    mini=min(mini,i-prevI);
                if(firstI == -1) firstI=i;
                prevI=i;
            }
            prev=head;
            head=head->next;
            i++;
        }
        if(mini==INT_MAX) return {-1,-1};
        return {mini,prevI-firstI };
    }
};