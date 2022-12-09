def hashing(string,m,M):
    hash=0
    x=31
    q=131
    tmp_str = string[:M]

    for ind in range(len(tmp_str)):
        hash =( hash*x + ord(string[ind]))%q
    return hash

M=int(input())
list_str=input().split()

print(M)
print(list_str)
ans={}
tmp_list = []
for ind in range(len(list_str)):
   tmp_list.append(hashing(list_str[ind],len(list_str),M))



for ind,el in enumerate(tmp_list):
    rep = tmp_list.count(el)
    ans[list_str[ind][:M]]=rep

print(ans)