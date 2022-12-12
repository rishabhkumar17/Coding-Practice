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

class LinkedListCycle {
public:
    string linkedListCycle(ListNode* head) {
        ListNode *p1 = head, *p2 = head;

        while(p1 != NULL && p2 != NULL && p2 -> next != NULL) {
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
            if(p1 == p2) {
                return "true";
            }
        }

        return "false";
    }
};