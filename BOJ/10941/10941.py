import base64
s=input()
#s=str(s).encode('utf-8')
out=base64.b16decode(s)
out=str(out)
print(out[2:-1])
