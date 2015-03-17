#include "OneSheeld.h"
#include "NFCTag.h"




NFCTag::NFCTag(char * _tagId, int _tagSize, int _tagMaxSize, byte _recordsNumber)
{
	isTypeCallBackAssigned= false;
	isErrorCallBackAssigned= false;
	isDataCallBackAssigned= false;
	isParsedDataCallBackAssigned= false;

	int idLength=strlen(_tagId);
	tagId = (char *) malloc(sizeof(char)*idLength);
	memcpy(tagId,_tagId,idLength);

	tagSize =_tagSize;
	tagMaxSize =_tagMaxSize;
 	recordsNumber =_recordsNumber;
 	if(recordsNumber>0)
	{
		recordsArray = (NFCRecord **) malloc(sizeof(NFCRecord*)*recordsNumber);
		for (int i = 0; i < recordsNumber; i++)
		{
			recordsArray[i]=new NFCRecord();
		}
	}
}

NFCRecord * NFCTag::getRecords()
{
	return *recordsArray;
}

int NFCTag::getSize()
{
	return tagSize;
}

int NFCTag::getMaxSize()
{
	return tagMaxSize;
}

byte NFCTag::getNumberOfRecords()
{
	return recordsNumber;
}

bool NFCTag::isEmpty()
{
	return !!recordsNumber;
}

char * NFCTag::getId()
{
	return tagId;
}

void NFCTag::setOnError(void (*userFunction)(byte data))
{
	isErrorCallBackAssigned = true;
	errorCallBack = userFunction;
}

void NFCTag::setOnRecordTypeResponse(void (*userFunction)(byte id, byte data[]))
{
	isTypeCallBackAssigned =true;
	recordTypeCallBack = userFunction;
}

void NFCTag::setOnRecordParsedDataResponse(void (*userFunction)(byte id, char data[]))
{
	isParsedDataCallBackAssigned =true;
	recordParsedCallBack = userFunction;
}

void NFCTag::setOnRecordDataResponse(void (userFunction)(byte id,byte data []))
{
	isDataCallBackAssigned =true;
	recordDataCallBack = userFunction;
}

NFCTag::~NFCTag()
{
	if(recordsNumber>0)
	{
		for(int i=0;i<recordsNumber;i++)
			delete recordsArray[i];
		free (recordsArray);
	}
	free (tagId);
}