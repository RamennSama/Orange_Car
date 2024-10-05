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

void bai1_2(){
	int n; cin >> n;
    int a[n]; int soDuong = 0, soNam = 0;
    for(auto &x : a){
    cin >> x;
    soDuong += (x > 0) ? 1 : 0;
    soNam += (x == 5) ? 1 : 0;
    }
  int key; cin >> key;
  cout << (ThayTriet(a, n, key) != -1 ? "key\n": "NO\n");
  cout << soDuong << ' ' << soNam << endl;
}

struct HocSinh{
	string name;
	int point;
};

void nhap(HocSinh a[], int n){
	for(int i = 0; i < n; i++){
		cin >> a[i].name >> a[i].point;
		}
	}

void check(HocSinh a[], int n){
	cout << "--DANH SACH HOC SINH GIOI--\n";
	for(int i = 0; i < n; i++){
		if(a[i].point >= 8){
			cout << a[i].name << ' ' << a[i].point << endl;
			}
		}
	}
	
	

int main(){
	int n; cin >> n;
	HocSinh a[n];
	nhap(a, n);
	check(a, n);
}
	
