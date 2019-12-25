import sqlite3

conn = sqlite3.connect("pets.db")   # 테이블 생성/오픈
cursor = conn.cursor()

# 버전 확인
print(sqlite3.sqlite_version_info)
version = cursor.execute('SELECT sqlite_version()').fetchone()[0]
print(version)

# 테이블 삭제
cursor.execute("""DROP TABLE IF EXISTS pets""")
conn.commit()

# 테이블 생성
cursor.execute('''CREATE TABLE pets (
		name VARCHAR(20),
		owner VARCHAR(20),
		species VARCHAR(20),
		sex CHAR(1),
		birth DATE,
		death DATE)''')

# 데이터 추가
cursor.execute("INSERT INTO pets VALUES('Fluffy', 'Harold', 'cat', 'f', '1993-02-04', NULL)")

cursor.executescript("""
INSERT INTO pets VALUES('Claws', 'Gwen', 'cat', 'm', '1994-03-17', NULL);
INSERT INTO pets VALUES('Buffy', 'Harold', 'dog', 'f', '1989-05-13', NULL);
INSERT INTO pets VALUES('Fang', 'Benny', 'dog', 'm', '1990-08-27', NULL);
INSERT INTO pets VALUES('Bowser', 'Diane', 'dog', 'm', '1998-08-31', '1995-07-29');
INSERT INTO pets VALUES('Chirpy', 'Gwen', 'bird', 'f', '1998-09-11', NULL);
INSERT INTO pets VALUES('Whistler', 'Gwen', 'bird', 'f', '1997-12-09', NULL);
INSERT INTO pets VALUES('Slim', 'Benny', 'snake', 'm', '1996-04-29', NULL);
""")

conn.commit()

# 데이터 검색
cursor.execute('select * from pets')
print(cursor.fetchone())
print(cursor.fetchmany(3))
print(cursor.fetchall())

# 데이터 검색
cursor.execute('select * from pets')
for row in cursor:
    print(row)

# 데이터 검색
for row in cursor.execute('select * from pets'):
    print(row)

# 테이블 삭제
#cursor.execute('DROP TABLE pets')

#cursor.close()
