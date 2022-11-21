#python

class RabinKarp():
    # инициализация необходимых констант
    def __init__(self, pattern, text):
        self.q = 5      # q - любое простое число
        self.x = 3      # x - любое число от 0 до q - 1

        self.pattern = pattern
        self.text = text

        self.len_pattern = len(pattern)
        self.len_text = len(text)

        # массив степеней х от x ** 0 до x ** len_pattern
        self.x_arr = [0] * self.len_pattern
        self.__createXArr()

        # сохранение хэша искомой подстроки
        self.hpattern = self.__hashing(self.pattern)

        self.answer = []

    # создает массив степеней х от x ** 0 до x ** len_pattern
    def __createXArr(self):
        for i in range(self.len_pattern):
            self.x_arr[i] = self.x ** i

    # хэширование строки из алгоритма Рабина-Карпа
    def __hashing(self, string):
        res = 0
        m = len(string)
        for i in range(m):
            res += (ord(string[i]) * self.x_arr[m - i - 1]) % self.q

        return res % self.q

    # поиск вхождения подстроки в тексте
    def search(self):
        htext = self.__hashing(self.text[:self.len_pattern])
        
        if self.len_pattern != 0 and self.len_text != 0:
            for i in range(self.len_text - self.len_pattern + 1):   # self.len_text - self.len_pattern + 1, чтобы проверить последнюю подпоследовательность в тексте
                if htext == self.hpattern:
                    if self.pattern == self.text[i : i + self.len_pattern]:
                        self.answer.append(i)
                    
                # для того, что бы не было ошибки при проверке последней подпоследовательности в тексте
                if (i + self.len_pattern) < self.len_text:
                    first_symb_code = ord(self.text[i])
                    next_symb_code = ord(self.text[i + self.len_pattern])

                    htext = ((htext - first_symb_code * self.x_arr[-1]) * self.x_arr[1] + next_symb_code) % self.q

    # возвращает результат
    def getAnswer(self):
        return self.answer


def main(pattern, text):
    rabin_karp = RabinKarp(pattern, text)      
    rabin_karp.search()
    return rabin_karp.getAnswer()


if __name__ == "__main__":
    pattern = input()
    text = input()
    print(*main(pattern, text))
