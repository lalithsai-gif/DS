import time
import random
random.seed(42)

s1=time.time()
I=[1,2,3,4]
wt=[5,10,8,15]
V=[50,50,96,120]
def KnapSack_DP(n,W):
    F=[[0]*(W+1) for _ in range(n+1)]
    for i in range(1,n+1):
        for w in range(W+1):
            if(wt[i-1]>w):
                F[i][w]=F[i-1][w]
            else:
                F[i][w]=max(F[i-1][w],F[i-1][w-wt[i-1]]+V[i-1])
    return F[n][W]
print("MAx Profit :",KnapSack_DP(len(I),25))
e1=time.time()

print("Execution Time: ",(e1-s1))



s2 = time.time()

Item = [1, 2, 3, 4]
weight = [5, 10, 8, 15]
Profit = [50, 50, 96, 120]

C=25
n=len(Item)

B=0
bestSet=[]
order=sorted(range(n),key=lambda i:Profit[i]/weight[i],reverse=True)

Item = [Item[i] for i in order]
weight = [weight[i] for i in order]
Profit = [Profit[i] for i in order]

Rate = [Profit[i] / weight[i] for i in range(n)]


def BoundingCond(i, cW, cP):
    global B

    bound = cP
    remaining = C - cW

    for j in range(i, n):
        if weight[j] <= remaining:
            bound += Profit[j]
            remaining -= weight[j]
        else:
            bound += remaining * Rate[j]
            break

    return bound > B


def KnapScak_BB(cI, i, cW, cP):
    global B, bestSet

    if cP>B:
        B=cP
        bestSet = cI.copy()

    if i >= n or cW == C:
        return

    if not BoundingCond(i, cW, cP):
        return

    if cW + weight[i] <= C:
        KnapScak_BB(cI + [Item[i]],i + 1,cW + weight[i],cP + Profit[i])

    KnapScak_BB(cI, i + 1, cW, cP)

KnapScak_BB([], 0, 0, 0)

e2=time.time()

print("Selected Items:",bestSet)
print("Maximum Profit:",B)
print("Execution Time:",e2 - s2)


"""
s2=time.time()
Item=[1,2,3,4]
weight=[5,10,8,15]
Profit=[50,50,96,120]
Rate=[10,5,12,8]
C=25
n=4
B=0
maxR=[max(Rate[i:]) for i in range(n)]

def BoundingCond(i,cW,cP):
    if i>=n:
        return False
    if cP+(C-cW)*maxR[i]>B:
        return True
    return False
def KnapScak_BB(cI,i,cW,cP):
    global B
    if(i>=n or cW==C):
        if(cP>B):
            B=cP
            print(cI,cP)
        return 
    if cW+weight[i]<=C:
        if BoundingCond(i,cW,cP):
            KnapScak_BB(cI+[Item[i]],i+1,cW+weight[i],cP+Profit[i])

    if BoundingCond(i+1,cW,cP):
        KnapScak_BB(cI,i+1,cW,cP)

KnapScak_BB([],0,0,0)
e2=time.time()

print("Execution time: ",(e2-s2))
"""