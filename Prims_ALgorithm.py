def Prims(V,E):
    n=len(V)
    key=[float('inf')]*n
    parent=[-1]*n
    visited=[False]*n

    index={vertex: i for i,vertex in enumerate(V)}
    adj={v:[] for v in V}
    for edge,wt in E.items():
        u,v=edge[0],edge[1]
        adj[u].append((v,wt))
        adj[v].append((u,wt))

    key[0]=0
    for _ in range(n):
        U=-1
        for i in range(n):
            if(not visited[i] and (U==-1 or key[i]<key[U])):
                U=i
        if(U==-1 or key[U]==float("inf")):
            print("MST Not Exists")
            return 
        visited[U]=True

        for v,wt in adj[V[U]]:
            j=index[v]
            if(not visited[j] and wt<key[j]):
                key[j]=wt
                parent[j]=U
        print("MST:\n")
        tot=0
        for i in range(n):
            if parent!=-1:   
                print(V[parent[i]],"-",V[i]+":",key[i])
                tot+=key[i]
        print("Total weight of the graph is:",tot)

V=['A','B','C','D','E','F']
E={'AB':4,'AC':3,'BC':1,'BD':2,'CD':4,'CE':5,'DE':2,'DF':3,'EF':6}
Prims(V,E)
