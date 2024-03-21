p = 256

def getHash(s):
    hash_val = 0
    p_pow = 1
    for i in s:
        hash_val = hash_val + (ord(i) + 1) * pow(p, p_pow)
        p_pow += 1
    print(hash_val)
    return int(hash_val)

def getRevHash(s):
    hash_val = 0
    p_pow = len(s)
    for i in s:
        hash_val = hash_val + (ord(i) + 1) * pow(p, p_pow)
        p_pow -= 1
    print(hash_val)
    return int(hash_val)



s = input()
ans = getHash(s)
asn2 = getRevHash(s)
if ans == asn2:
    print("YESSSS")