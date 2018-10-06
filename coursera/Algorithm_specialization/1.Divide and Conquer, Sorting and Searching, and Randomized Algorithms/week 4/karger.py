import random
Edges_List = []
Nodes_List = set()
for l in open('C:\Users\user\Desktop\desktop screen\course_revisited\kargerMinCut.txt'):
    x = l.strip().split()
    Nodes_List.add(x[0])
    for b in x[1:]:
        Edges_List.append([x[0],b])
        Nodes_List.add(b)

ans = 300000
for t in xrange(len(Nodes_List)/2):
    G=Edges_List
    N=set(Nodes_List)
    while len(N)!=2: 
        Temp_Edge_List = []
        a,b = G[random.randint(0,len(G)-1)] 
        for c,d in G:
            if c==b: c=a 
            if d==b: d=a 
            if c==d: continue
            Temp_Edge_List.append([c,d]) 
        N.remove(b) 
        G = Temp_Edge_List
        

    ans = min(ans,len(G)/2)
print ans