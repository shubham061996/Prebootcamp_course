#include <bits/stdc++.h>
using namespace std;
long long knapsack(vector<int> &weight,vector<int> &value,int items,int W){
    vector<long long > t;
	t.resize(W+1);
    for(int j=0; j<=W; j++) 
    	t[j]=0;
    
    for(int x = 1; x <=items; x++)
    {
        for(int i = W; i >= 0; i--){
	         if(weight[x]<=i && t[i]<(value[x]+t[i-weight[x]]))
	            t[i] = value[x]+t[i-weight[x]];
        }
    }
    return t[W];

}

int main()
{
	ifstream fp;
	 fp.open("knapsack1.txt");
	 int W ,items;
     fp >> W >>items;
     vector<int>weight(items +1);
     vector<int> value(items + 1);
  	for(int i = 1;i <=items;i++){
        fp>>value[i]>>weight[i];
	}
	fp.close();
	
	cout<<knapsack(weight,value,items,W)<<endl;
    return 0;
}
