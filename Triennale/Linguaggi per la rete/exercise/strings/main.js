string = 'Gustosa;pomodoro, mozzarella, salame piccante, ricotta;7.00';

console.log(string)

pizza_name = string.split(';')[0];
pizza_price = string.split(';').at(-1);

console.log(pizza_name)
console.log(pizza_price)
