def solve_case(n, original):
    if n == 2:
        cost_equal = abs(original[0] - original[1])
        cost_zero = original[0] + original[1]
        return min(cost_equal, cost_zero)
    
    min_cost = sum(original)  # All zeros baseline
    
    def is_valid(arr):
        """Check if array satisfies good conditions"""
        # A[0] = A[1] or A[0] = 0
        if arr[0] != 0 and arr[0] != arr[1]:
            return False
        
        # A[n-1] = A[n-2] or A[n-1] = 0
        if arr[n-1] != 0 and arr[n-1] != arr[n-2]:
            return False
        
        # A[i] = A[i-1] + A[i+1] or A[i] = 0 for 1 < i < n
        for i in range(1, n-1):
            if arr[i] != 0:
                if arr[i] != arr[i-1] + arr[i+1]:
                    return False
        
        return True
    
    def cost(arr):
        return sum(abs(original[i] - arr[i]) for i in range(n))
    
    # Collect unique values from original
    unique_vals = set(original)
    unique_vals.add(0)
    
    # Pattern 1: Generated sequences from (a, b)
    candidates = set([0])
    for val in unique_vals:
        candidates.add(val)
        # Add nearby values more aggressively
        for d in range(-5, 6):
            if val + d >= 0:
                candidates.add(val + d)
    
    for a0 in candidates:
        for a1 in candidates:
            arr = [a0, a1]
            for i in range(2, n):
                next_val = arr[i-1] - arr[i-2]
                if next_val < 0:
                    next_val = 0
                arr.append(next_val)
            
            if is_valid(arr):
                min_cost = min(min_cost, cost(arr))
    
    # Pattern 2: Repeating pattern [a, a, 0, a, a, 0, ...]
    for a in unique_vals:
        arr = []
        for i in range(n):
            if i % 3 == 2:
                arr.append(0)
            else:
                arr.append(a)
        
        if is_valid(arr):
            min_cost = min(min_cost, cost(arr))
    
    # Pattern 3: Variations with different starting positions
    for a in unique_vals:
        # [0, a, a, 0, a, a, ...]
        arr = []
        for i in range(n):
            if i % 3 == 0:
                arr.append(0)
            else:
                arr.append(a)
        if is_valid(arr):
            min_cost = min(min_cost, cost(arr))
        
        # [a, 0, a, a, 0, a, ...]
        arr = []
        for i in range(n):
            if i % 3 == 1:
                arr.append(0)
            else:
                arr.append(a)
        if is_valid(arr):
            min_cost = min(min_cost, cost(arr))
    
    return min_cost

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        print(solve_case(n, arr))

solve()
