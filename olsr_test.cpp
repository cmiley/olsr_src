
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "link_parser.h"

static size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* userp )
{
	( (string*) userp )->append( (char*) contents, size*nmemb );
	return size*nmemb;
}

using namespace std;

int main()
{
	int numLinks = 0;

	CURL *curl;
	CURLcode res;
	string readBuffer;

	curl = curl_easy_init();
	if( curl )
	{
		curl_easy_setopt( curl, CURLOPT_URL, "http://localhost:9090/links" );
		curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, WriteCallback );
		curl_easy_setopt( curl, CURLOPT_WRITEDATA, &readBuffer );
		res = curl_easy_perform( curl );
		curl_easy_cleanup( curl );
	}

	if( res != CURLE_OK )
	{
		cout << "Uh oh, curl had a problem with: " << res << endl;
		return 1;
	}

	rapidjson:: Document json_link;
	json_link.Parse( readBuffer.c_str() );

	const rapidjson:: Value& links = json_link["links"];
	assert( links.IsArray() );

	numLinks = json_link.Size();
	O_Link linkArr[numLinks];

	for( SizeType index = 0; index < json_link.Size(); index++ )
	{
		string str( links[index].GetString() );
		cout << str << endl << endl;
		parseLink( str, linkArr[index] );
	} 

	return 0;
}
