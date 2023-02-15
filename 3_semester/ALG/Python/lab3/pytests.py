from MinHeap import MinHeap

def test_mv():
    processors = [[0, 0], [0, 1]]
    tasks = [1, 2, 3, 4]
    correct_answer = [[0, 0], [1, 0], [0, 1], [1, 2]]

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer


def test_one_task():
    processors = [[0, 0], [0, 1]]
    tasks = [1]
    correct_answer = [[0, 0]]

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer


def test_zero_tasks():
    processors = [[0, 0], [0, 1]]
    tasks = []
    correct_answer = []

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer

def test_negative_tasks():
    processors = [[0, 0], [0, 1]]
    tasks = []
    correct_answer = []

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer

def test_same_tasks():
    processors = [[0, 0], [0, 1]]
    tasks = [1, 1, 1, 1, 1]
    correct_answer = [[0, 0], [1, 0], [0, 1], [1, 1], [0, 2]]

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer


def test_many_processors():
    processors = [[0, 0], [0, 1], [0, 2], [0, 3]]
    tasks = [1, 2, 3, 4, 5, 6, 7]
    correct_answer = [[0, 0], [1, 0], [2, 0], [3, 0], [0, 1], [1, 2], [2, 3]]

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer

def test_zero_processors():
    processors = []
    tasks = [1, 2, 3]
    correct_answer = []

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer

def test_negative_number_of_processors():
    processors = []
    tasks = [1, 2, 3]
    correct_answer = []

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer
    
def test_negative_time():
    processors = [[0, 0], [0, 1]]
    tasks = [-1, -2, -3]
    correct_answer = [[0, 0], [0, -1], [0, -3]]

    min_heap = MinHeap(processors)
    min_heap.parallelProcessing(tasks)

    assert min_heap.getResult() == correct_answer