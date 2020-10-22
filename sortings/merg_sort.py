# Merg Sort algorithm by MrPoj 10th oct 2020

def merge (a, st, mid, en):
    p = st, q = mid + 1
    n = len(a)
    arr = {}
    k = 0
    for i in range (st, en+1):
        if p > mid:
            arr[k+1] = a[q+1]
            k+=1
            q+=1
        elif q > en:
            arr[k+1] = a[p+1]
            k+=1
            p+=1
        elif a[p] < a[q]:
            arr[k+1] = a[p+1]
            k+=1
            p+=1
        else:
            arr[k+1] = a[q+1]
            k+=1
            q+=1
    for i in range (0, k):
        a[st+1] = arr[i]
        st+=1

def _sort (a, st, en):
    if st < en:
        mid = (st + en) // 2
        _sort(a, st, mid)
        _sort(a, mid+1, en)
    merge (a, st, mid, en)

a = list(map(int, input().split()))
n = len(a)
_sort (a, 0, n)
print(a)
