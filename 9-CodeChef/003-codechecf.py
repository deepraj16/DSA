# cook your dish here
def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    T = int(data[0])
    index = 1
    
    for _ in range(T):
        N = int(data[index])
        index += 1
        
        if N % 2 == 0:
            print("NO")
        else:
            print("YES")
            w = (N - 1) // 2
            res = [[0] * N for _ in range(N)]
            
            for i in range(N):
                for j in range(1, w + 1):
                    res[i][(i + j) % N] = 1
                    res[(i + j) % N][i] = 0
            
            for row in res:
                print(''.join(map(str, row)))

solve()
