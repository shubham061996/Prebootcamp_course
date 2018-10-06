# include <iostream>
# include <fstream>
# include <vector>

using namespace std;

long sort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
int median_of_3(vector<int>& num, int low, int high, int medium);
int main(int argc, char** argv) {
	vector<int> num;
	ifstream infile;
	infile.open("QuickSort.txt", ios::in);
	int tmp;
	while (infile >> tmp)
		num.push_back(tmp);
	infile.close();
	long cnt = 0;
	cnt = sort(num, 0, num.size()-1);
	cout << cnt << endl;
	return 0;
}

long sort(vector<int>& num, int low, int high) {
	if (high <= low)
		return 0;
	int pivot = partition(num, low, high);
	int tmp1 = sort(num, low, pivot-1);
	int tmp2 = sort(num, pivot+1, high);
	return (tmp1 + tmp2 + (high - low));
}

/*int partition(vector<int>& num, int low, int high) {
	int pivot = num[low];
	int i = low + 1;
	int j;
	for (j = low + 1; j <= high; ++j) {
		if (num[j] < pivot) {
			swap(num[j], num[i]);
			++i;
		}
		/* else, do nothing */
/*	}
	swap(num[low], num[i-1]);
	return (i - 1);
}
int partition(vector<int>& num, int low, int high) {

	int pivot = num[high];
	swap(num[low], num[high]);
	int i = low + 1;
	int j;
	for (j = low + 1; j <= high; ++j) {
		if (num[j] < pivot) {
			swap(num[i], num[j]);
			++i;
		}
		/* else, do nothing */
/*	}
	swap (num[i-1], num[low]);
	return (i-1);
}*/
int partition(vector<int>& num, int low, int high) {

	int index = median_of_3(num, low, high, (low+high)/2);
	int pivot = num[index];
	swap(num[low], num[index]);
	int i = low + 1;
	int j;
	for (j = low + 1; j <= high; ++j) {
		if (num[j] < pivot) {
			swap(num[i], num[j]);
			++i;
		}
	}
	swap(num[i-1], num[low]);
	return (i-1);
}

int median_of_3(vector<int>& num, int low, int high, int medium) {

	if (num[low] > max(num[medium], num[high])) {
		if (num[medium] > num[high])
			return medium;
		else
			return high;
	}
	else if (num[low] < min(num[medium], num[high])) {
		if (num[medium] > num[high])
			return high;
		else
			return medium;
	}
	else
		return low; 
}
