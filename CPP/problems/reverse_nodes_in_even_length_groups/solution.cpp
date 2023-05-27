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
        if(!head)   return head;
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* prev = dummy;
        
        for(int len = 1; len < 1e5 && head; len++) {
            ListNode* tail = head;
            ListNode* nextHead;
            
            int j = 1;
            while(j < len && tail && tail -> next) {
                tail = tail -> next;
                j++;
            }
            nextHead = tail -> next;
            
            if((j % 2) == 0) {
                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            } else {
                prev = tail;
                head = nextHead;
            }
        }
        return dummy -> next;
    }
};