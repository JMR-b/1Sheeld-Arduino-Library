#ifndef CameraShield_h
#define CameraShield_h


#define CAPTURE 	0x01
#define SET_FLASH 	0x02
#define FLASH_OFF	0x00
#define FLASH_ON    0x01
#define FLASH_AUTO  0x02

class CameraShieldClass
{
public:
	CameraShieldClass();
	void capture ();
	void setFlash(byte value);
private:
	
};

extern CameraShieldClass Camera;
#endif 