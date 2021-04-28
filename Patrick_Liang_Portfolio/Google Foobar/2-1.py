def solution(l, t):
    for c in range((len(l) - 1)):
        sum = l[c]
        if(sum == t):
            return[c,c]
        maxSumNumbers = len(l) - 1 - c
        for i in range(maxSumNumbers):
            sum += l[c+i+1]
            if(sum == t):
                return [c, c+i+1]
    return[-1, -1]
    

print(solution([1,9,2,1,2], 11))