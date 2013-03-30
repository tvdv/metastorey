#include <algorithm>
#include <iostream>
#include <boost/filesystem.hpp>
#include "FileSystemRepository.h"

using namespace boost::filesystem;
using namespace std;

FileSystemRepository::FileSystemRepository(FileSystemRepositoryConfig const & config)
	: m_Config(config)
{
}




FileSystemRepository::~FileSystemRepository(void)
{
}


std::vector<std::shared_ptr<Node>> FileSystemRepository::GetNodes()
{
	std::vector<std::shared_ptr<Node>> nodes;

	auto paths=m_Config.GetPaths();
	std::for_each(begin(paths),end(paths),[&] (std::wstring & path)
	{
		if (!GetFileSystemNodes(path,nodes))
		{
			//TOOD: Throw exception?
		}
	}
	);
	

	return nodes;
}



bool FileSystemRepository::GetFileSystemNodes(std::wstring path,std::vector<std::shared_ptr<Node>> &list)
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

shared_ptr<Node> FileSystemRepository::CreateNode(wstring filePath)
{
	//TODO: implement using various 'filters'/'handlers' that manage different file formats/storage mechanisns to determine if the file is data or metadata
	return shared_ptr<Node>(NULL);
}