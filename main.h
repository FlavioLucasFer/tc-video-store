#include <iostream>
#include <list>
#include "lib.h"
#include "client.h"
#include "video_collection.h"
#include "client_collection.h"

using choice_t = uint_t;

enum class state_t
{
	main_menu,
	client_menu,
	video_menu,
	see_billing,
	close,
	panic,

#define MAIN_MENU_STATE state_t::main_menu
#define CLIENT_MENU_STATE state_t::client_menu
#define VIDEO_MENU_STATE state_t::video_menu
#define SEE_BILLING state_t::see_billing
#define CLOSE_STATE state_t::close
#define PANIC_STATE state_t::panic
};


enum class client_interface_state_t
{
	menu,
	create,
	list,
	update,
	remove,

#define CLIENT_INTERFACE_MENU_STATE client_interface_state_t::menu
#define CLIENT_INTERFACE_CREATE_STATE client_interface_state_t::create
#define CLIENT_INTERFACE_LIST_STATE client_interface_state_t::list
#define CLIENT_INTERFACE_UPDATE_STATE client_interface_state_t::update
#define CLIENT_INTERFACE_DELETE_STATE client_interface_state_t::remove
};

enum class video_interface_state_t
{
	menu,
	create,
	update,
	remove,
	list,
	list_avaliable,
	list_rented,
	rent,
	return_video,

#define VIDEO_INTERFACE_MENU_STATE video_interface_state_t::menu
#define VIDEO_INTERFACE_CREATE_STATE video_interface_state_t::create
#define VIDEO_INTERFACE_LIST_STATE video_interface_state_t::list
#define VIDEO_INTERFACE_LIST_AVALIABLE_STATE video_interface_state_t::list_avaliable
#define VIDEO_INTERFACE_LIST_RENTED_STATE video_interface_state_t::list_rented
#define VIDEO_INTERFACE_UPDATE_STATE video_interface_state_t::update
#define VIDEO_INTERFACE_DELETE_STATE video_interface_state_t::remove
#define VIDEO_INTERFACE_RENT_STATE video_interface_state_t::rent
#define VIDEO_INTERFACE_RETURN_STATE video_interface_state_t::return_video
};

namespace client_interface
{
	client_t* get_client_by_id ();
	void menu ();
	void create ();
	void update ();
	void remove ();
	void list ();
}

namespace video_interface
{
	video_t* get_video_by_id ();
	void menu ();
	void create (); 
	void update ();
	void remove ();
	void list ();
	void list_avaliable ();
	void list_rented ();
	void rent ();
	void return_video ();
}
