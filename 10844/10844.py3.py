def total_cases(n):
    D = [[0 for row in range(10)] for col in range(n+1)] # D[i][j] 형식의 2차원 배열 생성

    # 예외 2: 가정이 거짓
    for j in range(1, 10):
        D[1][j] = 1

    for i in range(2, n+1):
        for j in range(10):
            if j == 0:  # 예외 1-1: 마지막 자리가 0
                D[i][0] = D[i-1][1]
            elif j == 9: # 예외 1-2: 마지막 자리가 9
                D[i][9] = D[i-1][8]
            else: # 일반적인 케이스
                D[i][j] = (D[i-1][j-1] + D[i-1][j+1])
    return sum(D[n])
print(total_cases(int(input()))%1000000000)