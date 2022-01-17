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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int counter = 1;
        ListNode *newHead = head;
        ListNode *res = head;
        while (head->next != nullptr)
        {
            counter += 1;
            head = head->next;
        }
        counter -= (n + 1);
        if (counter < 0)
            return newHead->next;
        while (counter > 0)
        {
            newHead = newHead->next;
            counter -= 1;
        }
        if (newHead->next != nullptr)
            newHead->next = newHead->next->next;

        return res;
    }
};