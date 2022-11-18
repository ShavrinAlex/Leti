#python

def substring_search(text, pattern):
    pattern_size = len(pattern)
    text_size = len(text)
    alphabet = list(set(text + pattern))
    min_code = min([ord(symbol) for symbol in alphabet])
    q = 7919
    x = len(alphabet)
    x_exp = (x ** pattern_size) % q

    def code(symbol):
        return ord(symbol) - min_code

    def hashing(string):
        return sum([code(string[i]) * x **(pattern_size - i - 1) for i in range(pattern_size)]) % q

    def slide_hash(subtext_hash, s0, s1):
        return (subtext_hash * x - code(s0) * x_exp + code(s1)) %q

    pattern_hash = hashing(pattern)
    subtext_hash = hashing(text)

    indices= []
    for i in range(text_size - pattern_size):
        if subtext_hash == pattern_hash and text[i:i + pattern_size] == pattern:
            indices.append(i)
        subtext_hash = slide_hash(subtext_hash, text[i], text[i + pattern_size])

    if subtext_hash == pattern_hash:
        indices.append(text_size - pattern_size)

    return indices


def main():
    pattern = input()
    text = input()
    print(*substring_search(text, pattern))


if __name__ == "__main__":
    main()
