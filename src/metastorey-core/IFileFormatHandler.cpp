#pragma once
#include "IFileFormatHandler.h"


IFileFormatHandler::IFileFormatHandler(void)
{
}

IFileFormatHandler::~IFileFormatHandler(void)
{
}

str IFileFormatHandler::GetFileExtesnion(str path)
{
	int p=path.rfind('.');
	if (p==std::string::npos)
	{
		str empty;
		return empty;
	}
	else
	{
		return path.substr(p+1);
	}
}