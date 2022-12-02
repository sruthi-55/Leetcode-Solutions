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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans;
        ListNode* prev = nullptr;
        if(head==NULL || head->next==NULL) return head;
        while(head != nullptr && head->next != nullptr) {
            ListNode *first = head;
            ListNode *second = head->next;
            head = head->next->next;
            if(prev == nullptr) {
                ans = second;
            }
            else {
                prev->next = second;                
            }
            second->next = first;
            prev = first;
        }
        //doubt 
            prev->next = head;            
        
        return ans;
        
    }
};