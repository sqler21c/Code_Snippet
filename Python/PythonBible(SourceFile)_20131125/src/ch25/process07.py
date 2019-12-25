# process07.py
from multiprocessing import Pool

def f(x):
    for k in range(10**7):  # 시간 보내기
        pass
    return x*x

if __name__ == '__main__':
    with Pool(processes=4) as pool:    # start 4 worker processes
        r1 = pool.apply_async(f, [10]) # 비 동기적으로 "f(10)" 시작
        r2 = pool.apply_async(f, [20]) # 비 동기적으로 "f(30)" 시작
        r3 = pool.apply_async(f, [30]) # 비 동기적으로 "f(30)" 시작
        r4 = pool.apply_async(f, [40]) # 비 동기적으로 "f(30)" 시작
        print(r1.get(timeout=2))       # 연산 후 출력
        print(r2.get(timeout=2))       # 동시 출력
        print(r3.get(timeout=2))       # 동시 출력
        print(r4.get(timeout=2))       # 동시 출력
        print(r1, dir(r1), r1.ready())
