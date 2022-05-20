def handle_area():
	print("변환할 값의 단위를 입력하세요 :\n(1)평\n(2)제곱미터")
	command = int(input())
	print("변환할 값을 입력하세요")
	val = int(input())
	if command == 1:
		print("{}평은 {}제곱미터입니다.".format(val, val * 3.3))
		return
	elif command == 2:
		print("{} 제곱미터는 {}평입니다.".format(val, val / 3.3))
		return
	else :
		print("입력값이 잘못되었습니다. 다시 시도하세요.")
		return

def handle_length():
	return


while True:
	print("실행할 기능의 번호를 입력하세요:\n(1)면적 변환 기능\n(2)길이 변환 기능\n(Q or q)프로그램 종료")
	command = input()
	if command == 'Q' or command == 'q':
		print("프로그램을 종료합니다.")
		break
	if command == 1:
		handle_area()
	elif command == 2:
		handle_length()
	else:
		print("잘못된 번호를 입력하셨습니다. 제시된 번호 중에서 선택해주세요.")

