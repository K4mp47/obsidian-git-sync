#include "json.hpp"

// define type of the json struct
enum Type {
    Boolean, Number, Null, Dict, List, String
};

struct json::impl {
    bool b_value = false;

    double d_value = 0.0;

    std::string s_value;

    struct list {
        json info;
        list *next;

        ~list() { delete next; }
    };

    list *list_head = nullptr;
    list *list_tail = nullptr;

    struct dict {
        std::pair<std::string, json> info;
        dict *next;

        ~dict() { delete next; }
    };

    dict *dict_head = nullptr;
    dict *dict_tail = nullptr;

    Type type = Type::Null;

    void clear() {
        if(type == Type::List) {
            delete list_head;
            list_head = nullptr;
            list_tail = nullptr;
        } else if (type == Type::Dict) {
            delete dict_head;
            dict_head = nullptr;
            dict_tail = nullptr;
        }
        type = Type::Null;
    }

    ~impl() {
        clear();
    }

    impl() = default;

    impl(const impl& pimpl) {
        if(pimpl.type == Type::List) {
            if(pimpl.list_head != nullptr) {
                list_head = new list(*pimpl.list_head);
                list_tail = list_head;
                list *other_curr = pimpl.list_head;
                list *curr = list_head;
                while (other_curr->next) {
                    curr->next = new list{*other_curr->next};
                    curr = curr->next;
                    list_tail = curr;
                    other_curr = other_curr->next;
                }
            } else {
                list_head = list_tail = nullptr;
            }
            type = Type::List;

        } else if(pimpl.type == Type::Dict) {
            if(pimpl.dict_head != nullptr){
                dict_head = new dict(*pimpl.dict_head);
                dict_tail = dict_head;
                dict *other_curr = pimpl.dict_head;
                dict *curr = dict_head;
                while (other_curr->next) {
                    curr->next = new dict(*other_curr->next);
                    curr = curr->next;
                    dict_tail = curr;
                    other_curr = other_curr->next;
                }
            } else {
                dict_head = dict_tail = nullptr;
            }
            type = Type::Dict;

        } else if(pimpl.type == Type::Boolean) {
            b_value = pimpl.b_value;
            type = Type::Boolean;

        } else if(pimpl.type == Type::Number) {
            d_value = pimpl.d_value;
            type = Type::Number;

        } else if(pimpl.type == Type::String) {
            s_value = pimpl.s_value;
            type = Type::String;

        } else {
            type = Type::Null;
        }
    }
};

// constructor
json::json() : pimpl(new impl) {}

json::json(json const &other) : pimpl(new impl(*other.pimpl)) {}

json::json(json &&other) : pimpl() {
    *this = std::move(other);
}

json &json::operator=(json const &other) {
    if(other.pimpl != nullptr) {

        if (this == &other) {
            return *this;
        }

        if (pimpl != nullptr) {
            delete pimpl;
            pimpl = nullptr;
        }

        pimpl = new impl(*other.pimpl);
    }

    return *this;
}

json &json::operator=(json &&other) {
    if (this == &other) {
        return *this;
    }

    delete pimpl;

    pimpl = other.pimpl;
    other.pimpl = nullptr;
    return *this;
}

json const &json::operator[](std::string const &other) const {
    if (!is_dictionary()) throw json_exception{"Json isn't a type dict! operator[]"};

    for (json::impl::dict *curr = pimpl->dict_head; curr != nullptr; curr = curr->next) {
        if (curr->info.first == other) {
            return curr->info.second;
        }
    }

    throw json_exception{.msg = "Key not found! operator[]"};
}


json &json::operator[](std::string const &other) {
    if (!is_dictionary()) throw json_exception{.msg = "Json isn't a type dict! operator[]"};

    for (json::impl::dict *curr = pimpl->dict_head; curr != nullptr; curr = curr->next) {
        if (curr->info.first == other) {
            return curr->info.second;
        }
    }

    json new_json;

    insert(std::make_pair(other, new_json));
    return pimpl->dict_tail->info.second;
}

