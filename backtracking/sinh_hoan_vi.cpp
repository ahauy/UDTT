#include <iostream>

using namespace std;

int a[100], n;
bool flag[100];

void display()
{
  for (int i = 1; i <= n; i++)
  {
    cout << a[i];
  }
  cout << endl;
}

void Try(int i)
{
  for (int j = 1; j <= n; j++)
  {
    if (!flag[j])
    {
      flag[j] = true;
      a[i] = j;
      if (i == n)
      {
        display();
      }
      else
      {
        Try(i + 1);
      }
      flag[j] = false;
    }
  }
}

int main()
{

  n = 3;
  Try(1);
  return 0;
}