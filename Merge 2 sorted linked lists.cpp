ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
}

/////////////////////

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* result = NULL; 
     
    if (l1 == NULL) 
        return(l2); 
    else if (l2 == NULL) 
        return(l1); 
     
 
    if (l1->val <= l2->val) 
    { 
        result = l1; 
        result->next = mergeTwoLists(l1->next, l2); 
    } 
    else
    { 
        result = l2; 
        result->next = mergeTwoLists(l1, l2->next); 
    } 
    return(result); 
    }