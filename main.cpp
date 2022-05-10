#include "main.h"

bool executing = true;

state_t state = MAIN_MENU_STATE;
client_interface_state_t client_interface_state = CLIENT_INTERFACE_MENU_STATE;
video_interface_state_t video_interface_state = VIDEO_INTERFACE_MENU_STATE;

video_collection_t video_collection;
client_collection_t client_collection;

choice_t get_menu_choice (uint_t max_value)
{
	choice_t choice;
	
	while (true) {
		lib::lnbr_input<choice_t>("\n Choice: ", choice);

		if (choice > 0 && choice <= max_value)
			return choice;  

		PRINTLN(" Invalid option. Please, type a valid option!");
	}
}

void main_menu ()
{
	PRINTLN(" WELCOME TO VIDEO STORE \n");
	PRINTLN(" 1. Client Management");
	PRINTLN(" 2. Collection Management");
	PRINTLN(" 3. See billing");
	PRINTLN(" 4. Close");

	choice_t choice = get_menu_choice(4);

	switch (choice) {
		case 1:
			state = CLIENT_MENU_STATE;
			break;
		case 2:
			state = VIDEO_MENU_STATE;
			break;
		case 3:
			state = SEE_BILLING;
			break;
		case 4:
			state = CLOSE_STATE;
			break;
		default:
			state = PANIC_STATE;
			break;
	}
}

namespace client_interface 
{
	void menu ()
	{
		PRINTLN(" CLIENT MANAGEMENT\n");
		PRINTLN(" 1. List all");
		PRINTLN(" 2. Create");
		PRINTLN(" 3. Update");
		PRINTLN(" 4. Delete");
		PRINTLN(" 5. Go back");
	}

	client_t* get_client_by_id ()
	{
		uint_t id;
		lib::lnbr_input<uint_t>("\n Client ID: ", id);
		client_t *client = client_collection.get_client_by_id(id);

		if (client == nullptr)
		{
			CLEAR_CONSOLE;
			PRINTLN(" Client not found!\n");
			return nullptr;
		}

		std::cout << "\n " << client->get_name() << std::endl;
		std::cout << " " << client->get_email() << std::endl;
		std::cout << " " << client->get_phone_number() << std::endl;
		return client;
	}

	void create ()
	{
		std::string name;
		std::string email;
		std::string phone_number;

		lib::lstr_input<std::string>("\n Name: ", name);
		lib::lstr_input<std::string>(" E-mail: ", email);
		lib::lstr_input<std::string>(" Phone number: ", phone_number);

		client_collection << client_t(name, email, phone_number);
		CLEAR_CONSOLE;
		PRINTLN(" Client successfully created!\n");
	}

	void update ()
	{
		client_t *client = get_client_by_id();

		if (client == nullptr)
			return;

		std::string name;
		std::string email;
		std::string phone_number;

		std::cin.ignore();
		lib::lstr_input<std::string>("\n New name (TYPE '!k' ENTER TO !k CURRENT): ", name);
		lib::lstr_input<std::string>(" New e-mail (TYPE '!k' TO !k CURRENT): ", email);
		lib::lstr_input<std::string>(" New phone number (TYPE '!k' TO !k CURRENT): ", phone_number);

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

	void remove ()
	{
		client_t *client = get_client_by_id();

		if (client == nullptr)
			return;

		std::string choice;
		lib::lstr_input<std::string>("\n Are you sure you want to delete this client? Y/n ", choice);
		CLEAR_CONSOLE;

		if (choice != "Y" && choice != "y")
			return;

		client_collection.remove(client->get_id());
		PRINTLN(" Client successfully deleted! \n");
	}

	void list ()
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Clients:\n");
		client_collection.list();
		PRINT("\n");
	}
}

void client_menu ()
{
	client_interface::menu();

	choice_t choice = get_menu_choice(5);

	switch (choice) {
		case 1:
			client_interface_state = CLIENT_INTERFACE_LIST_STATE;
			break;
		case 2:
			client_interface_state = CLIENT_INTERFACE_CREATE_STATE;
			break;
		case 3:
			client_interface_state = CLIENT_INTERFACE_UPDATE_STATE;
			break;
		case 4:
			client_interface_state = CLIENT_INTERFACE_DELETE_STATE;
			break;
		case 5:
			client_interface_state = CLIENT_INTERFACE_MENU_STATE;
			state = MAIN_MENU_STATE;
			CLEAR_CONSOLE;
			break;
		default: // panic
			client_interface_state = CLIENT_INTERFACE_MENU_STATE;
			state = PANIC_STATE;
			CLEAR_CONSOLE;
			break;
	}
}

