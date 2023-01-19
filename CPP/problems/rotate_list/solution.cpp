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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return head;
        int len=1;
        ListNode *tail,*newH;
        tail=newH=head;
        //to find length of LL
        while(tail->next){
            tail=tail->next;
            len++;
        }
        tail->next=head;       //circle the LL
        k=k%len;
        for(int i=0;i<len-k;i++){
            tail=tail->next;    //set the tail node to n-kth node from head
        }
        newH=tail->next;
        tail->next=NULL;
        return newH;
    }
};