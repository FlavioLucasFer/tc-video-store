#include "client_collection.h"

client_t* client_collection_t::get_client_by_id (uint_t id)
{
	client_t *client = nullptr;

	lib::for_each<client_t>(this->clients, [&](client_t& c) {
		if (c.get_id() == id) 
			client = &c;
	}, client != nullptr);

	return client;
}

void client_collection_t::add (client_t client)
{
	this->clients.push_back(client);
}

void client_collection_t::update (uint16_t id, std::string name, std::string email, std::string phone_number)
{
	client_t *client = this->get_client_by_id(id);

	if (client == nullptr)
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
	lib::for_each<client_t>(this->clients, [](client_t& client) {
		std::cout << " " << client.to_string() << std::endl;
	});
}
