var middleNode = function (head) {
  let first = head;
  let second = head;
  while (second && second.next) {
    first = first.next;
    second = second.next.next;
  }
  return first;
};