// destructor
json::~json() {
    delete pimpl;
}

// list control

bool json::is_list() const {
    return pimpl->type == Type::List;
}

void json::set_list() {
    pimpl->clear();
    pimpl->type = Type::List;
}

void json::push_front(json const &x) {
    if (!is_list()) throw json_exception{"Json is not a list! push_front()"};

    if (pimpl->list_head == nullptr) {
        pimpl->list_head = new json::impl::list{x, nullptr};
        pimpl->list_tail = pimpl->list_head;
    } else {
        pimpl->list_head = new json::impl::list{x, pimpl->list_head};
    }
}

void json::push_back(json const &x) {
    if (!is_list()) throw json_exception{"Json is not a list! push_back()"};

    if (pimpl->list_head == nullptr) {
        pimpl->list_head = new json::impl::list{x, nullptr};
        pimpl->list_tail = pimpl->list_head;
    } else {
        pimpl->list_tail->next = new json::impl::list{x, nullptr};
        pimpl->list_tail = pimpl->list_tail->next;
    }
}

struct json::list_iterator {
    json::impl::list *current;

    explicit list_iterator(json::impl::list *ptr) : current(ptr) {}

    json &operator*() const {
        return current->info;
    }

    list_iterator &operator++() {
        current = current->next;
        return *this;
    }

    list_iterator operator++(int) {
        list_iterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const list_iterator &other) const {
        return current == other.current;
    }

    bool operator!=(const list_iterator &other) const {
        return !(*this == other);
    }

    json *operator->() const {
        return &current->info;
    }
};

struct json::const_list_iterator {
    json::impl::list *current;

    const_list_iterator(json::impl::list *ptr) : current(ptr) {}

    json &operator*() const {
        return current->info;
    }

    const_list_iterator &operator++() {
        current = current->next;
        return *this;
    }

    const_list_iterator operator++(int) {
        const_list_iterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const const_list_iterator &other) const {
        return current == other.current;
    }

    bool operator!=(const const_list_iterator &other) const {
        return !(*this == other);
    }

    json *operator->() const {
        return &current->info;
    }
};

json::list_iterator json::begin_list() {
    if (is_list()) {
        return list_iterator(pimpl->list_head);
    }

    throw json_exception{.msg = "Json isn't a list! begin_list"};
}

json::list_iterator json::end_list() {
    if (is_list()) {
        return list_iterator(nullptr);
    }

    throw json_exception{.msg = "Json isn't a list! end_list"};
}

json::const_list_iterator json::begin_list() const {
    if (is_list()) {
        return const_list_iterator{pimpl->list_head};
    }
    throw json_exception{.msg = "Json isn't a list! begin_list const"};
}

json::const_list_iterator json::end_list() const {
    if (is_list()) {
        return const_list_iterator(pimpl->list_tail);
    }
    throw json_exception{.msg = "json isn't a list! end_list const"};
}

// dictionary control

bool json::is_dictionary() const {
    return pimpl->type == Type::Dict;
}

void json::set_dictionary() {
    //new(this) json();
    pimpl->clear();
    pimpl->type = Type::Dict;
}

void json::insert(std::pair<std::string, json> const &elem) {
    if (pimpl->dict_head == nullptr) {
        pimpl->dict_head = new json::impl::dict{elem, nullptr};
        pimpl->dict_tail = pimpl->dict_head;
    } else {
        pimpl->dict_tail->next = new json::impl::dict{elem, nullptr};
        pimpl->dict_tail = pimpl->dict_tail->next;
    }
}

struct json::dictionary_iterator {
    json::impl::dict *current;

    dictionary_iterator(json::impl::dict *ptr) : current(ptr) {}

    std::pair<std::string, json> &operator*() const {
        return current->info;
    }

    dictionary_iterator &operator++() {
        current = current->next;
        return *this;
    }

