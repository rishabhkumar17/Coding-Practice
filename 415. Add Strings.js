/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
  if (num2.length > num1.length) return addStrings(num2, num1);
  let i = num1.length - 1;
  let j = num2.length - 1;

  let output = '';
  let carry = 0;

  while (i >= 0) {
    const digit1 = num1.charAt(i) - '0';
    const digit2 = j < 0 ? 0 : num2.charAt(j) - '0';

    let sum = carry + digit1 + digit2;
    carry = 0;
    if (sum >= 10) {
      carry = 1;
      sum %= 10;
    }
    output = `${sum.toString()}${output}`;
    i--;
    j--;
  }
  if (carry > 0) output = `${carry.toString()}${output}`;

  return output;
};
