def solve(n, s, st):
    if n == 0:
        s.add("".join(sorted(st)))
    elif n < 0:
        return
    
    st += '1'
    solve(n-1, s, st)
    st = st[:-1:]

    st += '2'
    solve(n-2,s, st)
    st = st[:-1:]
    
    st += '3'
    solve(n-3, s, st)
    st = st[:-1:]

    return s

ans = solve(12, set(), "")
print(len(ans))
print(ans)
