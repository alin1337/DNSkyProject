#define THA_KAWAII

extern BYTE cheimagice[];
bool cryptpakv3(const std::string& s);

//
void encrypt_xml(const std::string& s);
void decrypt_xml(const std::string& s);

struct SPackingFileHeader
{
	char szHeaderString[256];
	int nVersion;
	int nFileCount;
	DWORD dwFileInfoOffset;
	bool bRequireHeaderWrite;
	char cPadding[3];
};


struct SPackingFileInfo
{
	char szFileName[_MAX_FNAME];
	DWORD dwCompressSize;
	DWORD dwOriginalSize;
	DWORD dwAllocSize;
	DWORD dwOffset;
	DWORD dwSeedValue;
	DWORD dwChecksum;
	char cReserved[36];
};


//bool cryptpakv3(const string& s);