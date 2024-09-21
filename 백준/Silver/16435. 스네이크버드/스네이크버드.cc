#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
  int n, l;
  vector<int> fruit;

  cin >> n >> l;

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    fruit.push_back(temp);
  }

  sort(fruit.begin(), fruit.end());

  for(int j = 0; j < n; j++){
    if(fruit[j] <= l) l++;
    else break;
  }
  cout << l;
}