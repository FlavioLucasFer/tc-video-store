#include "lib.h"

class client_t
{
	public:
		inline client_t (std::string name, std::string email, std::string phone_number)
		{
			this->name = name;
			this->email = email;
			this->phone_number = phone_number;
		}
		
		inline std::string to_string ()
		{
			return this->name + " - " + this->email + " - " + this->phone_number;
		}
		
	GETTER_SETTER_ENCAP(std::string, name);
	GETTER_SETTER_ENCAP(std::string, email);
	GETTER_SETTER_ENCAP(std::string, phone_number);
};

