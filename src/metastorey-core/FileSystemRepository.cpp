#include <algorithm>
#include "FileSystemRepository.h"


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
	std::for_each(begin(paths),end(paths),[&] (std::string & path)
	{
		if (!GetFileSystemNodes(path,nodes))
		{
			//TOOD: Throw exception?
		}
	}
	);
	

	return nodes;
}



bool FileSystemRepository::GetFileSystemNodes(std::string path,std::vector<std::shared_ptr<Node>> &list)
{
	//TODO: Implement
	return false;
}