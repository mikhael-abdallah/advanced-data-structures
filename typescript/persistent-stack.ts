
export class PersistentStack<T> {
    private value: T | null = null;
    private parent: PersistentStack<T> | null = null;
    private size: number = 0;
    constructor(value?: any, parent?: PersistentStack<T>, size?: number ) {
        this.value = value ?? null;
        this.parent = parent ?? null;
        this.size = size ?? 0;
    }

    public push(value: T): PersistentStack<T> {
        return new PersistentStack(value, this, this.size + 1)
    };

    public pop(): PersistentStack<T> | null {
        if(this.parent == null) {
            console.log("The stack is empty!")
            return null;
        }
        return this.parent;
    }

    public top(): T | null {
        if(this.parent == null) {
            console.log("The stack is empty!")
            return null;
        }
        return this.value;
    }


    public printStack(): any[] {
        const array = Array.from({length: this.size})
        let node: PersistentStack<T> | null = this;
        for(let i = this.size -1; i >= 0 && node != null; i--) {
            array[i] = node.value;
            node = this.parent;
        }
        return array;
    }
}


const stack1 = new PersistentStack<number>()

const stack2 = stack1.push(1)
const stack3 = stack2.push(2)

const stack4 = stack3.pop();
const stack5 = stack4?.pop();


console.log("stack1 top: " + stack1.top() + " ,stack:" + stack1.printStack())
console.log("stack2 top: " + stack2.top() + " ,stack: " + stack2.printStack())
console.log("stack3 top: " + stack3.top() + " ,stack: " + stack3.printStack())
console.log("stack4 top: " + stack4?.top() + " ,stack: " + stack4?.printStack())
console.log("stack5 top: " + stack5?.top() + " ,stack: " + stack5?.printStack())



