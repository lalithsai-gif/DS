def krushkal_algorithm(n,edges):
    parent=list(range(n))
    rank=[0]*n

    def find(x):
        if(parent[x]!=x):
            parent[x]=find(parent[x])
        return parent[x]

    def find_Union(x,y):
        root_u=find(x)
        root_v=find(y)

        if root_u==root_v:
            return False

        if rank[root_u]<rank[root_v]:
            parent[root_u]=root_v
        elif rank[root_u]>rank[root_v]:
            parent[root_v]=root_u
        else:
            parent[root_u]=root_v
            rank[root_u]+=1

        return True

    edges.sort(key=lambda x:x[2])

    mst=[]
    tot_cost=0

    for u,v,w in edges:
        if find_Union(u,v):
            mst.append((u,v,w))
            tot_cost+=w

        if len(mst)==n-1:
            break

    print("MST:")
    for u,v,w in mst:
        print(u,"-",v,":",w)
    print("minimum mst cost:",tot_cost)

n=4

edges=[
    (0,1,10),
    (0,2,6),
    (0,3,5),
    (1,3,15),
    (2,3,4)
]

krushkal_algorithm(n,edges)



