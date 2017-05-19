import hashlib
h=hashlib.sha256()
temp=input()
temp=str(temp).encode('utf-8')
h.update(temp)
hex=h.hexdigest()
print(hex)
