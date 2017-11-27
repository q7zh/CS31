#include <iostream>
#include <cctype>
#include <cassert>
#include "grid.h"
#include <string>
using namespace std;

bool isRouteWellFormed(string route)
{
    if (route == "")//whether route is an empty string
    {
        return true;
    }
    
    //calculate whetehr there are two digits or less after each letter
    
    if (isalpha(route[0]))
    {
        int numberofDigits = 0;
        for (int i = 0; i != route.size();i++)
        {
            if (isdigit(route[i]))
                numberofDigits++;
            else if (isalpha(route[i]))
            {
                //whether the letter is among the four letters
                
                route[i] = toupper(route[i]);
                if(route[i] != 'N' && route[i] != 'S' && route[i] != 'W' && route[i] != 'E')
                {
                    return false;
                }
                
                numberofDigits = 0;
            }
            else
                return false;//not digit or alpha, return false
            
            if (numberofDigits >= 3)
                return false;//bigger or equal to 3, return false
        }
        return true;
    }
    return false;//the first character of route is not a letter, return false
}


int navigateSegment(int r, int c, char dir, int maxSteps)
{
    //(r,c) is a valid empty grid position or not
    
    int i = getRows();
    int k = getCols();
    if(r < 1 || c < 1 || r > i || c > k || isWall(r,c))
        return -1;
    
    //dir is an valid direction character or not
    
    dir = toupper(dir);
    if(dir != 'N' && dir != 'S' && dir != 'W' && dir != 'E' )
        return -1;
    
    //maxSteps is negative or not
    
    if (maxSteps < 0)
        return -1;
    
    //whether there is wall in the route and calculate the valid steps
    
    int validSteps = 0;
    if (dir == 'N')
    {
        for (;r > 1 && !isWall(r-1,c);r--)
            validSteps++;
    }
    else if (dir == 'S')
    {
        for (;r < i && !isWall(r+1,c);r++)
            validSteps++;
    }
    else if (dir == 'W')
    {
        for(;c > 1 && !isWall(r, c-1);c--)
            validSteps++;
    }
    else if (dir == 'E')
    {
        for(;c < k && !isWall(r, c+1);c++)
            validSteps++;
    }
    
    if(validSteps < maxSteps)
        maxSteps = validSteps;
    
    return maxSteps;
}


int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps)
{
    int i = getRows();
    int k = getCols();
    
    //whether the start position, the end position and the route are valid
  
    if(sr < 1 || sc < 1 || sr > i || sc > k || isWall(sr,sc) ||er < 1 || ec < 1 || er > i || ec > k || isWall(er,ec) || isRouteWellFormed(route) == false)
        return 2;
    
    //calculate the valid steps and whether there is wall in the route
    
    int r = sr;
    int c = sc;
    int g;
    int h;
    int validSteps = 0;
    for (int n = 0; n != route.size(); n++)
    {
        if(isalpha(route[n]))
        {
            if (isdigit(route[n+1]))
            {
                g = route[n+1] - '0';
                if (isdigit(route[n+2]))
                {
                    int f = route[n+2] - '0';
                    h =  g * 10 + f;
                    validSteps = validSteps + navigateSegment(r, c, route[n], h);
                    for(int j = 1; j <= h; j++)
                    {
                        route[n] = toupper(route[n]);
                        if (route[n] == 'N')
                            r--;
                        else if (route[n] == 'S')
                            r++;
                        else if (route[n] == 'W')
                            c--;
                        else if (route[n] == 'E')
                            c++;
                        if ( r > i || c > k || r < 1 || c < 1 || isWall(r,c))
                        {
                            nsteps = validSteps;
                            return 3;
                        }
                    }
                 }
                else
                {
                
                    validSteps = validSteps + navigateSegment(r, c, route[n], g);
                    for (int p = 1; p <= g; p++)
                    {
                        route[n] = toupper(route[n]);
                        if (route[n] == 'N')
                            r--;
                        else if (route[n] == 'S')
                            r++;
                        else if (route[n] == 'W')
                            c--;
                        else if (route[n] == 'E')
                            c++;
                        if ( r > i || c > k || r < 1 || c < 1 || isWall(r,c))
                        {
                            nsteps = validSteps;
                            return 3;
                        }
                    }
                }
            }
            if (isalpha(route[n+1]))
            {
            
                validSteps = validSteps + navigateSegment(r, c, route[n], 1);
                route[n] = toupper(route[n]);
                if (route[n] == 'N')
                    r--;
                else if (route[n] == 'S')
                    r++;
                else if (route[n] == 'W')
                    c--;
                else if (route[n] == 'E')
                    c++;
                if (isWall(r,c) || r > i || c > k || r < 1 || c < 1)
                {
                    nsteps = validSteps;
                    return 3;
                }
            }
        }
    }
    
    nsteps = validSteps;
    
    if (r == er && c == ec)
        return 0;
    
        return 1;
}


