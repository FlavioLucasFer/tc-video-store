#ifndef __TC_VIDEO_STORE_CLIENT_COLLECTION__
#define __TC_VIDEO_STORE_CLIENT_COLLECTION__

#include <list>
#include <inttypes.h>
#include "lib.h"
#include "client.h"

class client_collection_t
{
	private:
		std::list<client_t> clients;

	public:
		client_t* get_client_by_id (uint16_t id);
		void add (client_t client);
		void update (uint16_t id, std::string name, std::string email, std::string phone_number);
		void remove (uint16_t id);
		void list ();

	void operator << (const client_t client)
	{
		this->add(client);
	}
};

#endif
