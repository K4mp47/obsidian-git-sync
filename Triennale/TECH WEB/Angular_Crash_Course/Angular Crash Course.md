Crash course based on creating a project
Video Link: https://youtu.be/3dHNOWTI7H8?si=MDA9olQiCTTP_jOx

![[Pasted image 20240917091122.png]]
That's is the component that we are going to create (or anyway something like that)

Basic component code:
```js
@Component({
	selector: 'app-hero-list',
	templateUrl: './hero-list.component.html',
	providers: [ HeroService ]
})

export class HeroListComponent implements OnInit {
	...
}
```

---
#### Angular Services
Angular permit to increase modularity and reusability using the services 

---
#### Angular CLI
Command line interface for creating Angular apps
```
$ npm install -g @angular/cli
$ ng new my-app
```

Command to create component, service ecc. are inside it.

---
#### List of Command
```
$ ng serve
$ ng generate component xyz 
$ ng add {dependency}
```

---
#### Project base structure
```
\
|___src
	|___app
		|___app.component.css
		|___app.component.html
		|___app.component.ts
		|___app.component.spec.ts
		|___app.module.ts
index.html
main.ts
style.ts
test.ts
favicon.ico
angular.json
package.json
package-lock.json
```

- As we can see there are a lot of file inside the app folder, that is the main component of our project. everything will pass through it.
- index.html: the single page loaded
- main.ts: entry angular point, which take enviroment, modules, components ecc.
---
#### 1: change app component
- Clean up the app.component.html file
- create a new component using the command:
	- `ng generate component components/header`
- Add the import of the `HeaderComponent` or whatever it is inside the app.component.ts
- change the title variable, cut it from app component and add it to the header component like: `title: string = 'Track Tracker'`

The result should be:
```js
// header.component.ts
import { Component } from '@angular/core';

@Component({
  selector: 'app-header',
  standalone: true,
  imports: [],
  templateUrl: './header.component.html',
  styleUrl: './header.component.css'
})

export class HeaderComponent {
  title: string = 'Task Tracker';

  constructor() {}

  ngOnInit(): void {

  }
}
```

```js
// app.component.ts
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { HeaderComponent } from './components/header/header.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, HeaderComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {}
```

with that, and the html set up, you can see the word task tracker on the browser after `ng serve` on the cli inside the project directory.

---

#### 2: Button component, EventEmitter()
Now the other component to create is a button to add task.
Using `ng generate component components/button` we create a new component, and we will set something particular for that component.

💡The component change during this phase, based on the tutorial steps.

```js
//button.component.ts
import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-button',
  standalone: true,
  imports: [],
  templateUrl: './button.component.html',
  styleUrl: './button.component.css'
})
export class ButtonComponent implements OnInit {
  @Input() text: string = '';
  @Input() color: string = '';

  constructor() { }

  ngOnInit(): void {
  }

}
```

As we can see, there is the `@Input()` tag, that is used to let input variable when the component is used inside the html code:
- an example could be: `<app-button text="Add Task"></app-button>` to change the text variable, that can be displayed inside the button component writing inside `button.component.html` the code: `<h1>{{ text }}</h1>`

Moving to the next part, we add even an `@Output` tag to the component, which permit us to use function `onClick()` inside our code:

```js
//button.component.ts
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-button',
  standalone: true,
  imports: [],
  templateUrl: './button.component.html',
  styleUrl: './button.component.css'
})
export class ButtonComponent implements OnInit {
  @Input() text: string = '';
  @Input() color: string = '';
  @Output() btnClick = new EventEmitter();

  constructor() { }

  ngOnInit(): void {
  }

  onClick() {
    this.btnClick.emit();
  }

}
```

After that, we know that on click, a function will be call, but which and how?
Ez, we create it!
How?
- Inside the `button.component.html` we add `(click)="onClick()"` inside the tag parameters
- Inside the `header.component.html` we add `(btnCklick)=toggleAddTask()` inside the button tag "parameters"
- We create the function inside the header component to be executed!

```js
//button.components.ts
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-button',
  standalone: true,
  imports: [],
  templateUrl: './button.component.html',
  styleUrl: './button.component.css'
})
export class ButtonComponent implements OnInit {
  @Input() text: string = '';
  @Input() color: string = '';
  @Output() btnClick = new EventEmitter();

  constructor() { }

  ngOnInit(): void {
  }

  onClick() {
    this.btnClick.emit();
  }

}
```

```html
<!--button.component.html-->
<button class="btn" (click)="onClick()">{{ text }}</button>
```

```js
//header.component.ts
import { Component } from '@angular/core';
import { ButtonComponent } from '../button/button.component';

@Component({
  selector: 'app-header',
  standalone: true,
  imports: [ ButtonComponent ],
  templateUrl: './header.component.html',
  styleUrl: './header.component.css'
})

export class HeaderComponent {
  title: string = 'Task Tracker';

  constructor() {}

  ngOnInit(): void {}

  toggleAddTask() {
    console.log('toggle');
  }
}

```

```html
<!--header.component.html-->
<app-button class="ml-5" text="Add Task" (btnClick)="toggleAddTask()"></app-button>
```

---

#### 3: Create the task
To give the better experience, we create an interface and a mock-task files to have some task by default and a specified way to represent that task.

```js
// src/app/Task.js
export interface Task {
	id?: number;
	text: string;
	day: string;
	reminder: boolean;
}
```

