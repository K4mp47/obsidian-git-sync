let BaseBankAccount = {
	amount: 0,
	owner: "none",
	add: function(incr) {
		this.amount = this.amount + incr;
	}
};

/*
let BankAccount = function( amount, owner ){
	if(amount !== undefined)
		this.amount = amount;
	if(owner !== undefined)
		this.owner = owner;
}
*/

/*
let BankAccount = function( accountConfig ){
	if(accountConfig.amount !== undefined)
		this.amount = accountConfig.amount;
	if(accountConfig.owner !== undefined)
		this.owner = accountConfig.owner;
}
*/

let BankAccount = function(firstParam, owner) {
	if (typeof firstParam === "object") {
		if (firstParam.amount !== undefined)
			this.amount = firstParam.amount;
		if (firstParam.owner !== undefined)
			this.owner = firstParam.owner;
	} else {
		if (firstParam !== undefined)
			this.amount = firstParam;
		if (owner !== undefined)
			this.owner = owner;
	}
}

// Alberto Campagnolo 6 marzo 2025
// trasformo l'oggetto sopra in una classe che poi posso mettere ovunque
class BankAccountClass {
	constructor(firstParam, owner) {
		if (typeof firstParam === "object") {
			if (firstParam.amount !== undefined)
				this.amount = firstParam.amount;
			if (firstParam.owner !== undefined)
				this.owner = firstParam.owner;
		} else {
			if (firstParam !== undefined)
				this.amount = firstParam;
			if (owner !== undefined)
				this.owner = owner;
		}
	}
}

// BankAccount = new BankAccountClass();

BankAccount.prototype = BaseBankAccount;
//BankAccount.prototype = { amount: 0, owner: "none" };

let AlternateNameForBankAccount = BankAccount;

let myAccount = new BankAccount({ owner: "pluto" });
let myAccount2 = new BankAccount(100, "pippo");

let v1 = myAccount.amount;

//BaseBankAccount.amount = 10000;

let v2 = myAccount.amount;
myAccount.owner = "paperino";

myAccount.add(20);
myAccount2.add(30);

console.log(myAccount, myAccount2);

function reducer() {
	return [...arguments].reduce((a, b) => a + b, 0);
}

console.log(reducer(1))
