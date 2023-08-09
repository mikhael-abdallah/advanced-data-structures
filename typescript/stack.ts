export class Stack {
    private data: any[] = [];

    public top(): any {
        return this.data.at(-1);
    }

    public isEmpty(): boolean {
        return this.data.length === 0;
    }

    public push(elem: any) {
        this.data.push(elem);
    }

    public pop() {
        if(this.isEmpty()) {
            return undefined;
        }
        return this.data.pop();
    }

    public printStack() {
        console.log(this.data)
    }
}




const stack = new Stack()

stack.push(1)
stack.push(2)
stack.push(3)

stack.printStack()
console.log(stack.pop())

console.log(stack.pop())

console.log(stack.pop())

console.log(stack.pop())
