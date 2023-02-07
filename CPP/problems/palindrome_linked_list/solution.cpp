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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *prev,*temp;
        //moving slow to the middle of LL
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reversing the second half
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp; 
        
        //comparing two halves
        fast = head, slow = prev;
        while (slow){
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        }
        return true;
    }
};