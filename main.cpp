#include "main.h"

bool executing = true;

state_t state = MAIN_MENU_STATE;
client_interface_state_t client_interface_state = CLIENT_INTERFACE_MENU_STATE;
video_interface_state_t video_interface_state = VIDEO_INTERFACE_MENU_STATE;

video_collection_t video_collection;
client_collection_t client_collection;

inline void main_menu ()
{
	unsigned int choice;
	PRINT_MAIN_MENU;
	GET_MENU_ENTRY(choice, 4);

	switch (choice)
	{
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

inline void client_menu ()
{
	unsigned int choice;
	PRINT_CLIENT_INTERFACE_MENU;
	GET_MENU_ENTRY(choice, 5);

	switch (choice)
	{
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
			break;
		default: // panic
			client_interface_state = CLIENT_INTERFACE_MENU_STATE;
			state = PANIC_STATE;
			break;
	}
}

inline void video_menu ()
{
	unsigned int choice;
	PRINT_VIDEO_INTERFACE_MENU;
	GET_MENU_ENTRY(choice, 9);

	switch (choice)
	{
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
			break;
		default: // panic
			video_interface_state = VIDEO_INTERFACE_MENU_STATE;
			state = PANIC_STATE;
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
				client_interface::create(client_collection);
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_LIST_STATE:
				client_interface::list(client_collection);
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_UPDATE_STATE:
				client_interface::update(client_collection);
				client_interface_state = CLIENT_INTERFACE_MENU_STATE;
				break;
			case CLIENT_INTERFACE_DELETE_STATE:
				client_interface::remove(client_collection);
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

void video_i ()
{
	do {
		switch (video_interface_state) {
			case VIDEO_INTERFACE_MENU_STATE:
				video_menu();
				break;
			case VIDEO_INTERFACE_LIST_STATE:
				video_interface::list(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_LIST_AVALIABLE_STATE:
				video_interface::list_avaliable(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_LIST_RENTED_STATE:
				video_interface::list_rented(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_CREATE_STATE:
				video_interface::create(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_UPDATE_STATE:
				video_interface::update(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_DELETE_STATE:
				video_interface::remove(video_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_RENT_STATE:
				video_interface::rent(video_collection, client_collection);
				video_interface_state = VIDEO_INTERFACE_MENU_STATE;
				break;
			case VIDEO_INTERFACE_RETURN_STATE:
				video_interface::return_video(video_collection);
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
				PRINT(" Billing: $");
				PRINTLN(video_collection.get_billing());
				PRINT("\n");
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
