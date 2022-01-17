def chaned_matrix(p, i, j):
    if i == j:
        return 0
    ans = 10000009
    for k in range(i, j):
        count = (chaned_matrix(p, i, k) + chaned_matrix(p, k + 1, j) + p[i-1] * p[k] * p[j])
        if count < ans:
            ans = count

    return ans
