#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    ll a[26]={0};
    for (ll i = 0; i < s.length()-1; i++) {
      if(s[i]==s[i+1] && s[i]!='0')
      {
        s[i]='0';
        s[i+1]='0';
      }
    }
    for (ll i = 1; i < s.length(); i++) {
      if(s[i]==s[i-1] && s[i]!='0')
      {
        s[i]='0';
        s[i+1]='0';
      }
    }
    set<char> st;
    for (ll i = 0; i < s.length(); i++) {
      if(s[i]!='0')
      st.insert(s[i]);
    }
    for(auto it:st)
    cout << it;
 
    cout << endl;
  }
}
