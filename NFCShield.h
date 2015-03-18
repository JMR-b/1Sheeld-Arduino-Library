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
	NFCTag * tag;
	void processData();
	void (*errorCallBack)(byte);
	void (*newTagCallBack)(NFCTag &);
	static NFCTag nullTag;
};

//Extern Object
extern NFCShield NFC;
#endif