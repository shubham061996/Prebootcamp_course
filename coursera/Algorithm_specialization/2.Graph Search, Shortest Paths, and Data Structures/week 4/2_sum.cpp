#include<bits/stdc++.h>
#define NUM_ELEMENTS 1000000
#define MIN -10000
#define MAX 10000
using namespace std;

long long  data[NUM_ELEMENTS];
int main()
{
    ifstream fin;
    fin.open("sum.txt");

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        fin >> data[i];
    }
    fin.close();    
    sort(data, data + NUM_ELEMENTS);
    int start = 0;
    int end = NUM_ELEMENTS - 1;
    bool found[MAX - MIN + 1];
    for (int i = MIN; i <= MAX; i++)
    {
        found[i - MIN] = false;
    }
    while (start < end)
    {
        long long  probe_sum = data[start] + data[end];
        if (probe_sum < MIN)
        {
            start++;
        }
        else if (probe_sum > MAX)
        {
            end--;
        }
        else
        {
            if (data[start] != data[end])
            {
                found[probe_sum - MIN] = true;
            }
            int current_start = start;
            int current_end = end;
            while (true)
            {
                start++;
                long long  probe_sum = data[start] + data[end];
                if (probe_sum > MAX)
                {
                    break;
                }
                else
                {
                    if (data[start] != data[end])
                    {
                        found[probe_sum - MIN] = true;
                    }
                }
            }
            start = current_start;

            while (true)
            {
                end--;
                long long  probe_sum = data[start] + data[end];
                if (probe_sum < MIN)
                {
                    break;
                }
                else
                {
                    if (data[start] != data[end])
                    {
                        found[probe_sum - MIN] = true;
                    }
                }
            }
            end = current_end;
            start++;
            end--;
        }
    }

    int count = 0;
    for (int i = MIN; i <= MAX; i++)
    {
        if (found[i - MIN])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}

