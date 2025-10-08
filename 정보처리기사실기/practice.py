# x ,y = input('입력 : ').split('-')

# a = ['abc123', 'def456', 'ghi789']
# a.append(x)
# a.append(y)

# a.remove('def456')
# print(a[1][-3:],a[2][:-3],sep = ',')
# # 뒤에서 -3 : e뒤에서 세자리 :-3 앞에서 세자리
# for i in range(3,6):
#     print(i,end = ' ')

# 문자열 출력
# a = {'apple', 'lemon', 'banana'}
# a.update({'kiwi' , 'banana'})
# a.remove('lemon')
# a.add('apple')
# for i in a :
#     print("과일명: %s " % i)

# # 람다식  -  수학식
# def func(x):
#     return x*x-3
# printf(func(10))

# #이것을 람다식으로 바꾸면?
# func = lambda x : x*x-3
# print(func(10))

# TestList= [1,2,3,4,5]
# TestList= list(map(lambda num : num +100 , TestList))
# print(TestList)


# a = "remember november"
# b = a[:3] + a[12:16]
# c = "r and %s" % "STR"
# print(b+c)

# a,b = 100, 200
# print(a == b)

# a = 100
# result =0
# count =0

# for i in range(1,3):
#     result = a>>i
#     print(i, result)
#     result = result+ i
#     print(i, result) 
# print(result)

# class good:
#     li = ["seoul", "kyeonggi", "inchon", "deajeon", "deagu", "pusan"]

# g = good()
# str01 = ' '
# for i in g.li:
#     str01 = str01 + i[0]

# print(str01)

# lol = [[1,2,3],[4,5],[6,7,8,9]]
# print(lol[0])
# print(lol[2][1])

# for sub in lol:
#     for item in sub:
#         print(item, end = '')
#     print()


# def fnCalculation(x,y):
#     result = 0
#     for i in range(len(x)):
#         temp = x[i:i+len(y)]
#         if temp == y:cd
#             result += 1
#     return result

# a = "abdcabcabca"
# pa = "ab"
# pb = "ca"
# out = f"ab{fnCalculation(a,pa)}ca{fnCalculation(a,pb)}"
# print(out)    

