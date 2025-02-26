function createRow(nameText,ingredientsText,priceText,total)
{
  var name = document.createElement("td");
  name.innerHTML = nameText;
  name.addEventListener("mouseover",function(){name.innerHTML = ingredientsText;}); 
  name.addEventListener("mouseout",function(){name.innerHTML = nameText;});

  var price = document.createElement("td");
  price.innerHTML = priceText;
  price.addEventListener("click",function(){total.innerHTML = parseFloat(priceText)+parseFloat(total.innerHTML);}); 

  var row = document.createElement("tr");
  row.appendChild(name);
  row.appendChild(price);	
  return row;
}

var menus = document.getElementsByClassName("menu");

while(menus.length>0){
	
  var menu = menus[0];
  var table = document.createElement("table");
  var total = document.createElement("div");
  total.innerHTML = "0";
  menu.parentNode.insertBefore(table,menu);
  menu.parentNode.insertBefore(total,menu);
  menu.parentNode.removeChild(menu);
  
  var divs = menu.getElementsByTagName("div");
  while(divs.length>0){	
	var blocks = divs[0].textContent.split(";");
	table.appendChild(createRow(blocks[0],blocks[1],blocks[2],total));
    menu.removeChild(divs[0]);             
  }
}