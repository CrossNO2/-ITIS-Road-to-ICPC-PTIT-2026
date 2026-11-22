
def check(a, b, c, d, e, f, i):
    return a * i *i *i *i*i + b *i*i*i*i + c*i *i*i + d*i*i+ e*i + f


s = input()
tmp = s.split()
a, b, c, d, e, f = map(int, tmp)

cnt = 0

for i in range(100):
    if(check(a, b, c, d, e, f, i) == 0): cnt += 1


print(cnt)