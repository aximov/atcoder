#include <array>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  regex re_0("^keyence.*");
  regex re_1("^k.*eyence$");
  regex re_2("^ke.*yence$");
  regex re_3("^key.*ence$");
  regex re_4("^keye.*nce$");
  regex re_5("^keyen.*ce$");
  regex re_6("^keyenc.*e$");
  regex re_7(".*keyence$");
  smatch match;
  array<regex, 8> res{re_0, re_1, re_2, re_3, re_4, re_5, re_6, re_7};
  for (auto re : res) {
    if (regex_match(s, match, re)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}