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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)   return;
        stack<ListNode*> stack;
        ListNode *ptr=head;
        int size=0;
        while(ptr!=NULL){
            stack.push(ptr);
            ptr=ptr->next;
            size++;
        }
        ListNode* ptr1=head;
        for(int i=0;i<size/2;i++){
            ListNode* ele=stack.top();
            stack.pop();
            ele->next=ptr1->next;
            ptr1->next=ele;
            ptr1=ptr1->next->next;
        }
        ptr1->next=NULL;
    }
};