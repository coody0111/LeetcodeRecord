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
    ListNode* partition(ListNode* head, int x) {
        ListNode * dummy1 = new ListNode(0);
        ListNode * cur1 = dummy1;
        ListNode * dummy2 = new ListNode(0);
        ListNode * cur2 = dummy2;
        while(head){
            ListNode *temp = new ListNode(head->val);
            if ( head-> val <x ){
                cur1 -> next = temp;
                cur1 = cur1 -> next;
            }else{
                cur2 -> next =temp;
                cur2 = cur2 -> next;
            }
            head = head -> next;
        }
        cur1 -> next = dummy2 -> next;
        return dummy1 -> next;
    }

};