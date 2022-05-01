#include "client_collection.h"

client_t* client_collection_t::get_client_by_id (uint16_t id)
{
	for (auto it = this->clients.begin(); it != this->clients.end(); it++) {
		client_t& client = *it;

		if (client.get_id() == id)
			return &client;
	}

	return nullptr;
}

void client_collection_t::add (client_t client)
{
	this->clients.push_back(client);
}

void client_collection_t::update (uint16_t id, std::string name, std::string email, std::string phone_number)
{
	client_t *client = this->get_client_by_id(id);

	if (!client)
		return;

	client->set_name(name);
	client->set_email(email);
	client->set_phone_number(phone_number);
}

void client_collection_t::remove (uint16_t id)
{
	this->clients.remove_if([id] (client_t& client) {
		return client.get_id() == id;
	});
}

void client_collection_t::list ()
{
	for (auto it = this->clients.begin(); it != this->clients.end(); it++) {
		client_t& client = *it;

		PRINTLN(" " + client.to_string());
	}
}
