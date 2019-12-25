# decompose_hangul1.py
c = '한'
code = ord(c) - 0xac00		# 수치로 형변환
chosung = code // (21*28)	# 초성
jungsung = (code - chosung*21*28) // 28	# 중성
jongsung = (code - chosung*21*28 - jungsung*28)	# 종성
print(chosung, jungsung, jongsung)  
