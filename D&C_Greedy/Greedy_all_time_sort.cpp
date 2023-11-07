#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<set>

using namespace std;

int count_Platforms(vector<int> arrival, vector<int> depart)
{
    int res = 1;
    int platforms = 1;

    //int a = 0,d = 0;

    // for(int i : all_time)
    // {
        
    //     for(int j = 0 ; j< arrival.size();j++)
    //     {
    //         if(i == arrival[j])
    //         {
    //             a = 1;
    //         }

    //         if(i == depart[j])
    //         {
    //             d = 1;
    //         }
    //     }

    //     if(a == 1)
    //     {
    //         platforms++;
    //         a = 0;
    //     }

    //     if(d == 1)
    //     {
    //         platforms--;
    //         d = 0;
    //     }

    //     res = max(res,platforms);
    // }

    int i = 1, j = 0;

    while(i < arrival.size() && j < depart.size())
    {
        if(arrival[i] <= depart[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }

        res = max(res,platforms);
    }

    return res;

}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        times.push_back(make_pair(x, y));
    }

    vector<int> arrival, depart;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> t = times[i];
        arrival.push_back(t.first);
        depart.push_back(t.second);
    }

    sort(arrival.begin(), arrival.end());
    sort(depart.begin(), depart.end());

    // vector<int> all_time(2 * n);

    // merge(arrival.begin(), arrival.end(), depart.begin(), depart.end(), all_time.begin());

    

    // set<int> s;

    // for(int i: all_time)
    // {
    //     s.insert(i);
    // }

    int res = count_Platforms(arrival, depart);

    cout << res << endl;
    fclose(stdin);
    return 0;
}