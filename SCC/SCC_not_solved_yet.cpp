#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

void add_edge(unordered_map<string, vector<string>> &graph, const string &from_node, const string &to_node)
{
    if (graph.find(from_node) == graph.end())
    {
        graph[from_node] = vector<string>();
    }
    graph[from_node].push_back(to_node);
}

string neg(const string &literal)
{
    if (literal[0] == '~')
    {
        return literal.substr(1);
    }
    else
    {
        return "~" + literal;
    }
}

pair<string, string> parse_clause(const string &clause)
{
    istringstream iss(clause);
    string x, y;
    iss >> x >> y;
    return make_pair(x, y);
}

unordered_map<string, vector<string>> construct_graph(const vector<string> &clauses)
{
    unordered_map<string, vector<string>> graph;

    for (const string &clause : clauses)
    {
        pair<string, string> literals = parse_clause(clause);
        string x = literals.first;
        string y = literals.second;

        if (y.empty())
        {
            // Handle clauses with just one literal (variable)
            if (x[0] == '~')
            {
                add_edge(graph, x.substr(1), neg(x));
            }
            else
            {
                add_edge(graph, neg(x), x);
            }
        }
        else
        {
            add_edge(graph, neg(x), y);
            add_edge(graph, neg(y), x);
        }
    }

    return graph;
}

void dfs(const unordered_map<string, vector<string>> &graph, const string &node, stack<string> &s, unordered_map<string, bool> &visited)
{
    visited[node] = true;
    if (graph.find(node) != graph.end())
    {
        for (const string &neighbor : graph.at(node))
        {
            if (!visited[neighbor])
            {
                dfs(graph, neighbor, s, visited);
            }
        }
    }
    s.push(node);
}

vector<vector<string>> find_sccs(const unordered_map<string, vector<string>> &graph)
{
    stack<string> s;
    unordered_map<string, bool> visited;
    for (const auto &entry : graph)
    {
        visited[entry.first] = false;
    }
    for (const auto &entry : graph)
    {
        if (!visited[entry.first])
        {
            dfs(graph, entry.first, s, visited);
        }
    }

    unordered_map<string, vector<string>> reversed_graph;
    for (const auto &entry : graph)
    {
        for (const string &neighbor : entry.second)
        {
            add_edge(reversed_graph, neighbor, entry.first);
        }
    }

    // for(auto x:reversed_graph)
    // {
    //     cout<<x.first<<"->";
    //     for(auto y:x.second)
    //     {
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    // stack<string> s1(s);
    // while(!s1.empty())
    // {
    //     cout<<s1.top()<<endl;
    //     s1.pop();
    // }
    // while (!s1.empty())
    // {
    //     if(reversed_graph.find(s1.top()) == reversed_graph.end())
    //     {
    //         reversed_graph[s1.top()] = vector<string>();
    //     }
    // }

    for (const auto &entry : graph)
    {
        visited[entry.first] = false;
    }

    vector<vector<string>> sccs;
    while (!s.empty())
    {
        string node = s.top();
        s.pop();
        if (!visited[node])
        {
            stack<string> component_stack;
            dfs(reversed_graph, node, component_stack, visited);
            vector<string> scc;
            while (!component_stack.empty())
            {
                scc.push_back(component_stack.top());
                component_stack.pop();
            }
            sccs.push_back(scc);
        }
    }
    return sccs;
}

bool assign_values(const vector<vector<string>> &sccs, unordered_map<string, int> &assignment_map)
{
    for (const vector<string> &scc : sccs)
    {
        for (int i = 0; i < scc.size(); i++)
        {
            string variable = scc[i];
            string neg_variable = neg(variable);
            for (int j = i+1; j < scc.size(); j++)
            {
                if (scc[j] == neg_variable)
                {
                    return false;
                }
            }
        }
    }

    for (const vector<string> &scc : sccs)
    {
        for (const string &variable : scc)
        {

            string neg_variable = neg(variable);
            //cout<<variable<<" "<<neg_variable<<endl;
            
            assignment_map[variable] = 1;
            assignment_map[neg_variable] = -1;
        }
    }

    return true;
}

int main()
{
    
    int n;
    cin>>n;
    vector<string> input_clauses(n);
    cin.ignore();
    for(int i=0;i<n;i++)
    {
      //  cin>>input_clauses[i];
      getline (cin, input_clauses[i]) ;
    }
    unordered_map<string, vector<string>> graph = construct_graph(input_clauses);
    
    vector<vector<string>> sccs = find_sccs(graph);
    // // reverse(sccs.begin(), sccs.end());  // Reverse SCCs for correct assignment order

    unordered_map<string, int> assignment_map;
    for (const vector<string> &scc : sccs)
    {
        for (const string &variable : scc)
        {
            assignment_map[variable] = 0;
            assignment_map[neg(variable)] = 0;
        }
    }

    if (assign_values(sccs, assignment_map))
    {
        // cout << "Assignment possible" << endl;
        for (const auto &entry : assignment_map)
        {
            if (entry.first.size() == 1)
            {
                cout << entry.first << " ";
                if (entry.second == 1)
                {
                    cout << "False" << endl;
                }
                else if (entry.second == -1)
                {
                    cout << "True" << endl;
                }
            }
        }
    }
    else
    {
        cout << "No assignment possible" << endl;
    }
    for (auto scc : sccs)
    {
        for (auto node : scc)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
