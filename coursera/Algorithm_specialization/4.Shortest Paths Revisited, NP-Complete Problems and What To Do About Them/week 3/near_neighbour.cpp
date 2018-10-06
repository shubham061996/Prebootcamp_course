#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
double length = 0.0;

double eucl_dist(int current,int other,vector<pair<double,double>> &cities){
	double x,y,z;
    x = cities[current].first - cities[other].first;
    x = x*x;
    y = cities[current].second - cities[other].second;
   	y = y*y;
    z = x+y;
    return z;
}

int find_next(int nodes,int current,vector<pair<double,double>> &cities,vector<int> &vis)
{

    double nearest=INF;
    int next = -1;
    for(int j=0;j<nodes;j++)
    {
        double dis = eucl_dist(current,j,cities);
        if(dis < nearest && vis[j]==0)
        {
            nearest = dis;
            next = j;
        }
    }
    length = length + sqrt(nearest);
    return next;
}

void TSP(int nodes,vector<pair<double,double>> &cities,vector<int> &vis){
    int curr = 0;
    vis[curr] = 1;

    for(int i=1;i<nodes;i++)
    {
        vis[curr] = 1;
        curr = find_next(nodes,curr,cities,vis);
    }

    double xx = pow(cities[curr].first - cities[0].first,2);
    double yy = pow(cities[curr].second - cities[0].second,2);
    length += sqrt(xx + yy);
}
int main()
{
    ifstream infile;
    infile.open("nn.txt"); 
    string line;
    stringstream in;
    getline(infile, line);
    in << line;
    int nodes;
    in >> nodes;
    vector<pair<double,double>> cities;
    vector<int> vis(nodes,0);
    in.clear();
    line.clear();
    int n;
    double a,b;
    int i=0;
    while(getline(infile, line))
    {
        in << line;
        in >> n >> a >> b;
		cities.push_back(make_pair(a,b));
        vis[i++]=0;		
        in.clear();
        line.clear();
    }
	infile.close();
	TSP(nodes,cities,vis);
    cout<<"shortest cycle is = " << long(length)<< endl;
}
