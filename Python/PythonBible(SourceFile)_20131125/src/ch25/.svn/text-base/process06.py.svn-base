# process06.py
from multiprocessing import Process, Manager

def f(d, l, ns):
    d[1] = '1'
    d['2'] = 2
    d[0.25] = None
    l.reverse()
    ns.x *= 10
    ns.y *= 10
    ns.stack.append(1)  # 주의!!
    print('ns.stack=', ns.stack)    # 결과 확인

if __name__ == '__main__':
    manager = Manager()     # 매니저 서버 생성
    d = manager.dict()      # 사전 자료 생성
    l = manager.list(range(10)) # 리스트
    ns = manager.Namespace()    # 네임스페이스
    ns.x = 1
    ns.y = 2
    ns.stack = []       # 주의!!

    p = Process(target=f, args=(d, l, ns))
    p.start()
    p.join()

    print('d=', d)
    print('l=', l)
    print('ns.x={0.x} ns.y={0.y}'.format(ns))
    print('ns.stack=', ns.stack)    # 결과 확인
