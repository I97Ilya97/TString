#include <iostream>
#include <assert.h>

#include "TString.h"

int main()
{
	TString str0;
	assert(str0 == "");

	TString str("str");
	assert(str == "str");

	{
		TString str1 = str;
		assert(str1 == str);
		assert(str1 == "str");
	}

	TString str2 = str + str;
	str2 += str;
	str2 += "123";
	assert(str2 == "strstrstr123");


	str0 = str2;
	assert(str0 == "strstrstr123");
	assert(str0 == str2);
	str0 = str0;
	assert(str0 == str2);

	str2.Replace('s', ' ');
	assert(str2 == " tr tr tr123");
	

	size_t found = str2.Find("tr12");
	assert(found == 7);
	found = str2.Find("uuuuuu"); // not found, returns -1
	assert(found == -1);


	str2.LTrim(' ');
	assert(str2 == "tr tr tr123");
	str2.RTrim('3');
	assert(str2 == "tr tr tr12");


	assert(str0 != str2);
	assert(str0 != "tr tr tr12");

	bool f1 = str != str2;
	assert(f1);

	bool f2 = str < str2;
	bool f3 = str > str2;

	char c = str[0];
	char c1 = str[1];
	assert(c == 's');
	assert(c1 == 't');

	str[0] = '1';
	assert(str[0] == '1');

	size_t sz = TString("size eq 9").Size();
	assert(sz == 9);

	assert(!str0.Empty());
	assert(TString().Empty());

	std::cout << str2 << " " << str << std::endl;

	system("pause");
}
