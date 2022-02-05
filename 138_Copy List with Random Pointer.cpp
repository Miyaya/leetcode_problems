class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *res = new Node(head->val);
        unordered_map<Node *, Node *> addrs; // addrs[old_addr]=new_addr;

        Node *new_head = res;
        Node *orig_head = head;
        addrs[orig_head] = new_head;

        // deep copy: next, val
        while (orig_head->next != NULL)
        {

            new_head->next = new Node(orig_head->next->val);
            addrs[orig_head->next] = new_head->next;

            orig_head = orig_head->next;
            new_head = new_head->next;
        }

        new_head = res;
        orig_head = head;

        // deep copy: random
        while (new_head != NULL)
        {
            new_head->random = addrs[orig_head->random];

            new_head = new_head->next;
            orig_head = orig_head->next;
        }

        return res;
    }
};