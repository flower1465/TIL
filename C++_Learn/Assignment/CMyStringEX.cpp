#include "./CMyStringEX.h"
#include <string.h>
#include "CMyString.h"
#include "CMyString.cpp"

int CMyStringEx::Find(const char* Param) {
	char* buf = GetString();
	if (buf == NULL)
		return -1;
	char* index = strstr(buf, Param);
	if (index == NULL)
		return -1;
	return (int)(index - buf);

}