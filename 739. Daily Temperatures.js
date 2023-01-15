var dailyTemperatures = function (temperatures) {
  let stack = [];
  let result = new Array(temperatures.length).fill(0);

  for (let i = 0; i < temperatures.length; i++) {
    while (
      stack.length &&
      temperatures[i] > temperatures[stack[stack.length - 1]]
    ) {
      let temp = stack.pop();
      result[temp] = i - temp;
    }
    stack.push(i);
  }
  return result;
};
