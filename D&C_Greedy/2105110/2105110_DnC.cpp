#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> origin;

// finding the quadrant of a point

int quadrant(pair<int, int> point)

{

    if (point.first >= 0 && point.second >= 0)
    {
        return 1;
    }

    if (point.first <= 0 && point.second >= 0)
    {
        return 2;
    }

    if (point.first <= 0 && point.second <= 0)
    {
        return 3;
    }
    return 4;
}

// The rotation_indicator function takes three points as input: p, q, and r.
// It calculates the cross product of the vectors formed by
// (r - q) and (q - p) to determine the orientation of the points.
// If the result of cross product is +ve,that means point r is in clock-wise
// direction of point q,otherwise(product<0) anti-clockwise.
// This is used to detemine if a line q-p intersects a polygon that has q and r as vertices.

int rotation_indicator(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{

    int x1 = p.first;
    int y1 = p.second;
    int x2 = q.first;
    int y2 = q.second;
    int x = r.first;
    int y = r.second;

    int cross_product = (y2 - y1) * (x - x2) - (x2 - x1) * (y - y2);

    if (cross_product == 0)
    {
        return 0;
    }
    if (cross_product > 0)
    {

        return 1;
    }
    return -1;
}

// compare_anti_clockwise fuction compares two points by
// anti-clockwise direction. p and q are shifted to new
//  co-ordinate axes by subtracting origin from p and q

bool copmpare_anti_clockwise(pair<int, int> p, pair<int, int> q)
{

    pair<int, int> p1 = make_pair(p.first - origin.first, p.second - origin.second);
    pair<int, int> q1 = make_pair(q.first - origin.first, q.second - origin.second);

    int a = quadrant(p1);
    int b = quadrant(q1);
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = q1.first;
    int y2 = q1.second;

    if (a != b)
    {
        return a < b;
    }
    return (y1 * x2 - y2 * x1 < 0);
}

vector<pair<int, int>> find_points_brute(vector<pair<int, int>> polygon)
{
    set<pair<int, int>> s;
    int m = polygon.size();

    for (int i = 0; i < polygon.size(); i++)

    {
        int x1 = polygon[i].first;
        int y1 = polygon[i].second;
        for (int j = i + 1; j < polygon.size(); j++)
        {
            int x2 = polygon[j].first;
            int y2 = polygon[j].second;

            int a = y1 - y2;
            int b = x2 - x1;
            int c = x1 * y2 - y1 * x2;
            int upside = 0;
            int downside = 0;
            for (int k = 0; k < polygon.size(); k++)
            {
                int x = polygon[k].first;
                int y = polygon[k].second;
                if (a * x + b * y + c <= 0)
                    downside++;
                if (a * x + b * y + c >= 0)
                    upside++;
            }
            if (upside == polygon.size() || downside == polygon.size())
            {
                s.insert(polygon[i]);
                s.insert(polygon[j]);
            }
        }
    }
    vector<pair<int, int>> res;
    for (auto e : s)
        res.push_back(e);

    origin = {0, 0};
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        origin.first += res[i].first;
        origin.second += res[i].second;
        res[i].first *= n;
        res[i].second *= n;
    }
    sort(res.begin(), res.end(), copmpare_anti_clockwise);
    for (int i = 0; i < n; i++)
        res[i] = make_pair(res[i].first / n, res[i].second / n);

    return res;
}

vector<pair<int, int>> merge_polygon(vector<pair<int, int>> left, vector<pair<int, int>> right)
{
    int n1 = left.size();
    int n2 = right.size();

    int r_m = 0, l_m = 0;

    for (int i = 0; i < n1; i++)
    {
        if (left[i].first > left[r_m].first)
        {
            r_m = i;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        if (right[i].first < right[l_m].first)
        {
            l_m = i;
        }
    }

    int up_left = r_m;
    int up_right = l_m;
    int finish = 0;
    while (finish == 0)
    {
        finish = 1;
        while (rotation_indicator(right[up_right], left[up_left], left[(up_left + 1) % n1]) > 0)
        {
            up_left = (up_left + 1) % n1;
        }

        while (rotation_indicator(left[up_left], right[up_right], right[(n2 + up_right - 1) % n2]) < 0)
        {
            up_right = (n2 + up_right - 1) % n2;
            finish = 0;
        }
    }

    // if (rotation_indicator(right[up_right], left[up_left], left[(up_left + 1) % n1]) == 0)
    //     {
    //         up_left = (up_left + 1) % n1;
    //     }

    // if (rotation_indicator(left[up_left], right[up_right], right[(n2 + up_right - 1) % n2]) == 0)
    //     {
    //         up_right = (n2 + up_right - 1) % n2;
    //         //finish = 0;
    //     }



    finish = 0;
    int down_left = r_m;
    int down_right = l_m;

    while (finish == 0)
    {
        finish = 1;
        while (rotation_indicator(left[down_left], right[down_right], right[(down_right + 1) % n2]) >= 0)
        {
            down_right = (down_right + 1) % n2;
        }

        while (rotation_indicator(right[down_right], left[down_left], left[(n1 + down_left - 1) % n1]) <= 0)
        {
            down_left = (n1 + down_left - 1) % n1;
            finish = 0;
        }
    }

    // if (rotation_indicator(left[down_left], right[down_right], right[(down_right + 1) % n2]) == 0)
    //     {
    //         down_right = (down_right + 1) % n2;
    //     }

    // if (rotation_indicator(right[down_right], left[down_left], left[(n1 + down_left - 1) % n1]) == 0)
    //     {
    //         down_left = (n1 + down_left - 1) % n1;
    //         //finish = 0;
    //     }

    vector<pair<int, int>> merged_polygon;

    int i = up_left;
    while (i != down_left)
    {
        merged_polygon.push_back(left[i]);
        i = (i + 1) % n1;
    }
    merged_polygon.push_back(left[down_left]);

    i = down_right;
    while (i != up_right)
    {
        merged_polygon.push_back(right[i]);
        i = (i + 1) % n2;
    }
    merged_polygon.push_back(right[up_right]);

    return merged_polygon;
}

vector<pair<int, int>> find_points(vector<pair<int, int>> points)
{
    if (points.size() <= 5)
    {
        return find_points_brute(points);
    }

    int n = points.size();

    vector<pair<int, int>> left, right;
    for (int i = 0; i < n / 2; i++)
    {
        left.push_back(points[i]);
    }

    for (int i = n / 2; i < n; i++)
    {
        right.push_back(points[i]);
    }

    vector<pair<int, int>> left_convex_points = find_points(left);
    vector<pair<int, int>> right_convex_points = find_points(right);

    return merge_polygon(left_convex_points, right_convex_points);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if(n<3)
    {
        cout<<"Cannot form a polygon"<<endl;
        return 0;
    }
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    sort(points.begin(), points.end());

    vector<pair<int, int>> convex_points = find_points(points);

    for (int i = 0; i < convex_points.size(); i++)
    {
        cout << convex_points[i].first << " " << convex_points[i].second << endl;
    }

    fclose(stdin);
    return 0;
}
