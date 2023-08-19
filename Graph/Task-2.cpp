#include<iostream>
#include<vector>
using namespace std;

vector<int> visited;
vector<int> parent;
vector<int> Time_St;
vector<int> Time_F;
vector<int> path;
int time = 0;

void DFS_visit(vector<int>* graph,int u)
{
    time = time+1;
    Time_St[u] = time;
    visited[u] = 1;

    for(int i = 0;i<graph[u].size();i++)
    {
        if(visited[graph[u][i]] ==0)
        {
            parent[graph[u][i]] = u;
            DFS_visit(graph,graph[u][i]);
        }
    }

    time = time +1;
    Time_F[u] = time;
    path.push_back(u);


}


void DFS(int s,int V,vector<int>* graph)
{
    visited[s] = 1;
    parent[s] = -1;
    //path.push_back(s);
    
    for(int i=0 ; i<graph[s].size();i++)
    {
        if(visited[graph[s][i]] == 0)
        {

            DFS_visit(graph,graph[s][i]);
        }
    }
}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> graph[V];

    visited.assign(V,0);
    Time_St.resize(V);
    Time_F.resize(V);
    parent.resize(V);

    for(int i = 0; i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    int s,d;
    cin>>s>>d;
    DFS(s,V,graph);
    path.push_back(s);
    //reverse(path.begin(),path.end());

    if(visited[d]==0)
    {
        cout<<-1<<endl;
    }

    else
    {
        int length = 0;
        for(int i = path.size()-1;path[i]!=d;i--)
        {
            length++;
        }
        cout<<length<<endl;
        for(int i = path.size()-1;path[i]!=d;i--)
        {
            cout<<path[i]<<" ";

        }
        cout<<d;
        cout<<endl;
    }
    
}