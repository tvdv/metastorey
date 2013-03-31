#pragma once
#include "config.h"
#include "IRepository.h"
#include "IFileFormatHandler.h"
class FileSystemRepository :
	public IRepository
{
public:
	class FileSystemRepositoryConfig
	{
	public:
		std::vector<str> GetPaths() const { return m_Paths;}
		std::shared_ptr<IFileFormatHandler> GetHandler() const  { return m_Handler;}

		std::vector<str> m_Paths;

		std::shared_ptr<IFileFormatHandler> m_Handler;
	};
	
	FileSystemRepository(FileSystemRepositoryConfig const & config);

	virtual ~FileSystemRepository(void);

	virtual std::vector<std::shared_ptr<Node>> GetNodes();
private:

	FileSystemRepository(void);
	bool GetFileSystemNodes(str path,std::vector<std::shared_ptr<Node>> &list);
	std::shared_ptr<Node> CreateNode(str filePath);
	FileSystemRepositoryConfig m_Config;


	std::shared_ptr<IFileFormatHandler> m_Handler; //most likely to be an IFileFormatHandler that internally has a chain of them, to support multiple formats

};

