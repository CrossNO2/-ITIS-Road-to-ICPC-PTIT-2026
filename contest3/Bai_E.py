

a = []
def fibonacci():
    a.append(0)
    # a[1] =1
    for i in range(1, 10002):
        if(i < 2): a.append(1)
        else: a.append(a[i-1] + a[i-2])
    a[0] = 1


t = int(input())
fibonacci()
while(t > 0):
    n = int(input()) 
    print(a[n])
    t -= 1