#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/*
Definition for ListNode
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
*/
ListNode *deleteKthToLast(ListNode *head, int k)
{
    ListNode *curr = head;
    int count = -k;
    while (curr->next != NULL)
    {
        curr = curr->next;
        count++;
    }
    if (count == -1)
    {
        ListNode *temp = new ListNode();
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    ListNode *new_curr = head;
    int node = 0;
    do
    {
        if (node == count)
        {
            ListNode *temp = new ListNode();
            temp = new_curr->next;
            new_curr->next = new_curr->next->next;
            free(temp);
            return head;
        }
        new_curr = new_curr->next;
        node++;
    } while (new_curr->next != NULL);
}