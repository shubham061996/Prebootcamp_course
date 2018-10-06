import networkx
G = networkx.DiGraph()

fp = open("C:\Users\user\Desktop\desktop screen\course_revisited\sat6.txt")

num_variables = int(fp.readline())

G.add_nodes_from(range(1,num_variables*2+1))
#print(G.number_of_nodes())
for line in fp.readlines():
    var1,var2 = map(int,line.split())
    if(var1<0):
        var1 = abs(var1) + num_variables
    
    if(var2 < 0):
        var2 = abs(var2) + num_variables
        
    if(var1 > num_variables):
        firstedge = var1 - num_variables
    else:
        firstedge = var1 + num_variables
        
    if(var2 > num_variables):
        secondedge = var2 - num_variables
    else:
        secondedge = var2 + num_variables
        
    G.add_edge(firstedge,var2)
    G.add_edge(secondedge,var1)

scc = networkx.strongly_connected_components(G)

compatibility = True

for c in scc:
    for x in c:
        if ( (x > num_variables) and  ((x - num_variables) in c) ):
            compatibility = False
            break
        if( (x < num_variables) and ((x + num_variables) in c) ):
            compatibility = False
            break 
    
    if(not compatibility):
        break        

if(compatibility):
    print('satisfied')
else:
    print('not satisfied')