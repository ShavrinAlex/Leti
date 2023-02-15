class Node:
    def __init__(self, data, index=None, next_node=None):
        self.__data = data
        self.__index = index
        self.__next_node__ = next_node

    def get_data(self):
        return self.__data

    def get_index(self):
        return self.__index

    def __str__(self):
        next = None
        if self.__next_node__:
            next = self.__next_node__.__data

        return "data: {}, next: {}".format(self.__data, next)


class Stack:
    def __init__(self, data_node=None):
        if data_node is None:
            self.__top = data_node
            self.__length = 0
            return
        self.__top = Node(data_node)
        self.__length = 1

    def push(self, data_node, index):
        node = Node(data_node, index, self.__top)
        self.__top = node
        self.__length += 1

    def pop(self):
        if self.__length == 0:
            raise IndexError("Stack is empty!")
        self.__top = self.__top.__next_node__
        self.__length -= 1

    def get_top(self):
        if self.__length == 0:
            raise IndexError("Stack is empty!")
        return self.__top

    def get_last(self):
        cur = self.__top
        while cur.__next_node__:
            cur = cur.__next_node__
        return cur

    def isEmpty(self):
        return self.__length == 0

    def clear(self):
        if self.__length == 0:
            raise IndexError("Stack is empty!")
        self.__length = 0
        self.__top = None

    def __len__(self):
        return self.__length

    def __str__(self):
        if self.__length == 0:
            return "Stack[]"

        res = "Stack[length = {}, [".format(self.__length)
        cur = self.__top

        while cur:
            res += cur.__str__()
            if cur.__next_node__:
                res += '; '
            cur = cur.__next_node__

        res += "]]"
        return res


def isBracket(symbol):
    if symbol in "({[":
        return -1
    if symbol in ")}]":
        return 1
    return 0


def isPairBrackets(left_brk, right_brk):
    if left_brk == '(':
        return right_brk == ')'
    if left_brk == '{':
        return right_brk == '}'
    if left_brk == '[':
        return right_brk == ']'
    """
    for python 3.10
    match left_brk:
        case '(':
            return right_brk == ')'
        case '{':
            return right_brk == '}'
        case '[':
            return right_brk == ']'
    """

def main():
    stack = Stack()
    str = input()
    index = 0
    f = 0
    for symbol in str:
        index += 1
        if isBracket(symbol) == -1:
            stack.push(symbol, index)
            continue
        if isBracket(symbol) == 1:
            if stack.isEmpty():
                f += 1
                break
            if isPairBrackets(stack.get_top().get_data(), symbol):
                stack.pop()
            else:
                f += 1
                break
        """
        for python 3.10
        match isBracket(symbol):
            case -1:
                stack.push(symbol, index)
                continue
            case 1:
                if stack.isEmpty():
                    f += 1
                    break
                if isPairBrackets(stack.get_top().get_data(), symbol):
                    stack.pop()
                else:
                    f += 1
                    break
            case 0:
                print(f"{symbol} - it is not a bracket!")
        """
    if stack.isEmpty() and not(f):
        print(f"Success")
    elif not(f):
        print(stack.get_last().get_index())
    else:
        print(index)

if __name__ == "__main__":
    main()
