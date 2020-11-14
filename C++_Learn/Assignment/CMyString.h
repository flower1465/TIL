#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class CMyString
{
public:
	CMyString();

	CMyString(const CMyString&);

	explicit CMyString(const char*);

	CMyString(CMyString&&);

	int GetLength() const;

	int Append(const char*);

	operator char* () const;

	CMyString& operator=(const CMyString&);

	CMyString operator+(const CMyString&);

	CMyString& operator+=(const CMyString&);

	char& operator[](int);

	char operator[](int) const;

	int operator==(const CMyString&);

	int operator!=(const CMyString&);

	~CMyString();

	int SetString(const char*);

	const char* GetString() const;

	void Release();

	virtual void OnSetString(char* pszData, int nLength);
private:

	char* m_pszData;

	int m_nLength;
};

