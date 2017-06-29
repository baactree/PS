import hashlib
m=hashlib.new('ripemd160')
s=input()
s=str(s).encode('utf-8')
m.update(s)
t=m.hexdigest()
print(t)
