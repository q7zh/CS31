#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

//function 1
int appendToAll(string a[], int n, string value)
{
    //whether n is negative
    
    if (n < 0)
        return -1;
    
    //append the value to a
    
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + value;
    }
    return n;
}

//function 2
int lookup(const string a [], int n, string target)
{
    //whether n is negative
    
    if (n < 0)
        return -1;
    
    //if (n == 0)                                                          //mistake 1
        //return 0;
    
    //find the match for target in a
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
            
            //return the position
            
            return i;
    }
    
    //if no such match
    
    return -1;
}

//function 3
int positionOfMax(const string a[], int n)
{
    //whether n is nagative or equal to zero
    
    if(n <= 0)
        return -1;
    
    //find the string is >= every string in the array
    
    string Max = a[0];
    int x = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > Max)
        {
            x = i;
            Max = a[i];
        }
    }
    return x;
}

//function 4
int rotateLeft(string a[], int n, int pos)
{
    //whether n is negative
    
    if (n < 0 || pos < 0 || pos >= n)                                    //mistake 2, 3
        return -1;
    
    
    //copy a[pos] to x
    
    string x = a[pos];
    
    //move the elements after a[pos] to left
    
    for (int i = pos; i < n - 1; i++)                                     //miatake 4
    {
        a[i] = a [i+1];
    }
    
    //put x into the lasr position
    
    a[n - 1] = x;
    
    //return the original position of the a[pos]
    
    return pos;
}

//function 5
int countRuns(const string a[], int n)
{
    //whether n is negative
    
    if (n < 0)
        return -1;
    
    if (n == 0)
        return 0;
    
    //calculate the number of sequences of one or more consecutive identical items in a
    
    int number = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i] != a[i+1])
            number++;
    }
    
    //return the number
    
    return number;
}

//function 6
int flip(string a[], int n)
{
    
    //whether n is negative
    
    if (n < 0)
        return -1;
    
    //flip the order of the elements in a
    
    int w = n-1;
    for (int i = 0; i < (n)/2; i++)                                            //mistake 5
    {
        string x = a[w];
        string y = a[i];
        a[i] = x;
        a[w] = y;
        w--;
    }
    return n;
}

//function 7
int differ(const string a1[], int n1, const string a2[], int n2)
{
    int w = 0;
    
    //whether n1 or n2 is negative
    
    if (n1 < 0 || n2 < 0)
        return -1;
    
    //calculate the position of the first corresponding elements of a1 and a2 that are not equal
    
    if (n1 > n2)
        w = n2;
    else
        w = n1;
    for (int i = 0; i <= w - 1; i++)
    {
        if (a1[i] != a2[i])
            
            //return the position
            
            return i;
    }
    
    //if the arrays run out
    
    if (n1 > n2)
        return n2;
    else
        return n1;

}

//function 8
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    int x = 0;
    
    //whether n1 or n2 is negative
    
    if (n1 < 0 || n2 < 0)
        return -1;
    
    //if a2 is a sequence of 0 elements
    
    if (n2 == 0)
        return 0;
    
    //determine whether a2 is a subsequence of a1
    
    for (int i = 0; i < n1; i++)
    {
        if (a1[i] == a2[0])
        {    x = i;
            bool match = true;
            for (int s = 1; s < n2; s++)
            {
                if (a1[i+s] != a2[s])
                {
                    //if not
                    match = false;                           //add bool match 
                    break;                                   //mistake 6, return -1
                }
            }
            if (match == false)
                continue;
            
            //if yes, return the position
            
            return x;
        }
    }
    
    //if not
    
    return -1;
}

//function 9
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    
    //whether n1 or n2 is negative
    
    if (n1 < 0 || n2 < 0)
        return -1;
    
    //find the smallest element in a1 that is equal to any of the elements in a2
    
    for (int i = 0; i < n1; i++)
    {
        for(int s =0; s < n2; s++)
        {
            if (a1[i] == a2[s])
                
                //return the position
                
                return i;
        }
    }
    
    //if no such match
    
    return -1;
}

//function 10
int split(string a[], int n, string splitter)
{
    //if n is negative
    
    if(n < 0)
        return -1;
    
    //rearrange the elements
    
    for (int i = 0; i < n - 1; i++)
    {
        //when the element is >= splitter
        
        if (a[i] >= splitter)
        {
            //determine whether there is elements after it that is < splitter. If there is, exchange the positions
            
            string x = a[i];
            for (int s = 1; s < n - i; s++)
            {
                if (a[i+s] < splitter)
                {
                    string y = a[i+s];
                    a[i] = y;
                    a[i+s] = x;
                    break;
                }
            }
            
            //if no elements after it is < splitter
            
            if (a[i] == x)
            {
                
                //determine whether there is elements after it that is equal to splitter. If there is, exchange the positions
                
                for (int g = 1; g < n - i; g++)
                {
                    if (a[i+g] == splitter)
                    {
                        string k = a[i+g];
                        a[i] = k;
                        a[i+g] = x;
                    }
                }
            }
        }
    }
    
    //find the position of the first element that, after the rearrangement, is not < splitter
    
    for (int p = 0; p < n; p++)
    {
        if (a[p] >= splitter)
            return p;
    }
    
    //if no such elements
    
    return n;
}









