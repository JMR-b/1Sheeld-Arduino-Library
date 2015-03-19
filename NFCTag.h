/*

  Project:       1Sheeld Library 
  File:          NFCTag.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/

#ifndef TagClass_h
#define TagClass_h


#include "NFCRecord.h"

//Input Function ID
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
	NFCRecord & getRecord(int);
	int getSize();
	int getMaxSize();
	void setOnError(void (*)(byte));
	void setOnRecordTypeResponse(void (*userFunction)(byte , byte []));
	void setOnRecordParsedDataResponse(void (*userFunction)(byte , char[]));
	void setOnRecordDataResponse(void (userFunction)(byte ,byte []));
	bool isNull();
	~NFCTag();
private:
	NFCTag();
	bool isTypeCallBackAssigned;
	bool isErrorCallBackAssigned;
	bool isDataCallBackAssigned;
	bool isParsedDataCallBackAssigned;
	char * tagId;
	int tagSize;
	int tagMaxSize;
	byte recordsNumber;
	NFCRecord ** recordsArray;
	static NFCRecord nullRecord;

	void (*errorCallBack)(byte);
	void (*recordTypeCallBack)(byte , byte[]);
	void (*recordParsedCallBack)(byte , char[]);
	void (*recordDataCallBack)(byte , byte[]);
	friend class NFCShield;
};

#endif