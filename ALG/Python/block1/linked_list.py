class Node:
    def __init__(self, data, prev=None, next=None):
        self.__data = data
        self.__prev__ = prev
        self.__next__ = next

    def get_data(self):
        return self.__data

    def __str__(self):
        prev = None
        if self.__prev__:
            prev = self.__prev__.__data

        next = None
        if self.__next__:
            next = self.__next__.__data

        return "data: {}, prev: {}, next: {}".format(self.__data, prev, next)


class LinkedList:
    def __init__(self, first=None, last=None):
        if first is None and last:
            raise ValueError("invalid value for last")

        if first and last is None:
            self.__length = 1
            self.__first__ = self.__last__ = Node(first)
            return

        if first and last:
            self.__length = 2
            self.__first__ = Node(first)
            self.__last__ = Node(last, self.__first__)
            self.__first__.__next__ = self.__last__
            return

        self.__length = 0
        self.__first__ = first
        self.__last__ = last

    def __len__(self):
        return self.__length

    def __str__(self):
        if self.__length == 0:
            return "LinkedList[]"

        res = "LinkedList[length = {}, [".format(self.__length)
        cur = self.__first__

        while cur:
            res += cur.__str__()
            if cur.__next__:
                res += '; '
            cur = cur.__next__

        res += "]]"
        return res

    def clear(self):
        self.__length = 0
        self.__first__ = self.__last__ = None

    def append(self, element):
        self.__length += 1

        if self.__length == 1:
            self.__first__ = self.__last__ = Node(element)
            return

        self.__last__.__next__ = Node(element, self.__last__)
        self.__last__ = self.__last__.__next__

    def pop(self):
        if self.__length == 0:
            raise IndexError("LinkedList is empty!")

        self.__length -= 1
        self.__last__ = self.__last__.__prev__
        self.__last__.__next__ = None

    def popitem(self, element):
        count = 0
        cur = self.__first__
        while cur:
            if cur.get_data() == element:
                self.__length -= 1
                count += 1

                if cur.__prev__:
                    cur.__prev__.__next__ = cur.__next__

                if cur.__next__:
                    cur.__next__.__prev__ = cur.__prev__

                if cur is self.__first__:
                    self.__first__ = cur.__next__

                if cur is self.__last__:
                    self.__last__ = cur.__prev__
            cur = cur.__next__

        if count == 0:
            raise KeyError("{} doesn't exist!".format(element))

# tests
node = Node(1)
print(node)
node.__prev__ = Node(2, None, None)
print(node)
node.__next__ = Node(3, None, None)
print(node)

linked_list = LinkedList()
print(linked_list)
linked_list.append(10)
print(linked_list)
print(len(linked_list))
linked_list.append(20)
print(linked_list)
print(len(linked_list))

linked_list.pop()
print(linked_list)
print(linked_list)
print(len(linked_list))