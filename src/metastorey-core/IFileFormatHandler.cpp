#pragma once
#include "IFileFormatHandler.h"

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