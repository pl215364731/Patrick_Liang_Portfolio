def solution(x, y):
    M = int(x)
    F = int(y)
    generations = 0
    result = recursiveMinus(M,F,generations)
    if(result == -1):
        return "impossible"
    else:
        return str(result)
    
def recursiveMinus(M,F,generations):
    if(M > F):
        if(F == 1):
            generations += M - 1
            M = 1
        else:
            divider = M / F
            M -= divider * F
            generations += divider

    elif(M < F):
        if(M == 1):
            generations += F - 1
            F = 1
        else:
            divider = F / M
            F -= divider * M
            generations += divider
    if(M == 1 and F == 1):
        return generations
    elif(M == F):
        return -1
    elif(M == 0 or F == 0):
        return -1
    else:
        generations = recursiveMinus(M,F,generations)
        return generations

