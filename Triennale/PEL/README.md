> 	Parser per file json

> 6 tipi in input:
> - null
> - double
> - bool
> - string
> - list
> - dictionary

> json.hpp da https://github.com/nicolaprezza/progetto_PEL_22_23 da usare come file header. Laureate ottimo json per testing.

> Problemi nel progetto:
> - prendere in input
> - trasformare nel tipo corrispondente
> - gestire eccezioni

>⚠ importante riguardare la calcolatrice dal moodle di PEL.
>json.hpp 
```cpp
#include <iostream>
#include <string>
#include <limits>

struct json_exception {
	std::string msg;
};

class json {

public:
	
	struct list_iterator;
	struct dictionary_iterator;
	struct const_list_iterator;
	struct const_dictionary_iterator;
	
	json();
	json(json const&);
	json(json&&);
	~json();
	
	json& operator=(json const&);
	json& operator=(json&&);

	bool is_list() const;
	bool is_dictionary() const;
	bool is_string() const;
	bool is_number() const;
	bool is_bool() const;
	bool is_null() const;

	json const& operator[](std::string const&) const;
	json& operator[](std::string const&);

	list_iterator begin_list();
	const_list_iterator begin_list() const;
	list_iterator end_list();
	const_list_iterator end_list() const;

	dictionary_iterator begin_dictionary();
	const_dictionary_iterator begin_dictionary() const;
	dictionary_iterator end_dictionary();
	const_dictionary_iterator end_dictionary() const;

	double& get_number();
	double const& get_number() const;

	bool& get_bool();
	bool const& get_bool() const;

	std::string& get_string();
	std::string const& get_string() const;

	void set_string(std::string const&);
	void set_bool(bool);
	void set_number(double);
	void set_null();
	void set_list();
	void set_dictionary();
	void push_front(json const&);
	void push_back(json const&);
	void insert(std::pair<std::string,json> const&);

private:
		
	struct impl;
	impl* pimpl;
	
};

std::ostream& operator<<(std::ostream& lhs, json const& rhs);
std::istream& operator>>(std::istream& lhs, json& rhs);
```

> Da usare come base calculator da https://moodle.unive.it/course/view.php?id=13454

>Immaginiamo:
>```cpp
>json j;
> {
>   "prima stringa" : [1,2,3],
>   "seconda stringa" : 6 
> }
>
>j["prima stringa"] // return reference of an object contain [1,2,3] (list)
>j["seconda stringa"] // return reference of an object contain 6 (number)
>j["terza stringa"] // return the key-value ("terza stringa", null)
>```
>```cpp
>json j2;
> //inserisco in j2 [1,2,[1,2,3]]
>
>auto it = j2.begin();
>*it; // return firsts json value
>*(++it) // return second json value
>```
