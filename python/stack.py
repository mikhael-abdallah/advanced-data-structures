class Stack:
    data = []

    def top(self):
        if self.empty():
            return None
        return self.data[-1]

    def push(self, x):
        self.data.append(x)

    def empty(self):
        return len(self.data) == 0

    def pop(self):
        if self.empty():
            return None
        return self.data.pop()
    
    def printStack(self):
            print(self.data)


stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)

stack.printStack()
print(stack.pop())

print(stack.pop())

print(stack.pop())

print(stack.pop())
