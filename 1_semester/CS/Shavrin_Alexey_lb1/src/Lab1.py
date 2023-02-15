import wikipedia


def is_page_valid(title):
    """Функция проверяет существование страницы на сайте"""
    try:
        wikipedia.page(title)
    except Exception:
        return False
    return True


def is_in_lang_wiki(l):
    """Функция проверяет наличие введенного языка в возможных языках сервиса"""
    lang_wiki = wikipedia.languages()
    return l in lang_wiki


def max_words(titles):
    """Функция возвращает максимальное кол-во слов в кратком содержании страницы и название этой страницы"""
    mx_words = 0
    mx_title = ''
    for title in titles:                                             # Проходит по всем введенным названиям страниц
        page = wikipedia.page(title)
        summary = page.summary.split()                               # Запись краткого содержания страницы
        count_words = len(summary)                                   # Вычисление кол-ва слов в кратком содержании
        if mx_words <= count_words:
            mx_words = count_words
            mx_title = page.title
    return mx_words, mx_title


def get_chain(titles):
    """Функция строит цепочку из страниц с наименьшим количеством промежуточных звеньев"""
    chain = [titles[0]]
    for i in range(len(titles)-1):                                   # Проходит по всем введенным названиям страниц
        links_list = wikipedia.page(titles[i]).links                 # Создание списка ссылок на странице
        if titles[i+1] in links_list:                                # Проверка на наличие ссылки на следующую страницу
            chain.append(titles[i+1])
        else:
            for j in range(len(links_list)):                         # Проходит по всем ссылкам страницы
                if not is_page_valid(links_list[j]):                 # Проверка на существование страницы по ссылке
                    continue
                intermediate_page = wikipedia.page(links_list[j])    # Сохранение промежуточной страницы в переменную
                intermediate_links = intermediate_page.links         # Сохранение ссылок промежуточной страницы в переменную
                if not intermediate_links:                           # Проверка на наличие ссылок
                    continue
                if titles[i+1] in intermediate_links:                # Проверка на наличие ссылки на следующую страницу
                    chain.append(links_list[j])
                    chain.append(titles[i+1])
                    break
    return chain


def main():
    """Функция запускает лабораторную работу"""
    inp = input().split(', ')
    lang = inp[-1]
    titles = inp[:-1]
    if is_in_lang_wiki(lang):
        wikipedia.set_lang(lang)                                     # Меняет язык
        print(*max_words(titles))                                    # Выводит максимальное кол-во слов и название страницы
        print(get_chain(titles))                                     # Выводит цепочку
    else:
        print('no results')


if __name__ == '__main__':
    main()
