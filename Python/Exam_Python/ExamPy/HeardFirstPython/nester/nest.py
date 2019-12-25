"""
하하 테스트
"""

def print_lol(each_item):
	""" 하하 하 테스트 """
	for each_items in each_item:
		if(isinstance(each_items, list)):
			print_lol(each_items)
		else:
			print(each_item)
