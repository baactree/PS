import datetime
a, b=input().split(" ")
now=datetime.datetime.strptime(a, '%Y-%m-%d')
b=int(b)
b-=1
now=now+datetime.timedelta(days=b)
now=now.strftime('%Y-%m-%d')
print(now)
