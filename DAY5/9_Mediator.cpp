// 6_Mediator - ������ ���� 
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		if (GetCheck() == true)
		{
			// ��ư enable
		}
		else 
			// ��ư disable
	}
};


int main()
{
	MyCheckBox c;
	c.SetCheck(true);
}



