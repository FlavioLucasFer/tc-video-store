#include "client_interface.h"

namespace client_interface
{
	void create (client_collection_t& client_collection)
	{
		std::string name;
		std::string email;
		std::string phone_number;

		PRINT("\n Name: ");
		GET_INPUT(name);
		PRINT(" E-mail: ");
		GET_INPUT(email);
		PRINT(" Phone number: ");
		GET_INPUT(phone_number);

		client_collection << client_t(name, email, phone_number);
		CLEAR_CONSOLE;
		PRINTLN(" Client successfully created!\n");
	}

	void update (client_collection_t& client_collection)
	{
		client_t* client = get_client_by_id(client_collection);

		if (client == nullptr)
			return;

		std::string name;
		std::string email;
		std::string phone_number;

		PRINT("\n New name (TYPE '!k' ENTER TO KEEP CURRENT): ");
		GET_INPUT(name);
		PRINT(" New e-mail (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(email);
		PRINT(" New phone number (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(phone_number);

		if (name == "!k")
			name = client->get_name();
		if (email == "!k")
			email = client->get_email();
		if (phone_number == "!k")
			phone_number = client->get_phone_number();

		client_collection.update(client->get_id(), name, email, phone_number);

		CLEAR_CONSOLE;
		PRINTLN(" Client successfully updated!\n");
	}

	void remove (client_collection_t& client_collection)
	{
		client_t* client = get_client_by_id(client_collection);

		if (client == nullptr)
			return;
		
		std::string choice;
		PRINT("\n Are you sure you want to delete this client? Y/n ");
		GET_INPUT(choice);
		CLEAR_CONSOLE;

		if (choice != "Y" && choice != "y") 
			return;

		client_collection.remove(client->get_id());
		PRINTLN(" Client successfully deleted! \n");
		
	}

	void list (client_collection_t& client_collection)
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Clients:\n");
		client_collection.list();
		PRINT("\n");
	}
} 
