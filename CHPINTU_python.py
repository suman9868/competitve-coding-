"""
code written by: Suman Kumar
date: 8 March 2020
time: 2 AM
place: dwarka, New Delhi
"""


def start():
	t = int(input())
	for i in range(t):
		m, n = input().split(' ')
		# print('m n', m, n)
		m, n = int(m), int(n)
		F = input().split(' ')
		P = input().split(' ')
		# print('F   ', F)
		# print('P   ', P)
		F = [int(ele) for ele in F]
		P = [int(ele) for ele in P]
		# print('F   ', F)
		# print('P   ', P)
		dictt = {}
		for ele in F:
			dictt[ele] = 0
		for ele_F, ele_P in zip(F,P):
			dictt[ele_F] += ele_P 

		min_value = 999999
		for key,value in dictt.items():
			if value < min_value:
				min_value = value
		print(min_value)
		print('\n')

if __name__ == "__main__":
	start()