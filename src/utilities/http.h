

#ifndef HTTP_H
#define HTTP_H

#include "platform.h"
#include "types/hash.h"

#include <memory>

namespace ARK
{
namespace Utilities
{
namespace Network
{
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class HTTPConnectable;
/*************************************************/

/**************************************************************************************************/

/**************************************************
* ARK::Utilities::Network::HTTP 
*	Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*	entry point for integrating the HTTPClient
*	library for different boards/chipsets
**************************************************/
class HTTPInterface
{
	protected: 
    HTTPInterface() = default;

	public:
    virtual ~HTTPInterface() { }

    virtual std::string get(
		const char *const peer,
		int port,
		const char *const request
	) = 0;

	virtual bool post(
		const Hash& nethash,
		const char *const peer,
		uint16_t port,
		const char *const request_str,
		const char* const data
	) = 0;
};
/*************************************************/

/**************************************************************************************************/

/**************************************************
*	HTTP object factory
**************************************************/
std::unique_ptr<HTTPInterface> make_http();
/*************************************************/

};
};
};

/**************************************************
* ARK::Utilities::Network::Connectable 
*	Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
	public:
		std::unique_ptr<ARK::Utilities::Network::HTTPInterface> http;
		HTTPConnectable() : http(make_http()) { }
};
/*************************************************/

#endif
