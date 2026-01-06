#pragma once


class IDamageable
{
private:
	
	int HP;
	

public:

	IDamageable()
	{
		HP = 1;
	}

	void SetHP (int i)
	{
		HP = i;
	}

	bool Dead() {
		return HP <= 0;
	}
	
	virtual void GetHurt() {
	
		HP--;
	}


};
