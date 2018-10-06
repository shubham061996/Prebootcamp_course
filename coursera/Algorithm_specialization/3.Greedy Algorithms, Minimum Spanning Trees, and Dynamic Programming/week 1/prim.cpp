#include<bits/stdc++.h>

using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long int
#define MAXX 1000000000007
bool great(vector<ll> a, vector<ll> b){
    if(b[2]>a[2])
        return 1;
    return 0;
}

ll solve(ll A, vector<vector<ll> > &C) {
	ll i,j;
    // int A = 4;
    ll  m;
    ll n = C.size();
    
    vector<pair<ll, ll> > B[A+1];
    
    for(ll i=0;i<n;i++){
        ll n1 = C[i][0];
        ll n2 = C[i][1];
        ll n3 = C[i][2];
        
        B[n1].push_back(mp(n2, n3));
        B[n2].push_back(mp(n1, n3));
    }
    
    
    ll dist[A+1][2];
    ll visited[A+1];
    
    for(ll i=0;i<=A;i++){
        dist[i][0] = MAXX;
    	dist[i][1] = 0;
        visited[i] = 0;
    }
    
    // dist[1][0] = 0;
    // dist[1][1] = 0;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
    
    q.push(mp(0, 1));
    ll sum = 0;
    while(!q.empty()){
        
        ll node = q.top().second;
        ll currDist = q.top().first;
        
        q.pop();
        
        if(visited[node])
            continue;
        // cout<<node<<endl;
        
        sum+=currDist;
        for(ll i=0;i<B[node].size();i++){
            ll v = B[node][i].first;
            ll d = B[node][i].second;
            if(!visited[v]){
    			
    			q.push(mp(d, v));       
            }
        }
        
        visited[node] = 1;
        
    }
    
    
    return sum;
}


int main(){
	
	freopen("edges.txt", "r", stdin);
	
	ll n, edges;
	
	cin>>n>>edges;
	
	vector<ll> temp;
	vector<vector<ll> > input;
	
	ll n1, n2, w;
	for(ll i=0;i<edges;i++){
		cin>>n1>>n2>>w;
		temp.clear();
		temp.pb(n1);
		temp.pb(n2);
		temp.pb(w);
		input.pb(temp);
	}
	cout<<solve(n, input)<<endl;
	return 0;
}
