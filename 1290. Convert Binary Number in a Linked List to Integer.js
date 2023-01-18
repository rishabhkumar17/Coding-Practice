var getDecimalValue = function (head) {
  let res = 0;
  let node = head;
  while (node) {
    res = res * 2 + node.val;
    node = node.next;
  }
  return res;
};
