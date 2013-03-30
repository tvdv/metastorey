#pragma once
#include "IRepository.h"

class FileSystemRepository :
	public IRepository
{
public:
	class FileSystemRepositoryConfig
	{
	public:
		std::vector<std::wstring> GetPaths() { return m_Paths;}

		std::vector<std::wstring> m_Paths;
	};
	
	FileSystemRepository(FileSystemRepositoryConfig const & config);

	virtual ~FileSystemRepository(void);

	virtual std::vector<std::shared_ptr<Node>> GetNodes();
private:

	FileSystemRepository(void);
	bool GetFileSystemNodes(std::wstring path,std::vector<std::shared_ptr<Node>> &list);
	std::shared_ptr<Node> CreateNode(std::wstring filePath);
	FileSystemRepositoryConfig m_Config;

};

