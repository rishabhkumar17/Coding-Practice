ListNode* partition(ListNode* head , int x) {
    ListNode *smallHead = NULL, *smallTail = NULL;
    ListNode *equalHead = NULL, *equalTail = NULL;
    ListNode *greatHead = NULL, *greatTail = NULL;

    while(head != NULL) {

        if(head -> val < x) {
            if(smallHead == NULL) {
                smallHead = smallTail = head;
            }
            else {
                smallTail -> next = head;
                smallTail = smallTail -> next;
            }
        }

        else if(head -> val == x) {
            if(equalHead == NULL) {
                equalHead = equalTail = head;
            }
            else {
                equalTail -> next = head;
                equalTail = equalTail -> next;
            }
        }

        else if(head -> val > x) {
            if(greatHead == NULL) {
                greatHead = greatTail = head;
            }
            else {
                greatTail -> next = head;
                greatTail = greatTail -> next;
            }
        }
        head = head -> next;
    }

    if(greatTail != NULL) {
        greatTail -> next = NULL;
    } 

    if(smallHead == NULL) {
        if(equalHead == NULL) {
            return greatHead;
        }
        equalTail -> next = greatHead;
        return equalHead;
    }

    if(equalHead == NULL) {
        smallTail -> next = greatHead;
        return smallHead;
    }

    smallTail -> next = equalHead;
    equalTail -> next = greatHead;
    return smallHead;
}