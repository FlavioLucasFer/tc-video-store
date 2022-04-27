#include <iostream>
#include "client.h"
#include "collection.h"

int main () 
{
	collection_t collection;
	
	video_t video("Unce upon a time... in hollywood.", 20);
	video_t video2("Harry Potter", 25.50);
	
	collection.add_video(video);
	collection.add_video(video2);

	client_t client("Matador de Porco", "matador@porco.com", "44999999");
	
	bool is_rent = collection.rent_video(video2.get_id(), client);
	
	client_t* client_ptr = collection.get_video_by_id(video2.get_id())->get_client();
	
	std::cout << client_ptr->get_email_ref() << std::endl;
	
	//collection.print();
	
	std::cout << std::endl;
	
	collection.return_video(video2.get_id());
	
	//collection.print();

	return 0;
}

