import java.util.Arrays;

public class Stack {
    private int[] data;
    int top = -1;
    private int size = 1;

    public Stack(int size) {
        if(size < 1) size = 1;
        this.data = new int[size];
        this.size = size;
    }

    public boolean isEmpty() {
        return this.top == -1;
    }

    public void push(int value) {
        if(this.top == this.size - 1) {
            this.size *= 2;
            this.data = Arrays.copyOf(this.data, this.size);
        }
        this.data[++this.top] = value;
    }

    public Integer pop() {
        if(this.isEmpty()) {
            System.out.println("Stack is empty!");
            return null;
        }
        if(this.top == this.size / 4) {
            this.size /= 2;
            this.data = Arrays.copyOf(this.data, this.size);
        }
        return this.data[this.top--];
    }
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 0; i <= this.top; i++) {
            if (i > 0) {
                stringBuilder.append(", ");
            }
            stringBuilder.append(this.data[i]);
        }
        return stringBuilder.append("]").toString();
    }

    public static void main(String[] args) {
        Stack stack = new Stack(1);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println(stack);
        System.out.printf("Stack size: %d\n", stack.size);

        System.out.printf("Pop: %d\n", stack.pop());
        System.out.printf("Stack size: %d\n", stack.size);

        System.out.printf("Pop: %d\n", stack.pop());
        System.out.printf("Stack size: %d\n", stack.size);

        System.out.printf("Pop: %d\n", stack.pop());
        System.out.printf("Stack size: %d\n", stack.size);

        System.out.printf("Pop: %d\n", stack.pop());
        System.out.printf("Stack size: %d\n", stack.size);

    }
}

