#include <iostream>
#include <map>

using namespace std;


void	count_words()
{
	map<string, int> dict;
	string s;

	while(cin >> s)
		++dict[s];

	map<string,int>::iterator it= dict.begin();
	for(; it != dict.end(); ++it)
		cout << it->first << ": " << it->second << endl;
}

int main()
{
	count_words();
	return 0;
}
