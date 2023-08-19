#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
const int INF = 100000;

bool isValid(int x, int y, int rows, int cols)
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

vector<pair<int, int>> moves = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

vector<pair<int, int>> getPossibleMoves(int x, int y, int k, int rows, int cols)
{
    vector<pair<int, int>> Moves;

    if (k == 1)
    {
        for (auto move : moves)
        {
            int new_x = x + move.first;
            int new_y = y + move.second;
            if (isValid(new_x, new_y, rows, cols))
            {
                Moves.push_back({new_x, new_y});
            }
        }
        return Moves;
    }

    for (auto move : moves)
    {
        int new_x = x + move.first;
        int new_y = y + move.second;
        if (isValid(new_x, new_y, rows, cols))
        {
            vector<pair<int, int>> nextMoves = getPossibleMoves(new_x, new_y, k - 1, rows, cols);
            Moves.insert(Moves.end(), nextMoves.begin(), nextMoves.end());
        }
    }

    return Moves;
}

int BFS(pair<int, int> source, pair<int, int> dest, int k, int rows, int cols)
{
    int visited[rows][cols];
    int level[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }

    queue<pair<int, int>> Q;
    Q.push(source);
    visited[source.first][source.second] = 1;
    level[source.first][source.second] = 0;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        int x = u.first;
        int y = u.second;
        Q.pop();
        vector<pair<int, int>> allmoves = getPossibleMoves(x, y, k, rows, cols);
        for (auto movement : allmoves)
        {
            int newX = movement.first;
            int newY = movement.second;

            if (visited[newX][newY] == 0)
            {
                Q.push({newX, newY});
                visited[newX][newY] = 1;
                level[newX][newY] = level[x][y] + 1;
            }
        }

        if (level[dest.first][dest.second] != INF)
        {
            break;
        }
    }
    return level[dest.first][dest.second];
}

int main()
{
    int rows, cols, num;
    cin >> rows >> cols >> num;

    vector<int> minmoves;
    vector<int> t(rows * cols, 0); // Initialize t with INF

    for (int i = 0; i < num; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        for (int j = 0; j < rows; j++)
        {
            for (int l = 0; l < cols; l++)
            {
                t[j * cols + l] = t[j * cols + l]+ BFS({x, y}, {j, l}, k, rows, cols);
                //cout<<t[j * cols + l]<<" ";
            }
        }

    }

    int minMove = *min_element(t.begin(), t.end());
    if (minMove == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minMove << endl;
    }

    return 0;
}
