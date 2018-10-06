#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,pair<double,double > > &a,const pair<int,pair<double,double > > &b)
{
    if (a.second.second > b.second.second)
        return true;
    else if(a.second.second == b.second.second){
        if(a.second.first > b.second.first)
            return true;
    }
        return false;
}

int main(){
    vector<pair<int,pair<double,double > > >diff;

    freopen("jobs.txt","r",stdin);

    int number = 0;
    cin>>number;
    int w,l;
    while (cin>>w>>l > 0) {
           diff.push_back(make_pair(l,make_pair(w,w/(double)l)));
    }
    sort(diff.begin(), diff.end(), sortbysec);

    long long weightedsum = 0;
    long lengthsum = 0;
    for(int i = 0;i < diff.size();i++){
            lengthsum += diff[i].first;
            weightedsum += diff[i].second.first * lengthsum;
    }
    cout << weightedsum << endl;

    return 0;
}
