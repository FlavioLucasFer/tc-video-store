#include "lib.h"

uint16_t generate_video_id ();

class video_t
{
	GETTER_ENCAP(uint16_t, id);
	GETTER_SETTER_ENCAP(std::string, name);
	GETTER_SETTER_ENCAP(std::string, director);
	GETTER_SETTER_ENCAP(std::string, cast);
	GETTER_SETTER_ENCAP(std::string, duration);
	GETTER_SETTER_ENCAP(std::string, category);
	GETTER_SETTER_ENCAP(double, price);
	GETTER_SETTER_ENCAP(bool, avaliable);

	public:
		inline video_t (
			std::string name, 
			double price,
			std::string director = "", 
			std::string cast = "", 
			std::string duration = "", 
			std::string category = ""
		)
		{
			this->id = generate_video_id();
			this->name = name;
			this->director = director;
			this->cast = cast;
			this->duration = duration;
			this->category = category;
			this->price = price;
			this->avaliable = true;
		}
		
		std::string to_string ();
};

