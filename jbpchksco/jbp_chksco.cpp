/*

#include"jbp_chksco.h"
using namespace std;

int main(int argc,char** argv)
{
  chksco cChk(900000001,960676,964576,963920);
  char *tmp=cChk.getData();
  MD5 m(tmp,32);
  cout<<m.getMD5.c_str();
}

*/

#inlcude"jbp_chksco.h"

chksco::chksco(void)
{
	clear();
}

chksco::chksco(long tid,long bas,long adv,long ext)
{
	setValues(tid,bas,adv,ext);
}

chksco::~chksco(void)
{
	;
}

void chksco::clear(void)
{
	scoreRecord[0]=0;scoreRecord[1]=0;scoreRecord[2]=0;scoreRecord[3]=0;
	calcScore();
}

void chksco::calcScore(void)
{
	scoreRecord[4]=scoreRecord[1]+scoreRecord[2]; //bas+adv
	scoreRecord[5]=scoreRecord[2]+scoreRecord[3]; //adv+ext
	scoreRecord[6]=scoreRecord[1]+scoreRecord[3]; //bas+ext
	scoreRecord[7]=scoreRecord[1]+scoreRecord[2]+scoreRecord[3]; //bas+adv+ext
}

void chksco::setValues(long tid,long bas,long adv,long ext)
{
	scoreRecord[1]=bas;scoreRecord[2]=adv;scoreRecord[3]=ext;scoreRecord[0]=tid;
	calcScore();
}

char* chksco::getData(void)
{ 
	char *tmp=new char[32];
	for (int i=0;i<8;i++)
		for (int j=0;j<4;j++)
			tmp[i*4+j]=(scoreRecord[i] >> (j*8) ) &0xff;
	return(tmp);
}
