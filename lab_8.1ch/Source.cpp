// ƒано л≥терний р€док, €кий м≥стить посл≥довн≥сть символ≥в s[0], ..., s[n], ... 
// 1. ¬и€снити, чи Ї в ц≥й посл≥довност≥ так≥ елементи s[iЦ1] , s[i+1]
// що s[iЦ1] Ц це знак плюс ('+'), а s[i+1] Ц знак м≥нус ('-'),
// та обчислити њх к≥льк≥сть.
// 2. «ам≥нити кожну групу символ≥в s[iЦ1] , s[i] , s[i+1] Ц таких, що
// s[iЦ1] Ц це знак плюс ('+'), а s[i+1] Ц знак м≥нус ('-')
// четв≥ркою з≥рочок "****".
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, ','))
	{
		pos = t - s + 1;
		if (s[pos ] == '-')
			k++;
	}
	return k;
}
char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, ','))
	{
		if (s[p - s + 1] == '-')
		{
			pos2 = p - s + 2;
			strncat(t, s + pos1, pos2 - pos1 - 2);
			strcat(t, "*");
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of ', -'" << endl;
	char* dest = new char[151];
		dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}