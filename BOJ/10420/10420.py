import datetime

d = datetime.date(2014, 4, 2)
n = input()
n = int(n)
now = d + datetime.timedelta(days=n-1)
print(now)
