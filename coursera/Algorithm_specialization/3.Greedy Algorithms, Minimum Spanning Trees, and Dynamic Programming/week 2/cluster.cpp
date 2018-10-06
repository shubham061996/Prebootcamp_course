#include <iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Edge
{
    int nodes[2];
    int cost;
};
bool Edge_Compare(Edge e1, Edge e2) {return (e1.cost < e2.cost);} 

struct UnionNode
{
    int parent;
    int rank; 
};

int Find_Parent(UnionNode *nodes, int n, int th)
{
    if(nodes[th].parent == th)
           return th; 
    else
           return Find_Parent(nodes, n, nodes[th].parent);
    
}

void Union(UnionNode *nodes, int n, int th1, int th2)
{
    int root1 = Find_Parent(nodes, n, th1);
    int root2 = Find_Parent(nodes, n, th2);
    if(root1 == root2)
        return;

    if (nodes[root1].rank < nodes[root2].rank)
        nodes[root1].parent = root2;
    else if (nodes[root1].rank > nodes[root2].rank)
        nodes[root2].parent = root1;
    else
	{
		nodes[root2].parent = root1;
		nodes[root1].rank += 1; 
	}
       
}

int ClusterMaxSpace(vector<Edge>& E, int num_nodes, int k)
{
    UnionNode *nodes = new UnionNode[num_nodes]; 
	for(int i=0; i<num_nodes; i++)
    {
        nodes[i].parent = i;
        nodes[i].rank = 0; 
    }
    int maxspace = 0,nc = num_nodes,root1,root2,i = 0;
    
    sort(E.begin(), E.end(), Edge_Compare);	
	while(nc != k)
    {
        root1 = Find_Parent(nodes, num_nodes, E[i].nodes[0]);
        root2 = Find_Parent(nodes, num_nodes, E[i].nodes[1]);
        if (root1 != root2)
        {
            maxspace = E[i].cost; 
            nc--; 
        }
        
        Union(nodes, num_nodes, E[i].nodes[0], E[i].nodes[1]);
		i++;
    }
	delete nodes;
    return maxspace;
}

int main()
{
    ifstream infile;
    infile.open("clustering1.txt"); 
    string line;
    stringstream in;
    getline(infile, line);
    in << line;
    int num_nodes;
    in >> num_nodes;
    vector<Edge> Edges;
    in.clear();
    line.clear();
    Edge e;
    while(getline(infile, line))
    {
        in << line;
        in >> e.nodes[0] >> e.nodes[1] >> e.cost;
		e.nodes[0]--;
		e.nodes[1]--;
        Edges.push_back(e);
        in.clear();
        line.clear();
    }
	infile.close();
	int k = 4;
    int maxspace = ClusterMaxSpace(Edges, num_nodes, k-1); 
    cout << maxspace << endl;
    return 0;
}
