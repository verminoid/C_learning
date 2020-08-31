#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
	public:
		ReversibleString () {}
		ReversibleString (const string& new_s) {
			data = new_s;
		}



		string ToString () const {
			return data;
		}
		void Reverse () {

			reverse(begin(data),end(data));


		}

	private:
		string data;

};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
