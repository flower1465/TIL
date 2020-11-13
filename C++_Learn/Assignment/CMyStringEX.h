#pragma once
#include "CMyString.h"
class CMyStringEx :
	public CMyString
{
public:
	CMyStringEx() {}

	~CMyStringEx() {}

	CMyStringEx(const char* pszData);

	int Find(const char* pszData);

	int SetString(const char* pszParam);
};