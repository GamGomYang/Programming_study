from collections import deque
from functools import cmp_to_key
def solution(numbers):
    answer = ''
    numbers = list(map(str,numbers))

    def compare(a,b):
        if a+b > b+a:
            return -1
        elif a+b < b+a:
            return 1
        else:
            return 0
    #cmp_to_key 에서는 -1 , 0 , 1 이 와야한다.
        
    numbers.sort(key = cmp_to_key(compare))
    
    answer = ''.join(numbers)
    

    return "0" if answer[0] == '0' else answer