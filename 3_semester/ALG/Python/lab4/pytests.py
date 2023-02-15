from RabinKarp import main

def test_mv():
    pattern = "aba"
    text = "abacaba"
    assert main(pattern, text) == [0, 4]

def test_null_pattern():
    pattern = ""
    text = "sdfqwesd"
    assert main(pattern, text) == []

def test_null_text():
    pattern = "asdf"
    text = ""
    assert main(pattern, text) == []

def test_pattern_at_the_beginning_of_the_text():
    pattern = "asdasd"
    text = "asdasdxcvbnmkiuyt"
    assert main(pattern, text) == [0]

def test_pattern_at_the_end_of_the_text():
    pattern = "asdasd"
    text = "xcvbnmkiuytasdasd"
    assert main(pattern, text) == [11]

def test_text_without_pattern():
    pattern = "fgvjbk"
    text = "ffghjrtyui vjhgf"
    assert main(pattern, text) == []

def test_pattern_with_spaces_and_other_symbols():
    pattern = "Он (Algorithm)~был| разработан в [$1987] {году'!"
    text = "Алгоритм Рабина. Он (Algorithm)~был| разработан в [$1987] {году'! Майклом Рабином и Ричардом Карпом.[1]"
    assert main(pattern, text) == [17]
    