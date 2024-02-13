#ifndef INTEGER
#define INTEGER

class Integer
{
private:
	int in;
public:
	Integer();
	Integer(Integer &i);
	Integer(int pi);
	Integer(double pd);

	void equals(int pi);
	int toInt() const;
	Integer add(int pi);
	Integer sub(int pi);
	Integer mul(int pi);
	Integer div(int pi);
	Integer add(const Integer &i);
	Integer sub(const Integer &i);
	Integer mul(const Integer &i);
	Integer div(const Integer &i);
	void print();
};

#endif

