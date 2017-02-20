#include "TString.h"
#include <iostream>
#include <string>	   
#include <stdlib.h>

TString::~TString()
{
	if(Data != nullptr)
		delete[] Data;
}

TString::TString()
{
	Data = new char[1];
	Data[0] = '\0';
}

TString::TString(const char *data)
{
	int length = 0;
	while(data[length]) length++;
	Data = new char[length + 1];
	for(int i = 0; i <= length; i++)
		Data[i] = data[i];
}

TString::TString(const TString &rhs)
{
	int length = rhs.Size();
	Data = new char[length + 1];
	for(int i = 0; i <= length; i++)
		Data[i] = (rhs.Data)[i];
}

TString operator+(const TString &a, const TString &b)
{
	TString result(a);
	result += b;
	return result;
}

bool operator !=(const TString &a, const TString &b)
{
	return !(a == b);
}

char TString::operator[](size_t index) const
{
	return Data[index];
}

char& TString::operator[](size_t index)
{
	return Data[index];
}

void TString::Replace(char oldSymbol, char newSymbol)
{
	int length = Size();
	for(int i = 0; i < length; i++)
		if(Data[i] == oldSymbol)
			Data[i] = newSymbol;
}

size_t TString::Size() const
{
	size_t length = 0;
	while(Data[length]) length++;
	return length;
}

bool TString::Empty() const
{
	return (Size() == 0);
}

std::ostream & operator<<(std::ostream &out, const TString &rhs)
{
	out << rhs.Data;
	return out;
}

bool operator >(const TString &a, const TString &b)
{
	if(a == b) return false;
	if(a < b) return false;
	return true;
}

size_t TString::Find(const TString &substr) const
{
	int len1 = Size();
	int len2 = 0;
	int k = 0;
	while(substr[len2]) len2++;
	for(int i = 0; i <= len1 - len2; i++)
	{
		for(k = 0; k < len2; k++) {
			if(Data[k + i] != substr[k]) break;
		}
		if(k == len2) return i;
	}
	return -1;
}

void TString::RTrim(char symbol)
{
	int len = Size();
	int i = 0;
	while(Data[len - i - 1] == symbol) i++;
	if(i == 0) return;
	char *str = new char[len - i + 1];
	for(int k = 0; k < len - i; k++)
		str[k] = Data[k];
	str[len - i] = '\0';
	delete[] Data;
	Data = str;
}

void TString::LTrim(char symbol)
{
	int len = Size();
	int i = 0;
	while(Data[i] == symbol) i++;
	if(i == 0) return;
	char *str = new char[len - i + 1];
	int k = 0;
	for(; k <= len - i; k++)
		str[k] = Data[k + i];
	delete[] Data;
	Data = str;
}

TString& TString::operator=(const TString &rhs)
{
	if(*this == rhs) return *this;
	delete[] Data;
	int len = rhs.Size();
	Data = new char[len + 1];
	int i = 0;
	for(i = 0; i <= len; i++)
		Data[i] = (rhs.Data)[i];
	return *this;
}

TString& TString::operator+=(const TString &rhs)
{
	int len1 = Size();
	int len2 = rhs.Size();
	char *str = new char[1 + len1 + len2];
	int i = 0;
	for(; i < len1; i++)
		str[i] = Data[i];
	for(i = 0; i <= len2; i++)
		str[len1 + i] = rhs.Data[i];
	delete[] Data;
	Data = str;
	return *this;
}

bool TString::operator ==(const TString &rhs) const
{
	int len1 = Size();
	int len2 = rhs.Size();
	if(len1 != len2) return false;
	int i = 0;
	while(Data[i] == rhs.Data[i] && i < len1 && i < len2) i++;
	if(i == len1 || i == len2) return true;
	else return false;
}

bool TString::operator <(const TString &rhs) const
{
	int i = 0;
	int len1 = Size();
	int len2 = rhs.Size();
	while(i <= len1 && i <= len2)
	{
		if(Data[i] < rhs.Data[i]) return true;
		if(Data[i] > rhs.Data[i]) return false;
		i++;
	}
	return false;
}
