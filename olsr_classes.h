#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

static const char DEC_POINT = '.';
static const char NULL_CHAR = '\0';

class IP
{
	public:
		IP();
		IP( const IP& src );
		IP( const string& addr );
		IP( int addr1, int addr2, int addr3, int addr4 );
		~IP();
		string toString();
		int operator []( int index ) const;
		int& operator[]( int index );
		IP& operator=( const IP& src );

	private: 
		int addr[4];
		string saddr;
		void setzero();
		int atoi_c( char value );
};

class O_Link
{
	public:
		O_Link();
		O_Link( const O_Link& src );
		O_Link( IP local_src, IP remote_src, float lq, float nlq, int lc );
		~O_Link();
		void connection();
		IP& getLocal();
		IP& getRemote();
		float lq();
		float nlq();
		int lc();
		bool operator<( const O_Link& comp );
		bool operator>( const O_Link& comp );
		bool operator==( const O_Link& comp );
		O_Link& operator=( const O_Link& src );

	private:
		IP local;
		IP neighbor;
		float link_q;
		float nbor_link_q;
		int link_cost;

};