```js
// src/app/mock-tasks.js
export const TASK: Task[] = [
  {
    id: 1,
    text: 'Doctors Appointment',
    day: 'May 5th at 2:30pm',
    reminder: true,
  },
  {
    id: 2,
    text: 'Meeting at School',
    day: 'May 6th at 1:30pm',
    reminder: true,
  },
  {
    id: 3,
    text: 'Food Shopping',
    day: 'May 7th at 12:30pm',
    reminder: false,
  },
  {
    id: 4,
    text: 'Doctors Appointment',
    day: 'May 8th at 2:30pm',
    reminder: true,
  },
  {
    id: 5,
    text: 'Doctors Appointment',
    day: 'May 9th at 2:30pm',
    reminder: true,
  },
  {
    id: 6,
    text: 'Doctors Appointment',
    day: 'May 10th at 2:30pm',
    reminder: true,
  },
  {
    id: 7,
    text: 'Doctors Appointment',
    day: 'May 11th at 2:30pm',
    reminder: true,
  },
  {
    id: 8,
    text: 'Doctors Appointment',
    day: 'May 12th at 2:30pm',
    reminder: true,
  },
  {
    id: 9,
    text: 'Doctors Appointment',
    day: 'May 13th at 2:30pm',
    reminder: true,
  },
  {
    id: 10,
    text: 'Doctors Appointment',
    day: 'May 14th at 2:30pm',
    reminder: true,
  },
  {
    id: 11,
    text: 'Doctors Appointment',
    day: 'May 15th at 2:30pm',
    reminder: true,
  },
  {
    id: 12,
    text: 'Doctors Appointment',
    day: 'May 16th at 2:30pm',
    reminder: true,
  },
  {
    id: 13,
    text: 'Doctors Appointment',
    day: 'May 17th at 2:30pm',
    reminder: true,
  },
  {
    id: 14,
    text: 'Doctors Appointment',
    day: 'May 18th at 2:30pm',
    reminder: true,
  },
]
```

if an element in `TASK` doesn't follow the interface structure, thanks to `: Task[]`, it return an error.

⚠ That's all thanks to the interface file! You can choice to change that interface, but remember to change all the elements inside the `TASK` variable!

---
#### 4: print the tasks

Inside the task component, should be coded:
```js
// tasks.component.ts
import { Component, OnInit } from '@angular/core';
import { Task } from '../../Task';
import { TASKS } from '../../mock-tasks';
import { CommonModule } from '@angular/common';

@Component({
	selector: 'app-tasks',
	standalone: true,
	imports: [
		CommonModule
	],
	templateUrl: './tasks.component.html',
	styleUrl: './tasks.component.css'
})

  

export class TasksComponent implements OnInit {
	tasks: Task[] = TASKS; 
	
	constructor() {} 
	
	ngOnInit(): void {}

}
```

```js
<!--tasks.component.html-->
<p *ngFor="let task of tasks">{{ task.text }}</p>
```

and than if you add `<app-tasks></app-tasks>` to the `app.component.html` you'll see all the tasks printed on screen!!

---
#### 5: create a service for tasks

Use the following command to create a service inside the angular project:
```
$ ng generate service services/task
```

the file generated should be like this:
```js
// task.service.ts
import { Injectable } from '@angular/core';

@Injectable({
	providedIn: 'root'
})

export class TaskService {
	constructor() { }
}
```

and then we will add:

```js
// task.service.ts
import { Injectable } from '@angular/core';
import { Observable, of } from 'rxjs'
import { Task } from '../Task';
import { TASKS } from '../mock-tasks';

@Injectable({
	providedIn: 'root'
})

export class TaskService {
	constructor() { }
	
	getTasks(): Observable<Task[]> {
		return of(TASKS);
	}
}
```

and we will change the `tasks.component.ts` file:

```js
import { Component, OnInit } from '@angular/core';
import { Task } from '../../Task';
import { CommonModule } from '@angular/common';
import { TaskItemComponent } from '../task-item/task-item.component';
import { TaskService } from '../../services/task.service';

@Component({
	selector: 'app-tasks',
	standalone: true,
	imports: [
		CommonModule,
		TaskItemComponent
	],
	templateUrl: './tasks.component.html',
	styleUrl: './tasks.component.css'
})
  
export class TasksComponent implements OnInit {

	tasks: Task[] = [];
	
	constructor(private taskService: TaskService) {}
	
	ngOnInit(): void {
		this.taskService.getTasks().subscribe((tasks) => this.tasks = tasks);
	}
}
```

---
#### 6: json local server setup
To simulate properly the work of the frontend we need a backend where save our tasks. So we will use a local json server, running the following command:

```
npm install -g json-server
```

⚠ Run with root privileges if necessary

And now change the `package.json` file inside the project adding the `server` to the possible `scripts`:

```js
{
	"name": "my-app",
	"version": "0.0.0",
	"scripts": {
		"ng": "ng",
		"start": "ng serve",
		"build": "ng build",
		"watch": "ng build --watch --configuration development",
		"test": "ng test",
		"server": "json-server --watch db.json", // <-- this
		"serve:ssr:my-app": "node dist/my-app/server/server.mjs"
	},
	"private": true,
	"dependencies": {
// <-- snip code -->
```

In the root folder, add a `db.json` file to configure the local REST API:

```js
{
	"tasks": [
		{
			"id": 1,
			"text": "Doctors Appointment",
			"day": "May 5th at 2:30pm",
			"reminder": true
		},
		{
			"id": 2,
			"text": "Meeting at School",
			"day": "May 6th at 1:30pm",
			"reminder": true
		},
		{
			"id": 3,
			"text": "Food Shopping",
			"day": "May 7th at 12:30pm",
			"reminder": false
		},
		{
			"id": 4,
			"text": "Doctors Appointment",
			"day": "May 8th at 2:30pm",
			"reminder": true
		}
	]
}```

Now if you run `npm run server` you should see a rest api working on your local machine!

