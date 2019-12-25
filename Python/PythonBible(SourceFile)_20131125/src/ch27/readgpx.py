# readgpx.py

import xml.etree.ElementTree as ET

tree = ET.parse('sample.gpx')
root = tree.getroot()

# bounds 엘리먼트(metadata 안에 있다)
bounds = root.findall('.//{http://www.topografix.com/GPX/1/1}bounds')[0]

# 속성 값 읽기
maxlat = float(bounds.get('maxlat'))
maxlon = float(bounds.get('maxlon'))
minlat = float(bounds.get('minlat'))
minlon = float(bounds.get('minlon'))

print('maxlat=', maxlat)
print('maxlon=', maxlon)
print('minlat=', minlat)
print('minlon=', minlon)
print()

# 웨이 포인트 이름과 위치 출력하기
wpts = root.findall('.//{http://www.topografix.com/GPX/1/1}wpt')
for wpt in wpts:
    name = wpt.find('{http://www.topografix.com/GPX/1/1}name').text
    lat = wpt.get('lat')
    lon = wpt.get('lon')
    print(name, lat, lon)    
print()

# 트랙 세그먼트 읽기
trksegs = root.findall('.//{http://www.topografix.com/GPX/1/1}trkseg')

for trkseg in trksegs:
    # 트랙 세그먼트에서 트랙 포인트 읽기
    trkpts = trkseg.findall('.//{http://www.topografix.com/GPX/1/1}trkpt')
    print('트랙 포인트 수 :', len(trkpts))
    for trkpt in trkpts:    # 트랙 포인트 시간 위도 경도 고도 출력
        lat = float(trkpt.get('lat'))
        lon = float(trkpt.get('lon'))
        ele = float(trkpt.find('{http://www.topografix.com/GPX/1/1}ele').text)
        tm = trkpt.find('{http://www.topografix.com/GPX/1/1}time').text
        print(tm, lat, lon, ele)
