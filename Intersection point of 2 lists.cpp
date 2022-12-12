/*
// Definition for ListNode
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
ListNode* listIntersectionPoint(ListNode* head1, ListNode* head2) {
    ListNode *int1 = head1, *int2 = head2;
    int n1=0, n2=0;
    while(int1 != NULL) {
        int1 = int1 -> next;
        n1++;
    }
    while(int2 != NULL) {
        int2 = int2 -> next;
        n2++;
    }
    int1 = head1;
    int2 = head2;
    int n3;

    if(n1 >= n2) {
        n3 = n1 - n2;
        while(n3 != 0) {
            int1 = int1 -> next;
            n3--;
        }
    } else {
        n3 = n2 - n1;
        while(n3 != 0) {
            int2 = int2 -> next;
            n3--;
        }
    }

    while(int1 != NULL || int2 !=NULL) {
        if(int1 == int2) {
            return int1;
        }
        else {
            int1 = int1 -> next;
            int2 = int2 -> next;
        }
    }

    return NULL;
}