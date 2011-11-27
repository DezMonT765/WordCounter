#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp> 
#include <boost/algorithm/string/compare.hpp> 
#include <boost/foreach.hpp>
using namespace std;
using namespace boost;
struct StringAndCount
{
	string str;
	int count;
};
void Count(vector<string> s, int razmer)
{	StringAndCount strandcount;
	strandcount.count=0;
	bool *b=new bool[razmer];
	for(int i=0;i<razmer;i++)
	{
		b[i]=true;
	}
	
	int minvalue=100;
	int maxvalue=0;
	list<StringAndCount> CountedAndSortedString;
	for(int i=0;i<razmer; i++)
	{	if(b[i]==true)
	{
		strandcount.str=s[i];
		for(int j=0;j<razmer;j++)
			if(b[j]==true)
			{
		if(!strandcount.str.compare(s[j]))
		{
			strandcount.count++;
			b[j]=false;
		}
			}
			if(strandcount.count<=minvalue)
			{
				CountedAndSortedString.push_back(strandcount);
				minvalue=strandcount.count;
			}
			else
				if(strandcount.count>=maxvalue)
				{
					CountedAndSortedString.push_front(strandcount);
					maxvalue=strandcount.count;
				}
		strandcount.count=0;
	}
	}
	BOOST_FOREACH(StringAndCount strandcount,CountedAndSortedString)
	{
		cout<<strandcount.str<<" "<<strandcount.count<<endl;
	}
}
int main()
{	
	ifstream f("1.txt",ios::in);
	vector<string> s;
	string stream;
	int stringcount = 0;
	int charcount = 0;
	while(!f.eof())
	{
	f>>stream;
	s.push_back(stream);
	stringcount++;
	}
	Count(s,stringcount);
	getchar();
	return 0;
}