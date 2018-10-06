#include <bits/stdc++.h>
using namespace std;

// Count inversionersions
long long int merge(int arr[],int l,int mid,int h){

	int n1 = mid - l + 1;
    int n2 =  h - mid;
    long long int inversion = 0;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){

        R[j] = arr[mid + 1+ j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inversion+=(n1-i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversion;

}
long long int merge_sort(int arr[],int l,int h){
	int mid;
	long long int inversion = 0;
	if(h > l){

		mid = (l+h)/2;
	 	inversion = merge_sort(arr,l,mid);
		inversion += merge_sort(arr,mid+1,h);
		inversion += merge(arr,l,mid,h);
	}

	return inversion;
}
int main(){
	int arr[100000];
	ifstream infile;
	infile.open("IntegerArray.txt");
	int tmp;
	int i=0;
	while (infile >> tmp)
		arr[i++]=tmp;
	infile.close();
    cout << merge_sort(arr,0,99999) << endl;
    return 0;
}
