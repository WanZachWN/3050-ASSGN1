#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void readAfile();
void aDFS();

int main()
{
    readAfile(); 6

    return 0;
}

void readAfile()
{
    string read;
    ifstream Afile ("DGraph.txt");
    if(Afile.is_open())
    {
        while(getline(Afile,read))
        {
            cout << read << '\n';
        }
        Afile.close();
    }
    else
        cout << "fail to read file";

    return;
}

void aDFS
(
    for(;;)
    {
        color(u) = black;
        for(;;)
        {
            for(;;)
            {
                if color(w) == 'white';
                {
                    color(w) = 'black';

                }
            }
        }
    }
)
