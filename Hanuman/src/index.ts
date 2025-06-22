interface Todo {
  id: number;
  text: string;
  completed: boolean;
}

let todos: Todo[] = [];

const todoList = document.getElementById('todo-list') as HTMLUListElement;
const todoForm = document.getElementById('todo-form') as HTMLFormElement;
const todoInput = document.getElementById('todo-input') as HTMLInputElement;

function renderTodos() {
  todoList.innerHTML = '';
  todos.forEach(todo => {
    const li = document.createElement('li');
    li.className = todo.completed ? 'completed' : '';

    const span = document.createElement('span');
    span.textContent = todo.text;
    span.onclick = () => toggleTodo(todo.id);

    const removeBtn = document.createElement('button');
    removeBtn.textContent = 'Remove';
    removeBtn.onclick = () => removeTodo(todo.id);

    li.appendChild(span);
    li.appendChild(removeBtn);
    todoList.appendChild(li);
  });
}

function addTodo(text: string) {
  const newTodo: Todo = {
    id: Date.now(),
    text,
    completed: false,
  };
  todos.push(newTodo);
  renderTodos();
}

function toggleTodo(id: number) {
  todos = todos.map(todo =>
    todo.id === id ? { ...todo, completed: !todo.completed } : todo
  );
  renderTodos();
}

function removeTodo(id: number) {
  todos = todos.filter(todo => todo.id !== id);
  renderTodos();
}

todoForm.onsubmit = (e) => {
  e.preventDefault();
  const value = todoInput.value.trim();
  if (value) {
    addTodo(value);
    todoInput.value = '';
  }
};

renderTodos();
