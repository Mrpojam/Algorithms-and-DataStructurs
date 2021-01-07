def part (A, start, end):
    i = start - 1
    piv = A[end]
    for j in range (start, end):
        if A[j] <= piv:
            i += 1
            A[j], A[i] = A[i], A[j]
    A[i+1], A[end] = A[end], A[i+1]
    return i+1

def quick (A, start, end):
    if len(A) == 1:
        return A
    if start < end:
        piv = part(A, start, end)
        quick(A, start, piv-1)
        quick(A, piv+1, end)

arr = list(map(int, input().split()))
quick(arr, 0, len(arr)-1)
print(arr)

#like merg sort quick sort is a devide and conquer algorithm
#every step we take the last index as pivot and devide the list and sort it
#Time order => O(N2) (if we choose pivote random o(n2) > time > o(nlog) by expirience)
