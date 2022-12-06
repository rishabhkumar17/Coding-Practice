/*
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
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

ListNode *moveMiddleToHead(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *curr = head, *last = head;
    ListNode *prev = NULL;

    while (last != NULL && last->next != NULL)
    {
        prev = curr;
        last = last->next->next;
        curr = curr->next;
    }
    prev->next = prev->next->next;
    curr->next = head;
    head = curr;
    return head;
}