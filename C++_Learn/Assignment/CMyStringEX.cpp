#include "CMyString.h"
#include "CMyString.cpp"
#include "CMyStringEx.h"

CMyStringEx::CMyStringEx(const char* pszData)
{
	this->SetString(pszData);
}

int CMyStringEx::Find(const char* pszData)
{
	const char* result = strstr(this->GetString(), pszData);
	if (result != nullptr) {
		return (result - this->GetString()) / sizeof(char);
	}
	return -1;
}

int CMyStringEx::SetString(const char* pszParam)
{
	if (!strcmp(pszParam, "멍멍이아들")) {
		return CMyString::SetString("좋은 사람");
	}
	else {
		return CMyString::SetString(pszParam);
	}
}