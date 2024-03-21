# ф-я хэширования строк
def hashing(string, M):
    hash = 0
    x = 31      # x - любое число от 0 до q -1 
    q = 131     # q - любое простое число

    tmp_str = string[:M]

    for ind in range(len(tmp_str)):
        hash = (hash * x + ord(string[ind])) % q

    return hash

def main():
    M = int(input())
    list_str = input().split()

    print(M)
    print(list_str)

    # вычисляем хэши строк
    hash_list = []
    for ind in range(len(list_str)):
        hash_list.append(hashing(list_str[ind], M))

    # вычисляем количество строк
    answer = {}
    count_no_repeat = 0

    for ind, el in enumerate(hash_list):
        repeat = hash_list.count(el)
        if repeat == 1:
            count_no_repeat += 1

        answer[list_str[ind][:M]] = repeat

    print(answer)

    print(count_no_repeat)

if __name__ == "__main__":
    main()
