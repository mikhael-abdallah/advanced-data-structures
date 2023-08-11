public class PersistentStack<T> {
    private T value;
    PersistentStack<T> parent = null;
    private int size = 0;

    public PersistentStack(T value, PersistentStack<T> parent, int size) {
        this.value = value;
        this.parent = parent;
        this.size = size;
    }
    public PersistentStack() {
        this.value = null;
        this.parent = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return this.parent == null;
    }

    public PersistentStack<T> push(T value) {
        return new PersistentStack<T>(value, this, this.size + 1);
    }

    public PersistentStack<T> pop() {
        if(this.isEmpty()) {
            System.out.println("Stack is empty!");
            return null;
        }
        return this.parent;
    }

    public T top() {
        if(this.isEmpty()) {
            System.out.println("Stack is empty!");
            return null;
        }
        return this.value;
    }
    public String toString() {
        return "[" + toStringHelper(this, 0) + "]";
    }

    private String toStringHelper(PersistentStack<T> node, int index) {
        if (node.value == null) {
            return "";
        }

        String result = toStringHelper(node.parent, index + 1);
        return (index > 0 ? ", " : "") + node.value + result;
    }


    public static void main(String[] args) {
        PersistentStack<Integer> stack1 = new PersistentStack<Integer>();
        PersistentStack<Integer> stack2 = stack1.push(1);
        PersistentStack<Integer> stack3 = stack2.push(2);

        PersistentStack<Integer> stack4 = stack3.pop();
        PersistentStack<Integer> stack5 = stack4.pop();

        System.out.println("stack1 top: " + stack1.top() + ", stack: " + stack1);
        System.out.println("stack2 top: " + stack2.top() + ", stack: " + stack2);
        System.out.println("stack3 top: " + stack3.top() + ", stack: " + stack3);
        System.out.println("stack4 top: " + stack4.top() + ", stack: " + stack4);
        System.out.println("stack5 top: " + stack5.top() + ", stack: " + stack5);

    }
}

