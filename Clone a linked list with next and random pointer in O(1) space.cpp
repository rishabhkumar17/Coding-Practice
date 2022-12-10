/*
class Node {
    public:
	int val;
    Node* next;
    Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

using namespace std;

class CopyLinkedListWithRandomPointer {
public:
	Node* copyLinkedListWithRandomPointer(Node* head) {
        Node *curr = head, *temp;

        while(curr) {
            temp = curr -> next;
            curr -> next = new Node();
            curr -> next -> val = curr -> val;
            curr -> next -> next = temp;
            curr = temp;
        }
        curr = head;

        while(curr) {
            if(curr -> next) {
                curr -> next -> random = curr -> random ? curr -> random -> next : curr -> random;
            }
            curr = curr-> next ? curr -> next -> next : curr -> next;
        }
        
        Node *original = head, *copy = head -> next;
        temp = copy;

        while(original && copy) {
            original -> next = original -> next ? original -> next -> next : original -> next;

            copy -> next = copy -> next ? copy -> next -> next : copy -> next;
            original = original -> next;
            copy = copy -> next;
        }

        return temp;
	}
};
