#include <bits/stdc++.h>
using namespace std;

inline int rd() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar())
    x = x * 10 + (c ^ 48);
  return f ? -x : x;
}

const double pi = acos(-1);

inline void work() {
  int n = rd();
  int r = rd();
  if (n <= 2) puts("QAQ");
  else printf("%.5lf\n", r * sin(pi / n) / (1.0 - sin(pi / n)));
}

int main() {
  int t = rd();
  while (t--) work();
  return 0;
}