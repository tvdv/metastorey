#pragma once
#include "node.h"
class FileSystemNode :
	public Node
{
public:
	FileSystemNode(void);
	~FileSystemNode(void);


	std::string GetFileSystemPath();

};

