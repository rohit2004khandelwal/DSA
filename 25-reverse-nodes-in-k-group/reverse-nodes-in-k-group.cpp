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
    int getlength(ListNode* &head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        int position = 0;
        int len=getlength(head);
        if(len<k){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(position < k){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        if(curr!=NULL){
            ListNode* recursionhead = reverseKGroup(curr , k);
            head->next = recursionhead;
        }
        return prev;
    }
};