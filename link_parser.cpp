#include "link_parser.h"

bool parseLink( string json, O_Link &toPopulate )
{
	if( json.size() < 2 )
	{
		return false;
	}
	else
	{
		Document doc;	
		doc.Parse( json.c_str() );

		const Value& localIP = doc["localIP"];
		const Value& remoteIP = doc["remoteIP"];
		const Value& linkQuality = doc["linkQuality"];
		const Value& neighborLinkQuality = doc["neighborLinkQuality"];
		const Value& linkCost = doc["linkCost"];

		IP local( localIP.GetString() );
		IP remote( remoteIP.GetString() );

		O_Link link( local, remote, linkQuality.GetDouble(),
				 neighborLinkQuality.GetDouble(), linkCost.GetInt() );

		toPopulate = link;

		return true;
	}
}