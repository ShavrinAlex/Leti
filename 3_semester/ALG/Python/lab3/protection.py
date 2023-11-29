#python

class Node:
    def __init__(self, elem):
        self.data = []
        self.data.append(elem)
        self.data_size = 1
        self.freq = elem[1]

    def insert(self, elem):
        for i in range(len(elem)):
            self.freq += elem[i][1]
            self.data.append(elem[i])
            self.data_size += 1

    def write_code(self, code):
        for i in range(self.data_size):
            self.data[i][2] = code + self.data[i][2]


class Haffman:
    def __init__(self, data = []):
        self.data = data
        self.size = len(data)

    def get_min(self):
        ind = -1
        min = 1000000
        for i in range(self.size):
            if self.data[i].freq < min:
                min = self.data[i].freq
                ind = i
        return ind

    def glue(self):
        while (self.size!=1):
            left = self.data.pop(self.get_min())
            left.write_code("0")
            self.size -=1

            right = self.data.pop(self.get_min())
            right.write_code("1")

            left.insert(right.data)

            self.data.append(left)

    def print_codes(self):
        for i in range(self.data[0].data_size):
            print(self.data[0].data[i][0]," - ",self.data[0].data[i][2])

    def get__symb_code(self, symb):
        for i in range(self.data[0].data_size):
            if (self.data[0].data[i][0] == symb):
                return self.data[0].data[i][2]
        return None

    def get_symb(self, code):
        for i in range(self.data[0].data_size):
            if (self.data[0].data[i][2] == code):
                return self.data[0].data[i][0]
        return None

    def encode(self, string):
        result = []
        for symb in string:
            result.append(self.get__symb_code(symb))
        
        return result
    
    def decode(self, encode_string):
        result = []
        code = ""
        for symb in encode_string:
            code += symb
            if self.get_symb(code) != None:
                result.append(self.get_symb(code))
                code = ""
        
        return result


if __name__ == "__main__":
    string = input()

    freq_dict = dict()
    node_list = []

    #create frec dict
    for symb in string:
        if symb in freq_dict.keys():
            freq_dict[symb] += 1
        else:
            freq_dict[symb] = 1
    
    #create Node list
    for symb, freq in freq_dict.items():
        node_list.append(Node([symb, freq, ""]))

    #create freq table
    haffman = Haffman(node_list)
    haffman.glue()
    haffman.print_codes()

    #encoding
    encode_string = ''.join(haffman.encode(string))
    print(encode_string)

    #decoding
    decode_string = ''.join(haffman.decode(encode_string))
    print(decode_string)
