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
class Solution
{
public:
    void reorderList(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        // if(!head || !head->next || !head->next->next) return;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse
        ListNode *pre = NULL;
        ListNode *curr = slow->next;
        slow->next = NULL;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }

        // Merge two List;
        ListNode *t1, *t2;
        while (head != nullptr && pre != nullptr)
        {
            t1 = head->next;
            t2 = pre->next;
            head->next = pre;
            pre->next = t1;
            head = t1;
            pre = t2;
        }
    }
};
