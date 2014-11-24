#ifndef DATE
#define DATE

class Date
{
public:
	Date(int, int, int);
	
	int day();
	int month();
	int year();
	
	Date operator+(const &Date) const;
	Date operator-(const &Date) const;
	bool operator==(const &Date) const;
	
	friend ostream& operator<<(ostream&, const Date&);
	
};

#endif