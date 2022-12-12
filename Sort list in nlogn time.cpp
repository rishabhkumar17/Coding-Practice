/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode* next;
 *   ListNode(int x) { val = x, next(NULL)}
 * }
 */

class SortList {
  public:
    // TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    // Your implementation goes here

    ListNode* sortList(ListNode* head) {
      vector<int> arr;
      ListNode * curr = head;
      while(curr != NULL) {
        arr.push_back(curr -> val);
        curr = curr -> next;
      }
      sort(arr.begin(), arr.end());
      curr = head;
      int i = 0;
      while(curr != NULL) {
        curr -> val = arr[i];
        i++;
        curr = curr -> next;
      }

      return head;

    }
};
