#ifndef INTEGER
#define INTEGER

class Integer
{
private:
	int in;
public:
	void equals(int i);
	int toInt();
	Integer add(const Integer &i);
	Integer sub(const Integer &i);
	Integer mul(const Integer &i);
	Integer div(const Integer &i);
	void print();
};

#endif
