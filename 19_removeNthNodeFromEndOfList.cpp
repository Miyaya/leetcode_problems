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

    // ListNode *removeNthFromEnd(ListNode *head, int &n)
    // {
    //     if (!head)
    //     {
    //         return head;
    //     }
    //     ListNode *ret = removeNthFromEnd(head->next, n);
    //     if ((--n) == 0)
    //     {
    //         return ret;
    //     }
    //     head->next = ret;
    //     return head;
    // }

    // e.g.
    // r1 ([1,2,3,4,5], n=2) -> return [1,2,3,5] (n==-3)
    // r2 ([2,3,4,5], n=2) -> return [2,3,5] (n==-2)
    // r3 ([3,4,5], n=2) -> return [3,5] (n==-1)
    // r4 ([4,5], n=2) -> return [5] (n==0)
    // r5 ([5], n=2) -> return [5] (n==1)
    // r6 ([], n=2) -> return nullptr (n==2)
};