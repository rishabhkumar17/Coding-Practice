Node* copyLinkedListWithRandomPointer(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *curr, *newHead;

        curr = head;
        newHead = new Node();
        newHead -> val = curr -> val;
        mp[curr] = newHead;

        while(curr -> next != NULL) {
            newHead -> next = new Node();
            newHead -> next -> val = curr -> next -> val;
            curr = curr -> next;
            newHead = newHead -> next;
            mp[curr] = newHead;   
        } 
        curr = head;
        while(curr != NULL) {
            mp[curr] -> random = mp[curr -> random];
            curr = curr -> next;
        }

        return mp[head];
	}