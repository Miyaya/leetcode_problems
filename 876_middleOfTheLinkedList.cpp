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
    ListNode *middleNode(ListNode *head)
    {
        int counter = 0;
        ListNode *newHead = head;
        while (head->next != nullptr)
        {
            counter += 1;
            head = head->next;
        }
        counter = (counter + 1) / 2;
        while (counter--)
        {
            newHead = newHead->next;
        }
        return newHead;
    }
};