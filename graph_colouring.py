def is_safe_color(graph,colors,n,vertex,c):
    for i in range(n):
        if(graph[vertex][i]==1 and colors[i]==c):
            return False
    return True

def graph_coloring(graph,colors,n,m,vertex):
    if vertex==n:
        return colors.copy()

    for c in range(1,m+1):
        if(is_safe_color(graph,colors,n,vertex,c)):
            colors[vertex]=c

            result=graph_coloring(graph,colors,n,m,vertex+1)

            if result:
                return result

            colors[vertex]=0

    return None

n=4
m=3

graph=[
    [0,1,1,1],
    [1,0,1,0],
    [1,0,1,1],
    [1,0,1,0]
]

colors=[0]*n

ans=graph_coloring(graph,colors,n,m,0)

if ans:
    print("Solution is ",ans)
else:
    print("Sol is not exits for the given graph")