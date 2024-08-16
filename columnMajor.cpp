#include <iostream>
using namespace std;

int main()
{
    int n = 5 ;
    int I[n];
    int S[n];
    int sum = 0;

    for (int i = n; i <= 0; i--)
    {
        int mul = I[i];
        for (int j = i - 1; j <= 0; j--)
        {
            mul *= S[j];
        }
        sum += mul;
    }
}