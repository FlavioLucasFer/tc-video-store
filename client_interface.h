#ifndef __TC_VIDEO_STORE_CLIENT_INTERFACE__
#define __TC_VIDEO_STORE_CLIENT_INTERFACE__

#include "lib.h"
#include "client_collection.h"

enum class client_interface_state_t
{
	MENU,
	CREATE,
	LIST,
	UPDATE,
	DELETE,
};

#define	CLIENT_INTERFACE_MENU_STATE client_interface_state_t::MENU
#define CLIENT_INTERFACE_CREATE_STATE client_interface_state_t::CREATE
#define CLIENT_INTERFACE_LIST_STATE client_interface_state_t::LIST
#define CLIENT_INTERFACE_UPDATE_STATE client_interface_state_t::UPDATE
#define CLIENT_INTERFACE_DELETE_STATE client_interface_state_t::DELETE

#define PRINT_CLIENT_INTERFACE_MENU \
	PRINTLN(" CLIENT MANAGEMENT"); \
	PRINT("\n"); \
	PRINTLN(" 1. List all"); \
	PRINTLN(" 2. Create"); \
	PRINTLN(" 3. Update"); \
	PRINTLN(" 4. Delete"); \
	PRINTLN(" 5. Go back");

inline client_t* get_client_by_id (client_collection_t& client_collection)
{
	unsigned int id;
	PRINT("\n Client ID: ");
	GET_INPUT(id);
	client_t* client = client_collection.get_client_by_id(id);

	if (client == nullptr) {
		CLEAR_CONSOLE;
		PRINTLN(" Client not found!\n");
		return nullptr;
	} 
	
	PRINTLN("\n " + client->get_name());
	PRINTLN(" " + client->get_email());
	PRINTLN(" " + client->get_phone_number());

	return client;
}

namespace client_interface 
{
	void create (client_collection_t& client_collection);
	void update (client_collection_t& client_collection);
	void remove (client_collection_t& client_collection);
	void list (client_collection_t& client_collection);
}

#endif
