#include "OneSheeld.h"
#include "NFCRecord.h"



NFCRecord::NFCRecord()
{
	recordType =0;
	recordTypeLength =0;
	recordDataLength =0;
}

byte NFCRecord::getType()
{
	return recordType;
}
	
int NFCRecord::getTypeLength()
{
	return recordTypeLength;
}

int NFCRecord::getDataLength()
{
	return recordDataLength;
}

void NFCRecord::queryData(int start,byte size)
{
	byte startArray[2] ;
	  	startArray[1] = (start >> 8) & 0xFF;
	  	startArray[0] = start & 0xFF;

	OneSheeld.sendPacket(NFC_ID,0,NFC_RECORD_QUERY_DATA,2,new FunctionArg(2,startArray),new FunctionArg(1,&size));
}

void NFCRecord::queryType(int start,byte size)
{
	byte startArray[2] ;
	  	startArray[1] = (start >> 8) & 0xFF;
	  	startArray[0] = start & 0xFF;

	OneSheeld.sendPacket(NFC_ID,0,NFC_RECORD_QUERY_TYPE,2,new FunctionArg(2,startArray),new FunctionArg(1,&size));

}

void NFCRecord::queryParsedData()
{
	OneSheeld.sendPacket(NFC_ID,0,NFC_RECORD_QUERY_PARSED_DATA,0);
}