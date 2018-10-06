#include<bits/stdc++.h>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define MAX 100005
#define mod 10000


int main(){
	
	int lines = 0;
    string line;
 
    ifstream file("Median.txt");
    while (getline(file, line))
        lines++;
 	
	freopen("Median.txt", "r", stdin);
	
	vector<int> input;
	
	int temp;
	
	for(int i=0;i<lines;i++){
		sd(temp);
		input.pb(temp);
	}
	
	priority_queue<int, vector<int>, greater<int> > min_heap;  
    priority_queue<int> max_heap;  
    
    int res = 0;
    
    if(input[0]>input[1]){
    	max_heap.push(input[1]);
    	min_heap.push(input[0]);	
	}
	else{
		max_heap.push(input[0]);
    	min_heap.push(input[1]);	
	}

  	res = (res + input[0])%mod;
  	res = (res + max_heap.top())%mod;
  	
  	for(int i=2;i<lines;i++){


  		if(input[i]<max_heap.top())  
            max_heap.push(input[i]);  
        else  
            min_heap.push(input[i]);
	  
	  
	  
		if(min_heap.size()>max_heap.size()&&(min_heap.size()-max_heap.size()>1)){  
				
			temp = min_heap.top();    
	        max_heap.push(temp);  
	        min_heap.pop();
	    }  
	    else if(max_heap.size()>min_heap.size()&&(max_heap.size()-min_heap.size()>1)){
			
			temp = max_heap.top();  
	        min_heap.push(temp);  
	        max_heap.pop();
		}
	    
	    
	    if(i%2==0){
	    	int size = max_heap.size()-min_heap.size();
	    	
	    	if(size>0){
	    		res += max_heap.top();
			}
			else{
				res += min_heap.top();
			}
		}
		else{
			res += max_heap.top();
		}
	    
	    res = res%mod;
	}
    cout<<res<<endl;
 	return 0;
}
