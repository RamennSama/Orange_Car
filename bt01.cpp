#include<iostream>
using namespace std;

int ThayTriet(int a[], int n, int key){
  int ans = (a[0] + a[n - 1]);
  ans /= 2;
  if(key >= ans){
    for(int i = n - 1; key >= a[i]; i--){
      if(a[i] == key){
        return 1;
        }
      }
    }
  else{
  for(int i = 0; a[i] <= key; i++){
      if(a[i] == key){
        return 1;
        }
      }
    }
  return -1;
  }

int main(){
  int n; cin >> n;
  int a[n];
  for(auto &x : a) cin >> x;
  int key; cin >> key;
  cout << (ThayTriet(a, n, key) != -1 ? "key\n": "NO\n");
  return 0;
  }
	
