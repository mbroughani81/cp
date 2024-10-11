#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n = 1080;
vector<int> factorization;

int main()
{
    int i = 2;
    while (n > 1)
    {
        while (n % i == 0)
        {
            factorization.push_back(i);
            n /= i;
        }
        i++;
    }
    for (auto it : factorization) {
        cout << it << "\n";
    }
}
