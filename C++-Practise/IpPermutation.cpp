#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
void valid( char *ip, int start, int end, int parts, string sub )
{
	cout<<"sub is "<<sub<<endl;
    if( !parts && start == end+1 ) {
		sub.erase( --sub.end() ); //remove last '.'
		cout << sub << endl;
		return;
	}
 
	if( end-start+1 < parts || end-start+1 > 3*parts ) {
		return;
	}
 
	sub +=ip[start];
	valid( ip, start+1, end, parts-1, sub + '.' ); //ip address sub section can be 1 digit
 
	sub += ip[start+1];
	valid( ip, start+2, end, parts-1, sub + '.' ); //ip address sub section can be 2 digit
 
	//3 digit ip section must be less than 256
	if( (ip[start]-'0')*100 + (ip[start+1]-'0')*10 + (ip[start+2]-'0') < 256 ) {
		sub += ip[start+2];
		valid( ip, start+3, end, parts-1, sub + '.' ); //ip address sub section can be 3 digit
	}
}
 
int main()
{
	char s[20];
	scanf( "%s", s );
 
	valid( s, 0, strlen(s)-1, 4, "" );
    cout<<"Length is "<<strlen(s)<<endl;
}
