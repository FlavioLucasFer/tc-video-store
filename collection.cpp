#include "collection.h"

video_t* collection_t::find_video_by_id (uint16_t id)
{	
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		if (video.get_id() == id)
			return &video;
	}
	
	return nullptr;
}

void collection_t::add_video (video_t video)
{
	this->videos.push_back(video);
}

void collection_t::remove_video (uint16_t id)
{
	this->videos.remove_if([id] (video_t& video) {
		return video.get_id() == id;
	});
}

bool collection_t::rent_video (uint16_t id)
{
	video_t *video = this->find_video_by_id(id);
	
	if (video == nullptr || !video->get_avaliable())
		return false;
		
	video->set_avaliable(false);
	
	return true;
}


bool collection_t::return_video (uint16_t id)
{
	video_t *video = this->find_video_by_id(id);
	
	if (video == nullptr || video->get_avaliable())
		return false;
		
	video->set_avaliable(true);
	
	return true;	
}

void collection_t::print ()
{
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		std::cout << video.to_string() << std::endl;
	}
}

