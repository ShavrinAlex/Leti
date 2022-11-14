class HashTable():
    def __init__(self):
        self.size = 0
        self.table = []

    def add(self, number, name):
        is_found = False
        for i in range(self.size):
            if self.table[i][0] == number:
                is_found = True
                break
        if not is_found:
            self.size += 1
            self.table.append([number, name])

    def find(self, number):
        result = "not found"
        for i in range(self.size):
            if self.table[i][0] == number:
                result = self.table[i][1]
        return result

    def dell(self, number):
        for i in range(self.size):
            if self.table[i][0] == number:
                del self.table[i]
                self.size -= 1
                break

def main():
    hash_table = HashTable()
    count_operations = int(input())
    for _ in range(count_operations):
        line = input().split(' ')
        if line[0] == "add":
            hash_table.add(line[1], line[2])
        elif line[0] == "find":
            print(hash_table.find(line[1]))
        elif line[0] == "del":
            hash_table.delete(line[1])

if __name__ == "__main__":
    main()