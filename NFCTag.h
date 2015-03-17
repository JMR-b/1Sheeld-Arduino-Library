#ifndef TagClass_h
#define TagClass_h


#include "NFCRecord.h"

#define NFC_TAG_ON_TYPE     0x03
#define NFC_TAG_ON_PARSED   0x04
#define NFC_TAG_ON_DATA		0x05

class NFCTag
{
public:
	NFCTag(char *, int, int, byte);
	bool isEmpty();
	char * getId();
	byte getNumberOfRecords();
	NFCRecord * getRecords();
	int getSize();
	int getMaxSize();
	bool isInit();
	void setOnError(void (*)(byte));
	void setOnRecordTypeResponse(void (*userFunction)(byte , byte []));
	void setOnRecordParsedDataResponse(void (*userFunction)(byte , char[]));
	void setOnRecordDataResponse(void (userFunction)(byte ,byte []));
	~NFCTag();
private:
	bool isTypeCallBackAssigned;
	bool isErrorCallBackAssigned;
	bool isDataCallBackAssigned;
	bool isParsedDataCallBackAssigned;
	char * tagId;
	int tagSize;
	int tagMaxSize;
	byte recordsNumber;
	NFCRecord ** recordsArray;

	void (*errorCallBack)(byte);
	void (*recordTypeCallBack)(byte , byte[]);
	void (*recordParsedCallBack)(byte , char[]);
	void (*recordDataCallBack)(byte , byte[]);
	friend class NFCShield;
};

#endif