#include <iostream>
#include <string>
#include <set>

using namespace std;

string GetRuler(const string& kingdom) {
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  char end = kingdom.back();
  char const init_s [] = {
      'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'
  };
  set<char> s (std::begin(init_s), std::end(init_s));
  if (end == 'y' || end == 'Y') ruler = "nobody";
  else if (s.find(end) != s.end()) ruler = "Alice";
  else ruler = "Bob";
  return ruler;
}

int main() {
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t) {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}
