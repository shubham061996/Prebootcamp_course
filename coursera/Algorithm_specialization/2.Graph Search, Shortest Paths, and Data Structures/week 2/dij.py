def make_graph(filename):
    f = open(filename, 'r')
    line_list = f.readlines()
    G={}
    for line in line_list:
        t = line.split()
        node = int(t[0])
        G[node]={}
        for element in t[1:]:
            #print(element)
            des,dis=map(int,element.split(','))
            G[node][des]=dis

    f.close()
    return G

def dijkstra(G, start, end=None):
    D = {}	     
    P = {}	     
    Q = {}                
    
    for vertex in G:
        Q[vertex] = float("inf")
        P[vertex] = None
    
    Q[start] = 0
    
    
    while(len(Q)):
        u = min(Q, key=lambda k: Q[k])
        D[u] = Q[u]
        if u == end: break

        for w in G[u]:
            vwLength = D[u] + G[u][w]
            if w not in Q or vwLength < Q[w]:
                Q[w] = vwLength
                P[w] = u
                
        del Q[u]
    

    return D, P
    

G = make_graph('C:\Users\user\Desktop\desktop screen\course_revisited\Data.txt')
lst = [7, 37, 59, 82, 99, 115, 133, 165, 188, 197] # a list of all the desired ending vertices
for v in lst:
    D, _ = dijkstra(G, 1, v)
    if v != lst[-1]:
        print(D[v])
    else:
        print(D[v])
    
