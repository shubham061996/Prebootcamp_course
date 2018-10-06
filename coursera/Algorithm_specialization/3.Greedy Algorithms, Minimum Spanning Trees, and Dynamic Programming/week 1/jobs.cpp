#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.second > b.second)
        return true;
    else if(a.second == b.second){
        if(a.first > b.first)
            return true;
    }
        return false;
}

int main(){
    vector<pair<int,int > > diff;
    freopen("jobs.txt","r",stdin);
    int number = 0;
    cin>>number;
    int w,l;
    while (cin>>w>>l > 0) {
           diff.push_back(make_pair(w,w-l));
    }
    sort(diff.begin(), diff.end(), sortbysec);

    long long weightedsum = 0;
    long lengthsum = 0;
    for(int i = 0;i < diff.size();i++){
            lengthsum += (diff[i].first - diff[i].second);
            weightedsum += diff[i].first * lengthsum;
    }
    cout << weightedsum << endl;
    return 0;
}
