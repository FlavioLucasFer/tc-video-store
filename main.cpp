#include <iostream>
#include "client.h"
#include "collection.h"

int main () 
{
	collection_t collection;
	video_t video = video_t("Unce upon a time... in hollywood.", 20);
	video_t video2 = video_t("Harry Potter", 25.50);
	
	collection.add_video(video);
	collection.add_video(video2);
	
	// collection.remove_video(video.get_id());
	
	// video_t f = collection.find_video_by_id(1);
	
	collection.rent_video(video2.get_id());
	
	collection.print();
	
	std::cout << std::endl;
	
	collection.return_video(video2.get_id());
	
	collection.print();

	return 0;
}

