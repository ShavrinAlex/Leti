#python

class MinHeap:
    def __init__(self, processors):
        self.data = processors
        #print(f"init {self.data}")
        self.size = len(processors)
        self.result = []

    @staticmethod
    def getLeftChildIndex(index):
        return 2 * index + 1

    @staticmethod
    def getRightChildIndex(index):
        return 2 * index + 2

    def getResult(self):
        return self.result

    def siftDown(self, index):
        #print(f"sift down {self.data}")
        min_index = index
        left_child_index = self.getLeftChildIndex(index)
        right_child_index = self.getRightChildIndex(index)
        #print(f"min_index = {min_index}")
        #print(f"left_child_index = {left_child_index}")
        #print(f"right_child_index = {right_child_index}")

        if left_child_index < self.size and self.data[left_child_index] < self.data[min_index]:
            #print(f"self.data[left_child_index] = {self.data[left_child_index]}\nself.data[min_index] = {self.data[min_index]}")
            min_index = left_child_index

        if right_child_index < self.size and self.data[right_child_index] < self.data[min_index]:
            min_index = right_child_index

        if index != min_index:
            #print(f"new min_index = {min_index} sift")
            self.data[index], self.data[min_index] = self.data[min_index], self.data[index]
            self.siftDown(min_index)

    def parallelProcessing(self, tasks):
        if (self.data != []):
            for cur_task in tasks:
                cur_time = self.data[0][0]
                processor = self.data[0][1]
                print(processor, cur_time)
                self.result.append([processor, cur_time])
                self.data[0][0] += cur_task
                self.siftDown(0)

def main(n, m):
    processors = [[0, i] for i in range(n)]
    if m <= 0:
        tasks = []
    else:
        tasks = list(map(int, input().split(' ')))

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

if __name__ == "__main__":
    n, m = map(int, input().split())
    main(n, m)

    #print(min_heap.getResult())