void client_i ()
{
	do {
		switch (client_interface_state) {
			case CLIENT_INTERFACE_MENU_STATE:
				client_menu();
				break;
			case CLIENT_INTERFACE_CREATE_STATE:
				client_interface::create();
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_LIST_STATE:
				client_interface::list();
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_UPDATE_STATE:
				client_interface::update();
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_DELETE_STATE:
				client_interface::remove();
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			default: // go back
				CLEAR_CONSOLE;
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				state = MAIN_MENU_STATE;
				break;
		}
	} while (state == CLIENT_MENU_STATE);
}

namespace video_interface
{
	void menu ()
	{
		PRINTLN(" COLLECTION MANAGEMENT \n");
		PRINTLN(" 1. List all");
		PRINTLN(" 2. List avaliable only");
		PRINTLN(" 3. List rented only");
		PRINTLN(" 4. Create");
		PRINTLN(" 5. Update");
		PRINTLN(" 6. Delete");
		PRINTLN(" 7. Rent");
		PRINTLN(" 8. Return");
		PRINTLN(" 9. Go back");
	}

	video_t* get_video_by_id ()
	{
		uint_t id;
		lib::lnbr_input<uint_t>("\n Video ID: ", id);

		video_t *video = video_collection.get_video_by_id(id);

		if (video == nullptr) {
			CLEAR_CONSOLE;
			PRINTLN(" Video not found!\n");
			return nullptr;
		}

		std::cout << "\n " << video->get_name() << std::endl;
		std::cout << " $" << video->get_price() << std::endl;
		std::cout << " " << video->get_director() << std::endl;
		std::cout << " " << video->get_cast() << std::endl;
		std::cout << " " << video->get_duration() << std::endl;
		std::cout << " " << video->get_category() << std::endl;

		return video;
	}

	void create ()
	{
		std::string name;
		double price;
		std::string director;
		std::string cast;
		std::string duration;
		std::string category;

		lib::lstr_input<std::string>("\n Name: ", name);
		lib::lnbr_input<double>(" Price: ", price);
		lib::lstr_input<std::string>(" Director: ", director);
		lib::lstr_input<std::string>(" Cast: ", cast);
		lib::lstr_input<std::string>(" Duration: ", duration);
		lib::lstr_input<std::string>(" Category: ", category);

		CLEAR_CONSOLE;
		video_collection << video_t(name, price, director, cast, duration, category);
		PRINTLN(" Video successfully created!\n");
	}

	void update ()
	{
		video_t* video = get_video_by_id();

		if (video == nullptr)
			return;

		std::string name;
		std::string price;
		std::string director;
		std::string cast;
		std::string duration;
		std::string category;

		lib::lstr_input<std::string>("\n New name (TYPE '!k' ENTER TO !k CURRENT): ", name);
		lib::lstr_input<std::string>(" New price (TYPE '!k' TO !k CURRENT): $", price);
		lib::lstr_input<std::string>(" New director (TYPE '!k' TO !k CURRENT): ", director);
		lib::lstr_input<std::string>(" New cast (TYPE '!k' TO !k CURRENT): ", cast);
		lib::lstr_input<std::string>(" New duration (TYPE '!k' TO !k CURRENT): ", duration);
		lib::lstr_input<std::string>(" New category (TYPE '!k' TO !k CURRENT): ", category);

		if (name == "!k")
			name = video->get_name();
		if (price == "!k")
			price = std::to_string(video->get_price());
		if (director == "!k")
			director = video->get_director();
		if (cast == "!k")
			cast = video->get_cast();
		if (duration == "!k")
			duration = video->get_duration();
		if (category == "!k")
			category = video->get_category();

		CLEAR_CONSOLE;
		video_collection.update(video->get_id(), name, std::stod(price.c_str()), director, cast, duration, category);
		PRINTLN(" Video successfully updated!\n");
	}