int main()
{
    setSize(3,4);
    setWall(1,4);
    setWall(2,2);
    setWall(3,2);
    
    assert(!isRouteWellFormed("n554W2eN3"));//3 digits
    assert(isRouteWellFormed("n2e1"));
    assert(!isRouteWellFormed("e1x"));//other alpha
    assert(!isRouteWellFormed("1n2nm2"));//start with digit
    assert(!isRouteWellFormed("n5W2e345N3"));//3 digits
    assert(!isRouteWellFormed("B23m12n3mght"));//other alpha
    assert(!isRouteWellFormed("n23,n12,n87"));//not digit or alpha
    assert(!isRouteWellFormed("w2+n3"));//not digit or alpha
    assert(!isRouteWellFormed("N144"));//3 digits
    assert(!isRouteWellFormed("3SN"));// start with sigit
    assert(isRouteWellFormed(""));
    assert(!isRouteWellFormed("G23h12"));
    assert(!isRouteWellFormed("W123s12"));
    assert(isRouteWellFormed("e0s12w03e2"));
    
    assert(navigateSegment(3, 1, 'N', 2) == 2);
    assert(navigateSegment(0, 1, 'N', 2) == -1); //r not valid
    assert(navigateSegment(1, -1, 'W', 2) == -1);//c not valid
    assert(navigateSegment(1, 2, 'w', 3) == 1);
    assert(navigateSegment(1, 2, 'g', 3) == -1); //dir not valid
    assert(navigateSegment(1, 7, 'w', 3) == -1); //c not valid
    assert(navigateSegment(7, 2, 'w', 3) == -1); //r not valid
    assert(navigateSegment(3, 1, 's', -5) == -1);//maxsteps not valid
    assert(navigateSegment(2, 2, 'n', 1) == -1);//(r,c)is wall
    assert(navigateSegment(1, 3, 'W', 3) == 2);
    assert(navigateSegment(1, 3, 'E', 1) == 0);
    assert(navigateSegment(1, 3, 'S', 2) == 2);
    assert(navigateSegment(1, 3, 'n', 3) == 0);
    assert(navigateSegment(2, 4, 'w', 3) == 1);
    assert(navigateSegment(2, 4, 'S', 2) == 1);
    assert(navigateSegment(2, 4, 'n', 4) == 0);
    assert(navigateSegment(2, 1, 'n', 2) == 1);
    
    
    int len;
    
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "N2eE02n0s2e1", len) == 3  &&  len == 4);//moving to wall
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 2,3, "N2eE01n0", len) == 1  &&  len == 4);//not ends up at (er,ec)
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "e1x", len) == 2  &&  len == -999);//route is not valid
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "N2eE01n0s2e1", len) == 0  &&  len == 7);//ends up at (er,ec)
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "w3+e4", len) == 2  &&  len == -999);//route is not valid
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(2,2, 3,4, "N2eE01n0s2e1", len) == 2  &&  len == -999);//(sr,sc)is not valid
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "N2eE01n0s3e1", len) == 3  &&  len == 6);//running off the edge
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 1,4, "N2eE01n0s2e1", len) == 2  &&  len == -999);//(er,ec)is not valid
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(2,1, 3,4, "NeE01n0s2e1", len) == 0  &&  len == 6);//ends up at (er,ec)
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(2,1, 2,3, "e2", len) == 3  &&  len == 0);//ends up at (er,ec)
    
    cout << "All tests succeeded" << endl;
}
