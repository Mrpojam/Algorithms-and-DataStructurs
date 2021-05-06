count = [0 for i in range (1000)]
array = list(map(int, input().split()))
for a in array:
    count[a] += 1
answer = []
for i in range (1000):
    while count[i] > 0:
        answer.append(i)
        count[i] -= 1
print (answer)

# n = 1000
# each number can appear n times
# check every n possible number -> O(n^2)
