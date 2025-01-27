def josephus(l, ind, k):
    if len(l) == 1:
        print(l[0])
        return
    ind = (ind + k) % len(l)
    l.pop(ind)
    josephus(l, ind, k)
    
n = int(input("Enter the number of people : "))
l = [i for i in range(1, n + 1)]
josephus(l, 0, 1)