string c[6] = {
    "alpha", "beta", "beta", "delta", "gamma", "gamma"
};

bool splitcheck(const string a[], int n, int p, string splitter)
{
    for (int k = 0; k < p; k++)
        if (a[k] >= splitter)
            return false;
    for ( ; p < n  &&  a[p] == splitter; p++)
        ;
    for (int k = p; k < n; k++)
        if (a[k] <= splitter)
            return false;
    string b[100];
    copy(a, a+n, b);
    sort(b, b+n);
    return equal(b, b+n, c);
}

void testone(int n)
{
    const int N = 6;
    
    // Act as if  a  were declared:
    //   string a[N] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[N] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~string();
    a[N].string::~string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "alpha", "beta", "gamma", "delta", "beta", "delta"
    };
    
    string d[9] = {
        "alpha", "beta",  "beta", "beta", "alpha",
        "alpha", "delta", "beta", "beta"
    };
    
    switch (n)
    {
        case  1: {
            assert(appendToAll(z, -1, "rho") == -1 && a[0] == "alpha");
        } break; case  2: {
            assert(appendToAll(z, 0, "rho") == 0 && a[0] == "alpha");
        } break; case  3: {
            assert(appendToAll(a, 1, "rho") == 1 && a[0] == "alpharho" &&
                   a[1] == "beta");
        } break; case  4: {
            assert(appendToAll(a, 6, "rho") == 6 && a[0] == "alpharho" &&
                   a[1] == "betarho" && a[2] == "gammarho" &&
                   a[3] == "gammarho" && a[4] == "betarho" &&
                   a[5] == "deltarho");
        } break; case  5: {
            assert(lookup(z, -1, "alpha") == -1);
        } break; case  6: {
            assert(lookup(z, 0, "alpha") == -1);
        } break; case  7: {
            assert(lookup(a, 1, "alpha") == 0);
        } break; case  8: {
            assert(lookup(a, 6, "delta") == 5);
        } break; case  9: {
            assert(lookup(a, 6, "beta") == 1);
        } break; case 10: {
            assert(lookup(a, 6, "zeta") == -1);
        } break; case 11: {
            assert(positionOfMax(z, -1) == -1);
        } break; case 12: {
            assert(positionOfMax(z, 0) == -1);
        } break; case 13: {
            assert(positionOfMax(a, 1) == 0);
        } break; case 14: {
            assert(positionOfMax(a, 3) == 2);
        } break; case 15: {
            assert(positionOfMax(a, 6) == 2);
        } break; case 16: {
            assert(positionOfMax(a+3, 3) == 0);
        } break; case 17: {
            a[0] = "";
            a[1] = " ";
            a[2] = "";
            assert(positionOfMax(a, 3) == 1);
        } break; case 18: {
            assert(rotateLeft(z, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 19: {
            assert(rotateLeft(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 20: {
            assert(rotateLeft(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 21: {
            assert(rotateLeft(z, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 22: {
            assert(rotateLeft(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 23: {
            assert(rotateLeft(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 24: {
            assert(rotateLeft(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 25: {
            assert(rotateLeft(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 26: {
            assert(rotateLeft(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 27: {
            assert(countRuns(z, -1) == -1);
        } break; case 28: {
            assert(countRuns(z, 0) == 0);
        } break; case 29: {
            assert(countRuns(a, 1) == 1);
        } break; case 30: {
            assert(countRuns(a, 3) == 3);
        } break; case 31: {
            assert(countRuns(a, 4) == 3);
        } break; case 32: {
            assert(countRuns(a+2, 4) == 3);
        } break; case 33: {
            assert(countRuns(d, 9) == 5);
        } break; case 34: {
            assert(flip(z, -1) == -1 && a[0] == "alpha");
        } break; case 35: {
            assert(flip(z, 0) == 0 && a[0] == "alpha");
        } break; case 36: {
            assert(flip(a, 1) == 1 && a[0] == "alpha" &&
                   a[1] == "beta");
        } break; case 37: {
            assert(flip(a, 2) == 2 && a[0] == "beta" &&
                   a[1] == "alpha" && a[2] == "gamma");
        } break; case 38: {
            assert(flip(a, 5) == 5 && a[0] == "beta" &&
                   a[1] == "gamma" && a[2] == "gamma" && a[3] == "beta" &&
                   a[4] == "alpha" && a[5] == "delta");
        } break; case 39: {
            a[2] = "zeta";
            assert(flip(a,6) == 6 && a[0] == "delta" && a[1] == "beta" &&
                   a[2] == "gamma" && a[3] == "zeta" && a[4] == "beta" &&
                   a[5] == "alpha");
        } break; case 40: {
            assert(differ(z, -1, b, 6) == -1);
        } break; case 41: {
            assert(differ(a, 6, z, -1) == -1);
        } break; case 42: {
            assert(differ(z, 0, b, 0) == 0);
        } break; case 43: {
            assert(differ(a, 3, b, 3) == 3);
        } break; case 44: {
            assert(differ(a, 3, b, 2) == 2);
        } break; case 45: {
            assert(differ(a, 2, b, 3) == 2);
        } break; case 46: {
            assert(differ(a, 6, b, 6) == 3);
        } break; case 47: {
            assert(subsequence(z, -1, b, 6) == -1);
        } break; case 48: {
            assert(subsequence(a, 6, z, -1) == -1);
        } break; case 49: {
            assert(subsequence(z, 0, b, 6) == -1);
        } break; case 50: {
            assert(subsequence(a, 6, z, 0) == 0);
        } break; case 51: {
            assert(subsequence(a, 6, b, 1) == 0);
        } break; case 52: {
            assert(subsequence(a, 6, b+4, 2) == 4);
        } break; case 53: {
            assert(subsequence(a, 6, b+3, 1) == 5);
        } break; case 54: {
            assert(subsequence(a, 6, b+3, 2) == -1);
        } break; case 55: {
            assert(subsequence(a, 6, b+2, 2) == -1);
        } break; case 56: {
            assert(subsequence(a, 6, a, 6) == 0);
        } break; case 57: {
            assert(lookupAny(a, 6, z, -1) == -1);
        } break; case 58: {
            assert(lookupAny(z, -1, b, 6) == -1);
        } break; case 59: {
            assert(lookupAny(z, 0, b, 1) == -1);
        } break; case 60: {
            assert(lookupAny(a, 6, z, 0) == -1);
        } break; case 61: {
            assert(lookupAny(a, 1, b, 1) == 0);
        } break; case 62: {
            assert(lookupAny(a, 6, b+3, 3) == 1);
        } break; case 63: {
            assert(lookupAny(a, 4, b+3, 3) == 1);
        } break; case 64: {
            assert(lookupAny(a, 2, b+2, 2) == -1);
        } break; case 65: {
            assert(split(z, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 66: {
            assert(split(z, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 67: {
            assert(split(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 68: {
            assert(split(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 69: {
            assert(split(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 70: {
            assert(split(a, 2, "aaa") == 0 &&
                   splitcheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 71: {
            assert(split(a, 2, "alpha") == 0 &&
                   splitcheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 72: {
            assert(split(a, 2, "beta") == 1 &&
                   splitcheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(split(a, 2, "zeta") == 2 &&
                   splitcheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(split(a, 6, "aaa") == 0 && splitcheck(a, 6, 0, "aaa"));
        } break; case 75: {
            assert(split(a, 6, "alpha") == 0 &&
                   splitcheck(a, 6, 0, "alpha"));
        } break; case 76: {
            assert(split(a, 6, "beta") == 1 &&
                   splitcheck(a, 6, 1, "beta"));
        } break; case 77: {
            assert(split(a, 6, "delta") == 3 &&
                   splitcheck(a, 6, 3, "delta"));
        } break; case 78: {
            assert(split(a, 6, "gamma") == 4 &&
                   splitcheck(a, 6, 4, "gamma"));
        } break; case 79: {
            assert(split(a, 6, "zeta") == 6 &&
                   splitcheck(a, 6, 6, "zeta"));
        } break; case 80: {
            a[2] = "mu";
            c[5] = "mu";
            assert(split(a, 6, "mu") == 5 && splitcheck(a, 6, 5, "mu"));
        } break; case 81: {
            assert(split(a, 6, "chi") == 3 && splitcheck(a, 6, 3, "chi"));
        } break; case 82: {
            // This case tested whether rotateLeft used an extra array
        } break; case 83: {
            // This case tested whether flip used an extra array
        } break; case 84: {
            // This case tested whether split used an extra array
        } break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}

int main()
{
    cout << "Enter a test number (1 to 81): ";
    int n;
    cin >> n;
    if (n < 1  ||  n > 81)
    {
        cout << "Bad test number" << endl;
        return 1;
    }
    testone(n);
    cout << "Passed test " << n << endl;
}

