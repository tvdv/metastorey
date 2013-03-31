#pragma once
#include "config.h"
#include "node.h"
class FileSystemNode :
	public Node
{
public:
	FileSystemNode(void);
	~FileSystemNode(void);


	str GetFileSystemPath();

};

