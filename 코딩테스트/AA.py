import sys
sys.stdin = open('input.txt','r')

t = int(input())

for test_case in range(1, t+1):

    a, num1, num2 = map(int , input().split())

    arr = [int(num) for num in input().split()]

    seen_1 = [21480000]*len(arr)
    seen_2 = [21480000]*len(arr)

    count_1=0
    res = 0
    index = 0

    for i in range(len(arr)):
        res = arr[i] % num1
        if res not in seen_1:
            count_1 +=1
            seen_1.append(res)
        else :
            index = count_1
            break

    for j in range(index, len(arr)):
        res = arr[j] % num2
        if res not in seen_1:
            index +=1 
            seen_1.append(res)
        else:
            break

    print(f"#{test_case} {index+1}")
            

'''
3                    // 테스트 케이스의 수
4 3 2                            // N = 4, P = 3, Q = 2 테스트 케이스 #1
2 2 2 2
5 5 3                            // N = 5, P = 5, Q = 3 테스트 케이스 #2
1 4 6 9 5
5 3 2                            // N = 5, P = 3, Q = 2 테스트 케이스 #3
1 2 3 4 5
[출력 예]
#1 3
#2 4
#3 4
'''
        


        
    


