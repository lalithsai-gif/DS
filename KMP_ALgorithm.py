def buildLPS(P):
    n=len(P)
    LPS=[0]*n

    leng=0
    i=1

    while(i<n):
        if P[i]==P[leng]:
            leng+=1
            LPS[i]=leng
            i+=1
        else:
            if leng!=0:
                leng=LPS[leng-1]
            else:
                LPS[i]=0
                i+=1
    return LPS

def KMP_Algorithm(A,B):
    n=len(A)
    m=len(B)

    if m==0:
        return 0

    LPS=buildLPS(B)
    i=0
    j=0

    while(i<n):

        if(A[i]==B[j]):
            i+=1
            j+=1

        if(j==m):
            return (i-j)
        elif(i<n and A[i]!=B[j]):
            if(j!=0):
                j=LPS[j-1]
            else:
                i+=1
    return -1

print(KMP_Algorithm('Lalith','ali'))
print(KMP_Algorithm("ABABDABACDABABCABAB", "ABABCABAB"))
print(KMP_Algorithm("AAAAA", "AAA"))
print(KMP_Algorithm("ABCDEFG", "XYZ"))
print(KMP_Algorithm("ABC", ""))
# 1
# 10
# 0
# -1
# 0