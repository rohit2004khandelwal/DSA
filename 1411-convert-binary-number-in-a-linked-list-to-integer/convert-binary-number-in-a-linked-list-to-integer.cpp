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
            ListNode* prev=NULL;
            ListNode* curr=head;
            while(curr!=NULL){
                ListNode* forward=curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head = reverseList(head);
        int result = 0;
        int power = 0;
        while(head){
            if(head->val == 1){
                result += pow(2, power);
            }
            power++;
            head=head->next;
        }
        return result;
    }
};