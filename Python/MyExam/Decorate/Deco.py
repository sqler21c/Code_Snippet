#-*- coding:utf-8 -*-

def quick_fix(func):
    def result(car_speed, speed_standard):
        if func(car_speed, speed_standard):
            print("적발!! 제한 속도 {}km/h초과 : ", format(car_speed-speed_standard))
            return True
        else:
            return False
    return result


#@quick_fix
def is_speeding(speed, standard):
    return speed > standard

is_speeding=quick_fix(is_speeding(150, 110))
is_speeding

print(is_speeding)
print(is_speeding(150,110))
#print(is_speeding(100, 110))