#include <iostream>
#include <string>
using namespace std;

int main ()
{
    //gather input data
    
    cout << "Units sent: ";
    int numbersofUnits;
    cin >> numbersofUnits;
    
    if (numbersofUnits < 0)
       {cout << "---" << endl;
        cout << "The number of units sent must be nonnegative." << endl;
        return 1;}
    
    cout << "Title: ";
    string movieTitle;
    cin.ignore(10000, '\n');
    getline(cin, movieTitle);
    
    if (movieTitle == "")
       {cout << "---" << endl;
        cout << "You must enter a title." << endl;
        return 1;}
    
    cout << "Base price: ";
    double basePrice;
    cin >> basePrice;
    
    if (basePrice < 0)
        {cout << "---" << endl;
        cout << "The base price must be nonnegative." << endl;
        return 1;}
    
    cout << "Premium item? (y/n): ";
    string premiumItem;
    cin.ignore(10000, '\n');
    getline(cin, premiumItem);
    
    if (premiumItem != "y" && premiumItem != "n")
       {cout << "---" << endl;
        cout << "You must enter y or n." << endl;
        return 1;}
    
    //compute royalties
    
    double royalties;
    
    if (numbersofUnits <= 400)
    royalties = basePrice * 0.09 * numbersofUnits;
    else if(400 < numbersofUnits && numbersofUnits <= 1200)
    {
         if (premiumItem == "y")
             royalties = 400 * 0.09 * basePrice + (numbersofUnits - 400) * 0.16 * basePrice;
        else
             royalties = 400 * 0.09 * basePrice + (numbersofUnits - 400) * 0.13 * basePrice;
    }
    else if (1200 < numbersofUnits)
    {    if (premiumItem == "y")
             royalties = 400 * 0.09 * basePrice + 800 * 0.16 * basePrice + (numbersofUnits - 1200) * 0.14 * basePrice;
         else
             royalties = 400 * 0.09 * basePrice + 800 * 0.13 * basePrice + (numbersofUnits - 1200) * 0.14 * basePrice;
    }
    
    //write results
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "---" << endl;
    cout << movieTitle << " earned $" << royalties << " in royalties." << endl;
        
    }