	void remove ()
	{
		video_t* video = get_video_by_id();

		if (video == nullptr)
			return;
		
		std::string choice;
		lib::lstr_input<std::string>("\n Are you sure you want to delete this video? Y/n ", choice);
		CLEAR_CONSOLE;

		if (choice != "Y" && choice != "y") 
			return;

		video_collection.remove(video->get_id());
		PRINTLN(" Video successfully deleted! \n");
	}

	void list ()
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Videos:\n");
		video_collection.list();
		PRINT("\n");
	}

	void list_avaliable ()
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Avaliable videos:\n");
		video_collection.list_avaliable();
		PRINT("\n");
	}

	void list_rented ()
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Rented videos:\n");
		video_collection.list_rented();
		PRINT("\n");
	}

	void rent ()
	{
		CLEAR_CONSOLE;
		video_t* video = get_video_by_id();
		client_t* client = client_interface::get_client_by_id();

		if (client == nullptr) {
			PRINTLN(" Client not found!\n");
			return;
		} 

		if (!video_collection.rent(video->get_id(), *client)) {
			PRINTLN(" Video not found or already rented!");
			return;
		}

		PRINTLN("\n Video successfully rented!\n"); 
	}

	void return_video ()
	{
		video_t* video = get_video_by_id();
		CLEAR_CONSOLE;
		
		if (video_collection.return_video(video->get_id()))
			PRINTLN(" Video successfully returned!");
		else
			PRINTLN(" Video not found or not even rented yet!");
	}
}

void video_menu ()
{
	video_interface::menu();

	choice_t choice = get_menu_choice(9);

	switch (choice) {
		case 1:
			video_interface_state = VIDEO_INTERFACE_LIST_STATE;
			break;
		case 2:
			video_interface_state = VIDEO_INTERFACE_LIST_AVALIABLE_STATE;
			break;
		case 3:
			video_interface_state = VIDEO_INTERFACE_LIST_RENTED_STATE;
			break;
		case 4:
			video_interface_state = VIDEO_INTERFACE_CREATE_STATE;
			break;
		case 5:
			video_interface_state = VIDEO_INTERFACE_UPDATE_STATE;
			break;
		case 6:
			video_interface_state = VIDEO_INTERFACE_DELETE_STATE;
			break;
		case 7:
			video_interface_state = VIDEO_INTERFACE_RENT_STATE;
			break;
		case 8:
			video_interface_state = VIDEO_INTERFACE_RETURN_STATE;
			break;
		case 9:
			video_interface_state = VIDEO_INTERFACE_MENU_STATE;
			state = MAIN_MENU_STATE;
			CLEAR_CONSOLE;
			break;
		default: // panic
			video_interface_state = VIDEO_INTERFACE_MENU_STATE;
			state = PANIC_STATE;
			CLEAR_CONSOLE;
			break;
	}
}

void video_i ()
{
	do {
		switch (video_interface_state) {
			case VIDEO_INTERFACE_MENU_STATE:
				video_menu();
				break;
			case VIDEO_INTERFACE_LIST_STATE:
				video_interface::list();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_LIST_AVALIABLE_STATE:
				video_interface::list_avaliable();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_LIST_RENTED_STATE:
				video_interface::list_rented();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_CREATE_STATE:
				video_interface::create();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_UPDATE_STATE:
				video_interface::update();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_DELETE_STATE:
				video_interface::remove();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_RENT_STATE:
				video_interface::rent();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_RETURN_STATE:
				video_interface::return_video();
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			default: // go back
				CLEAR_CONSOLE;
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				state = MAIN_MENU_STATE;
				break;
		}
	} while (state == VIDEO_MENU_STATE);
}

int main () 
{
	do {
		switch (state) {
			case MAIN_MENU_STATE:
				main_menu();	
				break;
			case CLIENT_MENU_STATE:
				CLEAR_CONSOLE;
				client_i();
				break;
			case VIDEO_MENU_STATE:
				CLEAR_CONSOLE;
				video_i();
				break;
			case SEE_BILLING:
				CLEAR_CONSOLE;
				std::cout << " Billing: $" << video_collection.get_billing() << "\n" << std::endl;
				state = MAIN_MENU_STATE;
				break;
			case CLOSE_STATE:
				CLEAR_CONSOLE;
				executing = false;
				break;
			default: // panic state
				CLEAR_CONSOLE;
				PRINT("PANIC: An unexpected error has occurred!");
				executing = false;
				break;
		}
	} while (executing);

	return 0;
}
