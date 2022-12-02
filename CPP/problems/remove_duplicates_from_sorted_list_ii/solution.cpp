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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;

    if (head==NULL) return 0;
    if (head->next==NULL) return head;
        if (head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        } 
        else {
            while (head->next && head->next->val == head->val) 
                head->next = head->next->next;
            return deleteDuplicates(head->next);
        }
    }
};