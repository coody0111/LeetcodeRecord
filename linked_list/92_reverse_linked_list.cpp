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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * pre = dummy;
        
        // find the start point 
        for (int i = 1 ; i < left; i++){
            pre = pre -> next;
        }

        ListNode* cur = pre->next;
        // reverse the list 
        for(int i = left ; i < right; i++){
            ListNode* temp = cur->next;
            cur -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
        }
        return dummy -> next;

        
    }
};