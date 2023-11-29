class Node:
    def __init__(self,symb):
        self.data = []
        self.data.append(symb)
        self.data_size = 1
        self.com_sum = symb[1]
    def insert(self,symb):
        for i in range(len(symb)):
            self.data.append(symb[i])
            self.data_size +=1
            self.com_sum += symb[i][1]
        
    def __str__(self):
        return str(self.com_sum)
    def write_code(self,code):
        for i in range(self.data_size):
            self.data[i][2] = code + self.data[i][2]
class Haffman:
    def __init__(self,data= []):
        self.data = data
        self.size = len(data)
    def min(self):
        ind = -1
        min = 1000
        for i in range(self.size):
            if self.data[i].com_sum < min:
                min = self.data[i].com_sum
                ind = i
        print(f"min = {min}, ind = {ind}")
        return ind
    def glue(self):

        while (self.size!=1):
            min1 = self.data.pop(self.min())
            min1.write_code("0")
            self.size -=1
            min2 = self.data.pop(self.min())
            min2.write_code("1")
            print(min1.data,min2.data)
            min1.insert(min2.data)
            print(min1.data)
            self.data.append(min1)
            self.print()
    def print(self):
        for i in range(hmn.size):
            print(self.data[i])
        print()
    def print_codes(self):
        for i in range(self.data[0].data_size):
            print(self.data[0].data[i][0]," - ",self.data[0].data[i][2])
if __name__ == "__main__":
    hmn = Haffman(  [Node(["a",10,""]),Node(["b",5,""]),Node(["c",7,""]),Node(["d",9,""]),Node(["e",7,""]) ] )
    hmn.glue()
    #hmn.print()
    #print(hmn.data[0].data)
    hmn.print()
    hmn.print_codes()