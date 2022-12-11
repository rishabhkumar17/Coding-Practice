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


ListNode* sumLists2(ListNode* head1 , ListNode* head2) {
	stack<int> s1, s2;
	while(head1 != NULL) {
		s1.push(head1 -> val);
		head1 = head1 -> next;
	}
	while(head2 != NULL) {
		s2.push(head2 -> val);
		head2 = head2 -> next;
	}
	int carry = 0;
	ListNode *result = NULL;
	while(s1.empty() == false || s2.empty() == false) {
		int a=0, b=0;
		if(s1.empty() == false) {
			a = s1.top(); 
			s1.pop();
		}
		if(s2.empty() == false) {
			b = s2.top(); 
			s2.pop();
		}
		int total = a + b + carry;
		ListNode *temp = new ListNode(total % 10);
		carry = total/10;
		if(result == NULL) {
			result = temp;
		} else {
			temp -> next = result;
			result = temp;
		}
	}
	if(carry != 0) {
		ListNode *temp = new ListNode(carry);
		temp -> next = result;
		result = temp;
	}
	return result;
}