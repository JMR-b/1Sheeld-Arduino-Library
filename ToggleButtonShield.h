#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h



class ToggleButtonShield
{
public:
	ToggleButtonShield();
	byte getValue();
	void processData();
	void setOnChange(void (*userFunction)(byte));
private:
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);
};

extern ToggleButtonShield ToggleButton;
#endif