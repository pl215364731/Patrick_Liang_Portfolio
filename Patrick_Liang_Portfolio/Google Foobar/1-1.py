def solution(string):
    newString = ""
    for c in string:
        lowerCase = False
        for i in range(97,123):
            if c == chr(i):
                lowerCase = True
                newString += chr(122 - i + 97)
        if lowerCase == False:
            newString += c
    return newString

print(solution("1234poop the poop team leader! Justin poopoo"))

