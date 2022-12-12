
#include<iostream>

#define getName(var)  #var
using namespace std;
int main()
{
    int myVary[3] = {3,2,1};
    printf("%s", getName(myVary[i]));
    return 0;
} 