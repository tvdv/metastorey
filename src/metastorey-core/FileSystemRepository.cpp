#include <algorithm>
#include <iostream>
#include <boost/filesystem.hpp>
#include "FileSystemRepository.h"

using namespace boost::filesystem;
using namespace std;

namespace MetaStorey {

FileSystemRepository::FileSystemRepository(FileSystemRepositoryConfig const & config)
	: m_Config(config),
	 m_Handler(config.GetHandler())
{
}




FileSystemRepository::~FileSystemRepository(void)
{
}


std::vector<std::shared_ptr<Node>> FileSystemRepository::GetNodes()
{
	std::vector<std::shared_ptr<Node>> nodes;

	auto paths=m_Config.GetPaths();
	std::for_each(begin(paths),end(paths),[&] (str & path)
	{
		if (!GetFileSystemNodes(path,nodes))
		{
			//TOOD: Throw exception?
		}
	}
	);
	

	return nodes;
}



bool FileSystemRepository::GetFileSystemNodes(str path,std::vector<std::shared_ptr<Node>> &list)
{
	//check if path exists
	if (!exists(path))
	{
		return false;
	}

	if (!is_directory(path))
	{
		return false;
	}

	directory_iterator enditer;
	directory_iterator it=directory_iterator(path);
	while (it != enditer)
	{
		if (is_directory(it->path()))
		{
			if (!GetFileSystemNodes(it->path().native(),list))
			{
				return false;
			}
		}
		else
		{
			auto ptr=CreateNode(it->path().native());
			if (ptr.get()==NULL)
			{
				//failed to create, ignore
			}
			else
			{
				list.push_back(ptr);
			}
		}
		++it;
	}
	
	return true;
}

shared_ptr<Node> FileSystemRepository::CreateNode(str filePath)
{
	shared_ptr<Node> ptr=m_Handler->CreateNode(filePath); //may return a shared_ptr to NULL if the device should not be a node

	
	return ptr; 
}

}