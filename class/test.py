from random import *
lst = [3,4,1,2,5,7]
#size = randint(1, 100)
#for num in range(size):
#	i = randint(0, 100)
#	if i not in lst:
#		lst.append(i)
#	else:
#		size -= 1
#shuffle(lst)
print(lst)

while (True):
	try:
		k = int(input("최대 합을 구할 인접 범위 k를 입력하세요."))
		if (k < 2 or k > len(lst)):
			print("프로그램을 종료합니다")
			break;
		max = 0
		for i in range(len(lst)):
			if i + k > len(lst):
				break;
			sum = 0
			for j in range(i, i+k):
				sum += lst[j]
			if sum > max:
				max = sum
		print("최대 합은 {}입니다.".format(max))

	except Exception as e:
		print(e)
		print("잘못된 값을 입력하셨습니다. 2 이상 정수를 입력하세요.")
