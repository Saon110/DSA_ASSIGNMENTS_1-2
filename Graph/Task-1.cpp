#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define SIZE 10

//vector<int> graph[];
vector<int> visited;
vector<int> parent;

void BFS(int s,int d,vector<int>* graph)
{
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i = 0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]==0)
            {
                Q.push(graph[u][i]);
                visited[graph[u][i]] = 1;
                parent[graph[u][i]] = u;
            }
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> graph[V];

    visited.assign(V,0);

    parent.resize(V);

    for(int i = 0; i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    int s,d;
    cin>>s>>d;

    BFS(s,d,graph);

    if(visited[d]==0)
    {
        cout<<-1<<endl;
    }

    else{

        vector<int> path;
        for(int v = d; v!=s ;v = parent[v])
        {
            path.push_back(v);
        }

        if(s!=d)path.push_back(s);

        cout<<path.size()-1<<endl;
        for(int i = path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<" ";

        }
        cout<<endl;
    }


}