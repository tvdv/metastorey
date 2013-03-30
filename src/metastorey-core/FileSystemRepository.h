#pragma once
#include "irepository.h"
class FileSystemRepository :
	public IRepository
{
public:
	class FileSystemRepositoryConfig
	{
	public:
		std::vector<std::string> GetPaths();

		std::vector<std::string> m_Paths;
	};
	
	FileSystemRepository(FileSystemRepositoryConfig const & config);

	virtual ~FileSystemRepository(void);

	virtual std::vector<std::shared_ptr<Node>> GetNodes();
private:

	FileSystemRepository(void);
	bool GetFileSystemNodes(std::string path,std::vector<std::shared_ptr<Node>> &list);
	FileSystemRepositoryConfig m_Config;

};

