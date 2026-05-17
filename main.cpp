#include <iostream>
#include <string>

#include "file.h"

using namespace std;

int main (int argc, char** argv)
{
    cout << "-2";
    if(argc == 2)
    {
        cout << "-1";
        string content = argv[1];
        File::WriteAfterToken("docs/index.html","<!--BLOGPOINT-->",content);
    }
    return 0;
}