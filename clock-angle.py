'''
Given a time, calculate the angle formed
between the hour and minute hands of a clock

input: 24h time (e.g. 17:30 or 5:30)
output: radians & degrees
------------------------------------------------------
libraries & input
------------------------------------------------------
'''
import math
H, m = 0, 0
while(True):
    time = input('enter time in 24h format (HH:MM): ')
    # splitting input into hours and minutes
    H, m = map(int, time.split(':'))
    # exit if out of range values
    if (H not in range(24)) or (m not in range(60)):
        print('range error. try again.')
        continue
    break
'''  
------------------------------------------------------
solution
------------------------------------------------------
'''
# total distance
clock = 2 * math.pi
# 24h to 12h
if H >= 12:
    h = H % 12
else:
    h = H
# speed = dist / time
speed_h = clock / 12
speed_m = clock / 60
# dist (in rad) = speed * time
dist_h = speed_h * (h + m/60)
dist_m = speed_m * m
# angle
angle = math.fabs(dist_h - dist_m)
'''
output
'''
print('angle b/w hands: ', round(angle, 2), ' rad or ',
      round(math.degrees(angle), 2), '°', sep='')
'''
------------------------------------------------------
examples
------------------------------------------------------

1) enter time in 24h format (HH:MM): 2:10
angle b/w hands: 0.09 rad or 5.0°

2) enter time in 24h format (HH:MM): 13:60
range error. try again.
enter time in 24h format (HH:MM): 6:00
angle b/w hands: 3.14 rad or 180.0°
'''
