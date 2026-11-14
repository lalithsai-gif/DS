class HM:    
    def Hamiltonian_Cycle(self,graph):
        n=len(graph)

        path=[0]*n
        visited=[False]*n

        visited[0]=True
        path[0]=0

        def solve(p):

            if(p==n):
                if(graph[path[p-1]][0]==1):
                    return True

                return False

            for v in range(1,n):
                if(graph[path[p-1]][v]==1 and not visited[v]):
                    visited[v]=True
                    path[p]=v
                    if(solve(p+1)):
                        return True
                    visited[v]=False
            return False
        if solve(1):
            print("Hamiltonian cycle and Hamiltonian Path also exists:")
            print("->".join(map(str,path+[0])))
        else:
            print("Hamiltonian Cycle is not Exists")

h=HM()


graph=[
    [0,1,1,1],
    [1,0,1,0],
    [1,1,0,1],
    [1,0,1,0]
]
h.Hamiltonian_Cycle(graph)
