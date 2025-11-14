def compute_f(s):

    balance = 0
    max_balance = 0
    for char in s:
        if char == '(':
            balance += 1
        else:  
            balance -= 1
        max_balance = max(max_balance, balance)
    return max_balance

def solve(a):
    
    f_value = compute_f(a)
    return '(' * f_value + ')' * f_value

t = int(input())

for _ in range(t):
    a = input().strip()
    b = solve(a)
    print(b)
