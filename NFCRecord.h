#ifndef NFCRecord_h
#define NFCRecord_h

#define NFC_RECORD_QUERY_DATA 0x01
#define NFC_RECORD_QUERY_TYPE 0x02
#define NFC_RECORD_QUERY_PARSED_DATA 0x03


class NFCRecord
{
public:
	NFCRecord();
	byte getType();
	int getTypeLength();
	int getDataLength();
	void queryData(int ,byte);
	void queryType(int ,byte);
	void queryParsedData();
private:
	byte recordType;
	int recordTypeLength;
	int recordDataLength;
friend class NFCShield;
};

#endif