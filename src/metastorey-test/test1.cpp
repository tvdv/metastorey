#include <gtest/gtest.h>
#include "IRepository.h"
#include "FileSystemRepository.h"
#include "MP3Handler.h"

using namespace MetaStorey;

TEST(BASIC, TEST) {

	FileSystemRepository::FileSystemRepositoryConfig config;
	config.m_Paths.push_back(L"f:\\test"); //TODO: take path from cmd line, or commit some basic test data with unit tests
	config.m_Handler=std::shared_ptr<IFileFormatHandler>(new MP3Handler);
	std::unique_ptr<IRepository> repo(new FileSystemRepository(config));

	auto nodes=repo->GetNodes();

	ASSERT_FALSE( nodes.size() == 0 );
	 
}