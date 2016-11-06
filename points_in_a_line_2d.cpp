#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
bool operator<(const Point& a, const Point& b)
{
    if(a.x < b.x)
        return true;
    else if(a.x == b.x)
        return a.y<b.y;
    else
        return false;
}

class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
    int maxPoints(vector<Point>& points) 
    {
        if( points.size() <= 2 )
            return points.size();
        
        int maxP = 0;

        for(int i=0 ; i<points.size() ;i++)
        {
            map<Point,int> stats;
            stats.clear();
            int same = 1;
            int localmax = 0;
            for(int j=i+1 ; j<points.size() ; j++)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y )
                    same++;
                else
                {
                    int x = points[i].x - points[j].x;
                    int y = points[i].y - points[j].y;
                    int gcd_val = gcd(x,y);
                    x /= gcd_val;
                    y /= gcd_val;
                    Point p(x,y);
                    stats[p] += 1;
                    localmax = max(localmax , stats[p]);
                }
            }
            maxP = max(maxP,localmax+same);
        }
        return maxP;
    }
};

int main()
{
    Solution sol;
    vector<Point> s;
    s.push_back(Point(1,1));
    s.push_back(Point(2,1));
    s.push_back(Point(2,2));
    s.push_back(Point(3,2));
    cout << sol.maxPoints(s) ;
    return 0;   
}
