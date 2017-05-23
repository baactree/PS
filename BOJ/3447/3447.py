while(1):
    s=input()
    a=[]
    for i in range(len(s)):
        if len(a)<2:
            a.append(s[i])
        elif s[i]=='G':
            q=a.pop()
            w=a.pop()
            if q=='U' and w=='B':
                continue
            a.append(w)
            a.append(q)
            a.append('G')
        else:
            a.append(s[i])
    ans=""
    for i in a:
        ans+=i
    print(ans)



