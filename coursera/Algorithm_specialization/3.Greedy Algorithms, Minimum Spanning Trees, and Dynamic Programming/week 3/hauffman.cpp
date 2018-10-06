#include<bits/stdc++.h>
using namespace std;

int frequency[1000];
int fun(int end,int total_freq,int count){
	if(0==end)
		return count;
	int index;
	long long int diff=total_freq,left=0,right=total_freq,sum=0;
	for(int i=0;i<end;i++){
		left+=frequency[i];
		right-=frequency[i];
		long long int temp=abs(right-left);
		if(temp<=diff){
			diff=temp;
			index=i;
			sum=left;
		}
	}

		return fun(index,sum,count+1);
}
int main() {
    ifstream infile;
    infile.open("huffman.txt");
    int i = 0;
    infile >> i;
    int j = 0;
    while (j<i) {
    	infile>>frequency[j];
        
        j++;

    }
    infile.close();
    //cout<<weight[100];
    long long int right=0;
    sort(frequency,frequency+1000);
    for(int i=0;i<1000;i++)
		right+=frequency[i];
	cout<<fun(999,right,0);	
}
