function make2DArray(cols, rows){
  var arr = new Array(cols);
  for (var i = 0; i < arr.length; i++){
    arr[i] = new Array(rows);
    for(var j = 0; j < arr[i].length; j++){
      arr[i][j] = 0;
    }
  }
  return arr;
}

let hueValue = 1;
let w = 10;

function reset() {
  for (var i = 0; i < cols; i++){
    for (var j = 0; j < rows; j++){
      grid[i][j] = 0;
    }
  }
}

function mouseDragged(){ // what happens when you drag inside the canvas
  let col = floor(mouseX / w);
  let row = floor(mouseY / w);

  let matrix = 3;
  let extra = floor(matrix/2);
  for(let i = -extra; i <= extra; i++){
    for(let j = -extra; j <= extra; j++){
      if(col + i >= 0 && col + i <= cols-1 && row + j >= 0 && row + j <= rows-1){ // check if mouse is inside the canvas
        if(grid[col+i][row+j] === 0)
          grid[col+i][row+j] = hueValue;
      }
    }
  }
  hueValue += 0.2;
  if(hueValue > 360){
    hueValue = 1;
  }
}

function setup(){ // setting up the canvas to draw on
  let canvas = createCanvas(800, 600);
  canvas.parent('main-container');
  colorMode(HSB, 255, 360, 100);
  cols = width / (w);
  rows = height / (w);

  grid = make2DArray(cols, rows);
  for (var i = 0; i < cols; i++){
    for (var j = 0; j < rows; j++){
      grid[i][j] = 0;
    }
  }
}

function draw(){ // actual painting of the canvas
  background('rgba(5, 5, 5, 1)');

  for(let i = 0; i < cols; i++){
    for(let j = 0; j < rows; j++){
      let x = i * w;
      let y = j * w;
      noStroke(); // print border
      if(grid[i][j] > 0){
        fill(grid[i][j], 255, 255); // print square to black 
        square(x, y, w);
      }
    }
  }

  let next = make2DArray(cols, rows);
  for(let i = 0; i < cols; i++){
    for(let j = 0; j < rows; j++){
      let state = grid[i][j];
      if (state > 0){
        let below = grid[i][j+1];

        let dir = 1; // direction of the sand chosen randomly
        if(random(1) < 0.5){
          dir *= -1;
        }

        let belowRight, belowLeft;
        if(i + dir >= 0 && i + dir <= cols-1)
          belowRight = grid[i+dir][j+1];

        if(i - dir >= 0 && i - dir <= cols-1)
          belowLeft = grid[i-dir][j+1];
        // check if the sand should fall down, right or left
        if(below === 0){
          next[i][j+1] = state;
        } else if(belowRight === 0){
          next[i+dir][j+1] = state;
        } else if(belowLeft === 0){
          next[i-dir][j+1] = state; 
        } else {
          next[i][j] = state;
        }
      }
    }
  }

  grid = next; // update the grid at the new state
}
