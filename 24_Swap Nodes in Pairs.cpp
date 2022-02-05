class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newLN = head->next;
        ListNode *nextLN = newLN->next;
        newLN->next = head;
        head->next = swapPairs(nextLN);
        return newLN;
    }
};