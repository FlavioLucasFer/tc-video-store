#include "video_collection.h"

video_t* video_collection_t::get_video_by_id (uint16_t id)
{	
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		if (video.get_id() == id)
			return &video;
	}
	
	return nullptr;
}

void video_collection_t::add (video_t video)
{
	this->videos.push_back(video);
}

void video_collection_t::remove (uint16_t id)
{
	this->videos.remove_if([id] (video_t& video) {
		return video.get_id() == id;
	});
}

void video_collection_t::update (uint16_t id, std::string name, double price, std::string director, std::string cast, std::string duration, std::string category)
{
	video_t *video = this->get_video_by_id(id);

	if (video == nullptr)
		return;

	video->set_name(name);
	video->set_price(price);
	video->set_director(director);
	video->set_cast(cast);
	video->set_duration(duration);
	video->set_category(category);
}

bool video_collection_t::rent (uint16_t id, client_t& client)
{
	video_t *video = this->get_video_by_id(id);
	
	if (video == nullptr || !video->is_avaliable())
		return false;
		
	video->set_client(&client);
	
	return true;
}


bool video_collection_t::return_video (uint16_t id)
{
	video_t *video = this->get_video_by_id(id);
	
	if (video == nullptr || video->is_avaliable())
		return false;
		
	video->set_client(nullptr);
	this->billing += video->get_price();
	
	return true;	
}

void video_collection_t::list ()
{
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		PRINTLN(" " + video.to_string() + (video.is_avaliable() ? "(AVALIABLE)" : "(RENTED)"));
	}
}

void video_collection_t::list_rented ()
{
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		if (!video.is_avaliable())
			PRINTLN(" " + video.to_string() + " [" + video.get_client()->to_string() + "]");
	}
}

void video_collection_t::list_avaliable ()
{
	for (auto it = this->videos.begin(); it != this->videos.end(); it++) {
		video_t& video = *it;
		
		if (video.is_avaliable())
			PRINTLN(" " + video.to_string());
	}
}
