class PersistentStack:
    value = None
    parent = None
    size = 0

    def __init__(self, value=None, parent=None, size=0):
        self.value = value
        self.parent = parent
        self.size = size

    def push(self, x):
        return PersistentStack(x, self, self.size + 1)

    def pop(self):
        if not self.parent:
            print("Stack is empty!")
            return None
        return self.parent

    def top(self):
        if not self.parent:
            print("Stack is empty!")
            return None
        return self.value

    def to_string(self):
        return "[" + self.to_string_helper(self, 0) + "]"

    def to_string_helper(self, node, index):
        if node.value is None:
            return ""
        result = self.to_string_helper(node.parent, index + 1)
        if index > 0:
            return ", " + str(node.value) + result
        return str(node.value) + result


stack1 = PersistentStack()
stack2 = stack1.push(1)
stack3 = stack2.push(2)

stack4 = stack3.pop()
stack5 = stack4.pop()

print("stack1 top: ", stack1.top(), "stack1: ", stack1.to_string())
print("stack2 top: ", stack2.top(), "stack2: ", stack2.to_string())
print("stack3 top: ", stack3.top(), "stack3: ", stack3.to_string())
print("stack4 top: ", stack4.top(), "stack4: ", stack4.to_string())
print("stack5 top: ", stack5.top(), "stack5: ", stack5.to_string())
