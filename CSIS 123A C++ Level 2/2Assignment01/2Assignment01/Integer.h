#ifndef INTEGER
#define INTEGER

class Integer 
{
private:
	int in;

public:
	Integer();
	Integer(int i);

	void equals(int i);
	int toInt();
	Integer add(const Integer &f);
	Integer sub(const Integer &f);
	Integer mul(const Integer &f);
	Integer div(const Integer &f);
	void print();
};

#endif
