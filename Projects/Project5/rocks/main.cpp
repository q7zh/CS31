#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <utility>
using namespace std;

int manageOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum);

int main()
{
    int t;
    char wordList[10000][MAXWORDLEN+1];
    int n = loadWords(wordList, 10000);      //modification for test propose
    int total = 0;
    int max = 0;
    int min = 0;
    
    if (n < 1)
    {
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }
    
    //get rounds
    
    int rounds;
    cout << "How many rounds do you want to play? ";
    cin >> rounds;
    
    if (rounds < 1)
    {
        cout << "The number of rounds must be positive." << endl;
        return 0;
    }
    
    for (int i = 1; i <= rounds; i++)
    {
        cout << endl << "Round " << i << endl;
        
        //get the secret word
        
        int k = randInt(0, n - 1);
        //cerr << wordList[k] << endl;
        
        //write the length of the secret word
        
        cout << "The secret word is " << strlen(wordList[k]) << " letters long." << endl;
        
        //compute the number of tries
        
        t = manageOneRound(wordList, n, k);
        
        //write results
        
        if (t == 1)
            cout << "You got it in " << t << " try." << endl;
        else
            cout << "You got it in " << t << " tries." << endl;
        
        //calculate average, minimun and maximun
        
        total = total + t;
        if (t > max)
            max = t;
        if (i == 1)
            min = t;
        if (t < min)
            min = t;
        
        //write results
        
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "Average: " << static_cast<double>(total)/i << ", minimum: " << min << ", maximum: " << max << endl;
    }
}



int manageOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum)
{
    if (nWords < 0 || wordnum < 0 || wordnum >= nWords)
        return -1;
    
    int n = 1;
    char word[100];
    while (strcmp(word, words[wordnum]) != 0)
    {
        //get probe word
        
        cout << "Probe word: ";
        cin >> word;
        
        //whether it is a word of 4 to 6
        
        if (strlen(word) < 4 || strlen(word) > 6)
        {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }

        //whether it consists of lower case letters
        
        int k;
        for (k = 0; word[k] != '\0'; k++)
            {
                if (isalpha(word[k]))
                {
                    if(isupper(word[k]))
                    {
                        cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
                        break;
                    }
                    continue;
                }
                cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
                break;
            }
        if (k < strlen(word))
            continue;
        
        // whether it belongs to the wordlist
        
        int p = 0;
        for (int i = 0; i < nWords; i++)
        {
            p = strcmp(word, words[i]);
            if (p == 0)
                break;
        }
        if (p != 0)
        {
            cout << "I don't know that word." << endl;
            continue;
        }
        
        //if right guess
        
        if (strcmp(word, words[wordnum]) == 0)
            return n;
       
        //count rocks and pebbles
        
        char v[6] = "";
        int R = 0;
        int P = 0;
        
        //count rocks
        
        for (int m = 0; word[m] != '\0'; m++)
        {
            if (word[m] == words[wordnum][m])
            {
                v[m] = words[wordnum][m];
                R++;
            }
        }
        
        //count pebbles
        
        for (int g = 0; word[g] != '\0'; g++)
        {
            if (word[g] == v[g])
                continue;
            for (int b = 0; words[wordnum][b] != '\0'; b++)
            {
                if (word[g] == words[wordnum][b])
                {
                    if(words[wordnum][b] != v[b])
                    {
                        v[b] = words[wordnum][b];
                        P++;
                        break;
                    }
                }
            }
        }
        
        //write results
        
        cout << "Rocks: " << R << ", Pebbles: " << P << endl;
        n++;
        
    }
    return n;
}