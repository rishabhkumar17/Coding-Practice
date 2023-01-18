//iterative solution
var reverseList = function (head) {
  let prev = null;
  let curr = head;
  let next = null;

  while (curr !== null) {
    next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
};

//recursive solution
var reverseList = function (head) {
  if (head == null || head.next == null) return head;

  let reversedHead = reverseList(head.next);
  head.next.next = head;
  head.next = null;

  return reversedHead;
};
