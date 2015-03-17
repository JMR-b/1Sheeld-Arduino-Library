#ifndef NFCShield_h
#define NFCShield_h

#define NFC_GET_BASIC_INFO 0x01
#define NFC_ON_ERROR	   0x02

#include "ShieldParent.h"
#include "NFCTag.h"
#include "NFCRecord.h"

class NFCShield : public ShieldParent
{
public:
	NFCShield();
	NFCTag & getLastTag();
	bool isNewTagScanned();
	void setOnNewTagScanned(void (*)(NFCTag &));
	void setOnError(void (*)(byte));
private:
	bool isErrorAssigned;
	bool isNewTag;
	bool isNewTagSetOnAssigned;
	int tagSize;
	int tagUsedSize;
	NFCTag * tag;
	void processData();
	void (*errorCallBack)(byte);
	void (*newTagCallBack)(NFCTag &);
};

//Extern Object
extern NFCShield NFC;
#endif