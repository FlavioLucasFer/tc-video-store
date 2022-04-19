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
	
	video_t f = collection.find_video_by_id(1);

	return 0;
}

