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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        int i=0,j=0;
        int l=0,t=0,r=n-1,b=m-1;
        while(head){
            mat[i][j]=head->val;
            head=head->next;
            if(i==t && j<r){
                j++;    if(j==r)  t++;
            }
            else if(j==r && i<b){
                i++;    if(i==b)    r--;
            }
            else if(i==b && j>l){
                j--;    if(j==l)    b--;
            }
            else if(j==l && i>t){
                i--;    if(i==t)    l++;
            }
        }
        return mat;
    }
};