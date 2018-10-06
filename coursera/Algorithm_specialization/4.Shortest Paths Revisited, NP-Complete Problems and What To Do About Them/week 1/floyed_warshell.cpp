#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int main()
{
	// Read the file	
	ifstream f ;
	//f.open("g1.txt");
//	f.open("g2.txt");
	f.open("g3.txt");
	int vertices = 0;
	int edges = 0;
    f>>vertices>>edges;
	vector<vector<int> >distance(vertices + 1);

    for(int i = 1;i < (vertices + 1);i++){
    	distance[i].resize(vertices + 1,INF);
    }
    
    for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(i == j)
    			distance[i][j] = 0;
    	}
    }

    int s;
    int d;
    int w;

  	for(int i = 1;i <=edges;i++){
        f>>s>>d>>w;
		distance[s][d] = w;
	}
	f.close();


	for (int k = 1; k <=vertices; k++)
    {
        
        for (int i = 1; i <=vertices; i++)
        {
           
            for (int j = 1; j <=vertices; j++)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
	int cycle = 0;

    for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(i == j & distance[i][j] < 0){
    			cycle = 1;
    		}
    	}
    }
    
    if(cycle == 1){
    	cout << "Cycle Found" << endl;
	}
	else{
		int min = INF;
		for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(distance[i][j] < min && i!=j){
    			min = distance[i][j];
    		}
    	}
    }
    cout << " Shortest Shortes Path is : "<< min<<endl;

	}

    return 0;
}

