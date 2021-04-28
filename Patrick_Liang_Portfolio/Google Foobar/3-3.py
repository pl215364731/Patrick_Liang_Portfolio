def solution(l):
    double = [0]*len(l)
    triple = 0
    for i in range(len(l)):
        for j in range(i+1, len(l)-1):
            if l[j] % l[i] == 0:
                double[j] += 1
    for j in range(1,len(l)-1):
        for k in range(j+1,len(l)):
            if l[k] % l[j] == 0:
                triple += double[j]
    return triple

def check(i,j,l):
    counter = 0
    for k in range(j+1, len(l)):
        if l[k] % l[j] == 0:
            counter += 1
    return counter

print(solution([1,2,3,4,5,6]))