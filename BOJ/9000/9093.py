num = int(input())
for i in range(num):
    string = input().split()
    for ch in string:
        print(''.join(reversed(ch)), end=' ')