    dictionary_iterator operator++(int) {
        dictionary_iterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const dictionary_iterator &other) const {
        return current == other.current;
    }

    bool operator!=(const dictionary_iterator &other) const {
        return !(*this == other);
    }

    std::pair<std::string, json> *operator->() const {
        return &current->info;
    }

};

struct json::const_dictionary_iterator {
    json::impl::dict *current;

    const_dictionary_iterator(json::impl::dict *ptr) : current(ptr) {}

    std::pair<std::string, json> &operator*() const {
        return current->info;
    }

    const_dictionary_iterator &operator++() {
        current = current->next;
        return *this;
    }

    const_dictionary_iterator operator++(int) {
        const_dictionary_iterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const const_dictionary_iterator &other) const {
        return current == other.current;
    }

    bool operator!=(const const_dictionary_iterator &other) const {
        return !(*this == other);
    }

    std::pair<std::string, json> *operator->() const {
        return &current->info;
    }
};

json::const_dictionary_iterator json::begin_dictionary() const {
    if (is_dictionary()) {
        return const_dictionary_iterator(pimpl->dict_head);
    }
    throw json_exception{.msg = "Json isn't a dict! begin_dictionary const"};
}


json::const_dictionary_iterator json::end_dictionary() const {
    if (is_dictionary()) {
        return const_dictionary_iterator(pimpl->dict_tail);
    }
    throw json_exception{.msg = "Json isn't a dict! end_dictionary const"};
}

json::dictionary_iterator json::begin_dictionary() {
    if (is_dictionary()) {
        return dictionary_iterator(pimpl->dict_head);
    }
    throw json_exception{.msg = "Json isn't a dict! begin_dictionary"};
}

json::dictionary_iterator json::end_dictionary() {
    if (is_dictionary()) {
        return dictionary_iterator(nullptr);
    }
    throw json_exception{.msg = "Json isn't a dict! end_dictionary"};
}


// string control

std::string &json::get_string() {
    if (!is_string()) {
        throw json_exception{.msg = "json is not a string"};
    }

    return pimpl->s_value;
}

std::string const &json::get_string() const {
    if (!is_string()) {
        throw json_exception{.msg = "json is not a string"};
    }

    return pimpl->s_value;
}

bool json::is_string() const {
    return pimpl->type == Type::String;
}

void json::set_string(std::string const &value) {
    pimpl->clear();
    pimpl->s_value = value;
    pimpl->type = Type::String;
}

void parse_string(std::istream &hs, std::string &str) {
    char c;
    (hs >> std::ws) >> c;
    str.clear();
    while (hs.peek() != '"' || (!str.empty() && str.back() == '\\')) {
        if (hs.peek() != std::istream::traits_type::eof()) {
            str += char(hs.get());
        } else {
            throw json_exception{.msg = "Not a valid string! parse_string"};
        }
    }
    hs.ignore();
}
// number control

double &json::get_number() {
    if (!is_number()) {
        throw json_exception{.msg = "json is not a double"};
    }

    return pimpl->d_value;
}

double const &json::get_number() const {
    if (!is_number()) {
        throw json_exception{.msg = "json is not a double"};
    }

    return pimpl->d_value;
}


bool json::is_number() const {
    return pimpl->type == Type::Number;
}


void json::set_number(double number) {
    pimpl->clear();
    pimpl->d_value = number;
    pimpl->type = Type::Number;
}
// bool control

bool &json::get_bool() {
    if (!is_bool()) {
        throw json_exception{.msg = "json is not a boolean"};
    }

    return pimpl->b_value;
}

bool const &json::get_bool() const {
    if (!is_bool()) {
        throw json_exception{.msg = "json is not a boolean"};
    }

    return pimpl->b_value;
}

bool json::is_bool() const {
    return pimpl->type == Type::Boolean;
}

void json::set_bool(bool value) {
    pimpl->clear();
    pimpl->b_value = value;
    pimpl->type = Type::Boolean;
}

