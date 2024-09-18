import { Component } from '@angular/core';
import { ButtonComponent } from '../button/button.component';
import { TasksComponent } from '../tasks/tasks.component';
import { Task } from '../../Task';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-header',
  standalone: true,
  imports: [ 
    ButtonComponent, 
    TasksComponent
  ],
  templateUrl: './header.component.html',
  styleUrl: './header.component.css'
})

export class HeaderComponent {
  title: string = 'Task Tracker';
  private apiUrl = 'http://localhost:3000/tasks';


  constructor( private http: HttpClient) {}

  ngOnInit(): void {}

  public toggleAddTask() {
    const TASKS = this.http.post<Task[]>(this.apiUrl, { title: 'Task 1', reminder: true });
    return TASKS;
  }
}
