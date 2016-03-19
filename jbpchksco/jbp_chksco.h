#pragma once

#include<iostream>
using namespace std;

class chksco
{
	private:
		long scoreRecord[8];

		void calcScore(void);

	public:
		chksco(void);
		chksco(long,long,long,long);
		~chksco(void);

		void clear(void);

		void setValues(long,long,long,long);

		char* getData(void);
};