// null control

bool json::is_null() const {
    return pimpl->type == Type::Null;
}

void json::set_null() {
    pimpl->clear();
    pimpl->type = Type::Null;
}

std::ostream &operator<<(std::ostream& lhs, json const &rhs) {
    if (rhs.is_null()) {
        lhs << "null";
    } else if (rhs.is_string()) {
        lhs << '"' << rhs.get_string() << '"';
    } else if (rhs.is_bool()) {
        bool boolean = rhs.get_bool();
        lhs << (boolean ? "true" : "false");
    } else if (rhs.is_number()) {
        lhs.precision(10);
        lhs << rhs.get_number();
    } else if (rhs.is_list()) {
        if(rhs.begin_list() == nullptr){
            lhs << "[]";
        } else {
            lhs << "[ ";
            auto iterator = rhs.begin_list();
            while(iterator != rhs.end_list()){
                lhs << *iterator;
                lhs << ", ";
                ++iterator;
            }
            if(iterator == rhs.end_list())
                lhs << *iterator;
            lhs << " ]";
        }
    } else if (rhs.is_dictionary()) {
        if(rhs.begin_dictionary() == nullptr){
            lhs << "{} ";
        } else {
            lhs << "{ ";
            auto iterator = rhs.begin_dictionary();
            while(iterator != rhs.end_dictionary()){
                lhs << "\"" << iterator->first << "\" : " << iterator->second;
                lhs << ", ";
                iterator++;
            }
            if(iterator == rhs.end_dictionary())
                lhs << "\"" << iterator->first << "\" : " << iterator->second;
            lhs << " }";
        }
    }

    return lhs;
}


std::istream &operator>>(std::istream& hs, json& rhs) {
    char c = (hs >> std::ws).peek();
    if (c == '"') {
        std::string str;
        parse_string(hs, str);
        rhs.set_string(str);
    } else if (std::isdigit(c) || c == '-') {
        //parse_double(hs, rhs);
        double num;
        hs >> num;
        rhs.set_number(num); // Set Num Type
    } else if (c == 't' || c == 'f') {
        int count = hs.peek() == 't'? 4:5;
        char boolean[count+1];
        hs.read(boolean, count);
        boolean[count] = '\0';
        std::string boolean_string = boolean;
        if(boolean_string == "true"){
            rhs.set_bool(true);
        } else if (boolean_string == "false"){
            rhs.set_bool(false);
        } else {
            throw json_exception{ .msg = "Error reading boolean" };
        }
    } else if (c == '[') {
        hs.ignore(); // Read '['
        rhs.set_list(); // Set List Type
        json item;
        while ((hs >> std::ws).peek() != ']') {
            (hs >> std::ws) >> item;
            rhs.push_back(item);

            if ((hs >> std::ws).peek() == ',') {
                hs.ignore();
            }
        }
        hs.ignore();
    } else if (c == '{') {
        char d;
        hs >> d;
        rhs.set_dictionary(); // Set Dict Type
        while ((hs >> std::ws).peek() != '}') { // Fill Dict
            std::string key;
            parse_string(hs, key);
            (hs >> std::ws) >> c;
            if (c != ':')
                throw json_exception{.msg = "Invalid dictionary format"};
            json value;
            (hs >> std::ws) >> value;
            rhs.insert({key, value});

            if (hs.peek() == ',')
                hs.ignore();
        }
        hs.ignore();
    } else if(c == 'n') {
        int count = 4;
        char nullchar[count+1];
        hs.read(nullchar, count);
        nullchar[count] = '\0';
        std::string nullstr = nullchar;
        if(nullstr == "null") {
            rhs.set_null();
        } else {
            throw json_exception{ .msg = "Not valid number" };
        }
    }

    return hs;
}

int main(){
    std::ifstream is("in.json");
    std::ofstream on("out.json");
    json j;
    is >> j;
    on << j;
}
