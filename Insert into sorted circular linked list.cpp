ListNode *insertIntoSortedCircularList(ListNode *head, int insertVal)
{
    if (head == NULL)
    {
        ListNode *new_node = new ListNode();
        new_node->val = insertVal;
        new_node->next = new_node;
        return new_node;
    }
    ListNode *prev = head;
    ListNode *curr = head->next;
    if (curr == NULL)
    {
        ListNode *new_node = new ListNode();
        new_node->val = insertVal;
        new_node->next = prev;
        prev->next = new_node;
        return head;
    }

    do
    {
        if ((insertVal >= prev->val && insertVal <= curr->val) ||
            ((prev->val > curr->val) && (insertVal >= prev->val || insertVal <= curr->val)))
        {
            ListNode *new_node = new ListNode();
            new_node->val = insertVal;
            new_node->next = curr;
            prev->next = new_node;
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (prev != head);

    ListNode *new_node = new ListNode();
    new_node->val = insertVal;
    new_node->next = curr;
    prev->next = new_node;
    return head;
}