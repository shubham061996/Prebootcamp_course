import math
import itertools

INF = 99999999
def dpsol(nodes,dist):
    dp = {}
    cityno = []
    for i in range(1,nodes+1):
        cityno.append(i)


    for i in itertools.combinations(cityno, 1):
        dp[i] = dp.get(i, {})
        if i[0] == 1:
            dp[i][i[0]] = 0
        else:
            dp[i][i[0]] = INF

    for i in range(2, nodes+1):
        print (i)
        for j in itertools.combinations(cityno, i):
            print (i,j)
            dp[j] = dp.get(j, {})
            for element in j:
                current_set = set(j)
                current_set.discard(element)
                sorted_set = tuple(sorted(current_set))
                
                mini1 = INF
                for k in sorted_set:
                    y = dp[sorted_set].get(k, INF)  + dist[k-1][element-1]
                    if y < mini1:
                        mini1 = y
                dp[j][element] = y
                print (j,element,y)
                     

    mini = INF
    for j in range(1,nodes+1):
        x = dp[tuple(cityno)][j] + dist[j-1][0]
        if x < mini:
            mini = x

    return mini


def main():
    
    fp = open("tsp.txt",'r')
    
    nodes = int(fp.readline())

    cities = []
    for line in fp.readlines():
        xandy = line.split()
        x = float(xandy[0])
        y = float(xandy[1])
        cities.append((x, y))

    dist = []
    for j in range(nodes):
        dist.append([])
        for i in range(nodes):
            dist[j].append(math.sqrt((cities[i][0] - cities[j][0])**2 + (cities[i][1] - cities[j][1])**2))

    mini = dpsol(nodes,dist)
    
    print ("Minimum Distance of The Route :")
    print (int(mini))
    


if __name__ == '__main__':
    main()
