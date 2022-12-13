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
bool isCycle(ListNode *&p1, ListNode *&p2) {
    while(p1 != NULL && p2 != NULL && p2 -> next != NULL) {
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
        if(p1 == p2) {
            return true;
        }
    }
    return false; 
}

bool detectAndRemoveCycle(ListNode* head){
    ListNode *p1 = head, *p2 = head;
    bool cycle = isCycle(p1, p2);
    if(cycle == false) {
        return false;
    }
    p1 = head;
    if (p1 == p2) {            
        while (p2->next != p1) p2 = p2->next;        
        p2->next = NULL;
        return true;    
    }
    while(1) {
        if(p1 -> next == p2 -> next) {
            p2 -> next = NULL;
            return true;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
}
