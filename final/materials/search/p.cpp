#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define vt vector
#define itn int
const int MAXN = 1e9;

 
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int w, h, n;
  cin >> w >> h >> n;
  long long left = min(w, h), right = n * 1ll * max(w, h), middle;
  while (true)
  {
    if (left + 1 > right) {
      break;
    }
    middle = (right + left) / 2;
    if (n <= (middle / w) * 1ll * (middle / h)) {
      right = middle;
    } else {
      left = middle + 1;
    }
  }
  cout << left;  
  return 0;
}