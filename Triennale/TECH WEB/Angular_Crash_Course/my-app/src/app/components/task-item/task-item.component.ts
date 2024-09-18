import { Component, Input, OnInit } from '@angular/core';
import { Task } from '../../Task';

@Component({
  selector: 'app-task-item',
  standalone: true,
  imports: [],
  templateUrl: './task-item.component.html',
  styleUrl: './task-item.component.css'
})
export class TaskItemComponent implements OnInit {
  @Input() task!: Task;

  constructor() { }

  ngOnInit(): void {}

}
