import fractions
from fractions import Fraction
def solution(m):
    absorbingIndex = []
    nonAbsorbingIndex = []
    for i in range(len(m)):
        if(m[i][i] != 0):
            m[i][i] = 0
    
    nonAb = getnonAb(m, absorbingIndex, nonAbsorbingIndex)
    newM = probabilityMatrix(m, nonAbsorbingIndex)
    Q = getQ(newM, nonAb, nonAbsorbingIndex)
    R = getR(newM, nonAb, absorbingIndex, nonAbsorbingIndex)
    I = getI(nonAb)
    F = invertMatrix(matrixSubtract(I,Q))
    probability = matrixMulti(F,R)
    #converting probability to answer
    result = []
    denominators = [Fraction(r).denominator for r in probability]
    lcm = denominators[0]
    for d in denominators[1:]:
        lcm = lcm // fractions.gcd(lcm, d) * d
    for i in range(len(m) - nonAb):
        result.append(probability[i].numerator * lcm // probability[i].denominator)
    result.append(lcm)
    return result
    
def probabilityMatrix(m, nonAbIn):
    tmp = [[0 for col in range(len(m))]for row in range(len(m))]
    for row in nonAbIn:
        denom = 0
        for col in range(len(m)):
            denom += m[row][col]
        for col in range(len(m)):
            tmp[row][col] = Fraction(m[row][col],denom)
    return tmp

def matrixSubtract(m,n):
    tmp = m[:]
    for row in range(len(m)):
        for col in range(len(m)):
            tmp[row][col] = m[row][col] - n[row][col]
    return tmp

def matrixMulti(F,R): #returns an array that has size col of R
    tmpRow = [0 for col in range(len(R[0]))]
    for i in range(len(R[0])):
        for j in range(len(F)):
            tmpRow[i] += (F[0][j] * R[j][i])
    return tmpRow

def invertMatrix(m):
    tmp = m[:]
    I = getI(len(m))
    for j in range(len(m)):
        tmpFrac = tmp[j][j]
        tmp[j] = rowMultiply(tmp[j], 1/tmpFrac)
        I[j] = rowMultiply(I[j], 1/tmpFrac)
        for i in range(len(m)):
            if i == j:
                continue
            tmpFrac = tmp[i][j]
            rowSubtract(tmp[i], rowMultiply(tmp[j], tmpFrac))
            rowSubtract(I[i], rowMultiply(I[j], tmpFrac))
            
    return I
        
                
def rowSubtract(row1, row2):
    for i in range(len(row1)):
        row1[i] -= row2[i]
    return 
    
def rowMultiply(row, scalar):
    tmpRow = [0 for i in range(len(row))]
    for i in range(len(row)):
        tmpRow[i] = row[i] * scalar
    return tmpRow


def getnonAb(m, abIn, nonAbIn):
    nonAb = 0
    for row in range(len(m)):
        ab = True
        for col in range(len(m)):
            if m[row][col] != 0 and row != col:
                nonAb += 1
                ab = False
                nonAbIn.append(row)
                break
        if ab == True:
            abIn.append(row)        
    return nonAb

def getQ(m, nonAb, nonAbIn):
    Q = []
    for i, row in enumerate(nonAbIn):
        Q.append([])
        for col in nonAbIn:
            Q[i].append(m[row][col])
    return Q

def getR(m, nonAb, abIn, nonAbIn):
    R = []
    for i,row in enumerate(nonAbIn):
        R.append([])
        for col in abIn:
            R[i].append(m[row][col])
    return R

def getI(size):
    I = [[0 for col in range(size)]for row in range(size)]
    for i in range(size):
        I[i][i] = Fraction(1,1)
    return I


