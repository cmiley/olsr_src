#include "olsr_classes.h"

IP::IP()
{
	this->setzero();
}

IP::IP( const IP& src )
{
	*this = src;
}

IP::IP( const string& address )
{
	int num, index, numIndex;
	int strIndex = 0;
	int numArr[3] = {0,0,0};

	if( address.length() < 7 || address.length() > 15 )
	{
		this->setzero();
	}
	else
	{
		for( index = 0; index < 4; index++ )
		{
			num = 0;
			numIndex = 0;

			while( address[strIndex] != DEC_POINT && address[strIndex] != NULL_CHAR )
			{
				numArr[numIndex] = atoi_c( address[strIndex] );
				numIndex++;
				strIndex++;
			}

			if( numIndex == 1 )
			{
				num = numArr[0];
			}
			else if( numIndex == 2 )
			{
				num = numArr[1] + numArr[0]*10 ;
			}
			else if( numIndex == 3 )
			{
				num = numArr[2] + numArr[1]*10 + numArr[0]*100;
			}
			else
			{
				num = 0;
			}
		
			addr[index] = num;

			cout << num << " final" << endl;

			strIndex++;
		}

		saddr = address;
	}
}

IP:: IP( int addr1, int addr2, int addr3, int addr4 )
{
	addr[0] = addr1;
	addr[1] = addr2;
	addr[2] = addr3;
	addr[3] = addr4;

	string str = to_string( addr[0] );
	str.append( "." );
	str.append( to_string( addr[1] ) );
	str.append( "." );
	str.append( to_string( addr[2] ) );
	str.append( "." );
	str.append( to_string( addr[3] ) );

	saddr = str;
}

IP:: ~IP()
{
	// Graceful destruction
}

string IP:: toString()
{
	return saddr;
}

int IP:: operator []( int index ) const
{
	if( index >=0 && index < 4 )
	{
		return addr[index];
	}
	else return 0;
}

int& IP:: operator[]( int index )
{
	if( index >=0 && index < 4 )
	{
		return addr[index];
	}
	else return addr[0];
}

void IP:: setzero()
{
	int index; 

	for( index = 0; index < 4; index++ )
	{
		addr[index] = 0;
	}

	saddr = "0.0.0.0";
}

int IP:: atoi_c( char value )
{
	int num = value - '0';
	cout << value << ' ' << num << " num" << endl;
	return num;
}

IP& IP:: operator=( const IP& src )
{
	addr[0] = src.addr[0];
	addr[1] = src.addr[1];
	addr[2] = src.addr[2];
	addr[3] = src.addr[3];
	saddr = src.saddr;

	return *this;
}

// O-Link Class ///////////////////////////////////////////////////////

O_Link:: O_Link()
{
	local = IP();
	neighbor = IP();
	link_q = nbor_link_q = 0.0;
	link_cost = 0;
}

O_Link:: O_Link( const O_Link& src )
{
	*this = src; 
}

O_Link:: O_Link( IP local_src, IP remote_src, float lq, float nlq, int lc )
{
	local = local_src;
	neighbor = remote_src;
	link_q = lq;
	nbor_link_q = nlq;
	link_cost = lc;
}

O_Link:: ~O_Link()
{
	// graceful destruction
}

void O_Link:: connection()
{
	cout << local.toString() << " to " << neighbor.toString() << endl;
}

float O_Link:: lq()
{
	return this->link_q;
}

float O_Link:: nlq()
{
	return this->nbor_link_q;
}

int O_Link:: lc()
{
	return this->link_cost;
}

bool O_Link:: operator<( const O_Link& comp )
{
	return false;
}

bool O_Link:: operator>( const O_Link& comp )
{
	return false;
}

bool O_Link:: operator==( const O_Link& comp )
{
	return false;
}

O_Link& O_Link:: operator=( const O_Link& src )
{
	local = src.local;
	neighbor = src.neighbor;
	link_q = src.link_q;
	nbor_link_q = src.nbor_link_q;
	link_cost = src.link_cost;
	
	return *this;
}