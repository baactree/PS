import hashlib
h=hashlib.sha384()
temp=input()
temp=str(temp).encode('utf-8')
h.update(temp)
hex=h.hexdigest()
print(hex)