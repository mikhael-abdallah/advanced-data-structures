#[derive(Debug)]

struct Stack<T> {
  stack: Vec<T>,
}

impl<T> Stack<T> {
  fn new() -> Self {
    Stack { stack: Vec::new() }
  }

  fn pop(&mut self) -> Option<T> {
    if self.is_empty() {
        println!("The stack is empty!");
        return None;
    }
    self.stack.pop()
  }

  fn push(&mut self, item: T) {
    self.stack.push(item)
  }

  fn is_empty(&self) -> bool {
    self.stack.is_empty()
  }

  fn size(&self) -> usize {
    self.stack.len()
  }
}


fn main() {
    let mut stack: Stack<isize> = Stack::new();
    stack.push(1);
    stack.push(2);
    stack.push(3);

    println!("{:?}", stack);

    println!("size: {}", stack.size());

    println!("pop: {:?}", stack.pop().unwrap());
    println!("size: {}", stack.size());

    println!("pop: {:?}", stack.pop().unwrap());
    println!("size: {}", stack.size());

    println!("pop: {:?}", stack.pop().unwrap());
    println!("size: {}", stack.size());

    println!("pop: {:?}", stack.pop());
    println!("size: {}", stack.size());

}