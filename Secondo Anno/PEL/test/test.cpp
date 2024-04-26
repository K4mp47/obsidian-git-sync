#include "../include/json.hpp"

using namespace std;

void test_json_constructor() {
    cout << "testing json constructor... ";
    json j;
    assert(j.is_null());
    cout << "passed" << endl;
}

void test_json_number() {
    cout << "testing number json... ";
    json j;
    j.set_number(1.0);
    assert(j.is_number());
    assert(j.get_number() == 1.0);
    cout << "passed" << endl;
}

void test_json_bool() {
    cout << "testing bool json... ";
    json j;
    j.set_bool(true);
    assert(j.is_bool());
    assert(j.get_bool());
    cout << "passed" << endl;
}

void test_json_string() {
    cout << "testing string json... ";
    json j;
    j.set_string("test");
    assert(j.is_string());
    assert(j.get_string() == "test");
    cout << "passed" << endl;
}


void test_json_copy_constructor() {
    cout << "testing json copy constructor... ";
    json j1;
    j1.set_number(1.0);
    json j2 = j1;
    assert(j2.is_number());
    assert(j2.get_number() == 1.0);
    j1.set_string("test");
    assert(j2.is_number());
    assert(j1.is_string());
    cout << "passed" << endl;
}

void test_json_move_constructor() {
    cout << "testing json move constructor... ";
    json j1;
    j1.set_number(1.0);

    json j2(std::move(j1));
    assert(j2.is_number());

    j1 = j2;
    assert(j1.is_number());

    j2 = std::move(j1);
    j1 = std::move(j2);
    assert(j1.is_number());

    cout << "passed" << endl;
}

void test_json_list() {
    std::cout << "testing json list changes... ";
    // elements
    json number1;
    number1.set_number(1.0);

    json number2;
    number2.set_number(2.0);

    json string;
    string.set_string("test");

    json j;
    j.set_list();
    assert(j.is_list());

    j.push_back(string);
    j.push_back(number1);
    j.push_front(number2);

    // untestable: iterators are only forward declared

//    auto it = j.begin_list();
//    assert(it->is_number());
//    assert(it->get_number() == 2.0);
//    ++it;
//    assert(it->is_string());
//    assert(it->get_string() == "test");
//    ++it;
//    assert(it->is_number());
//    assert(it->get_number() == 1.0);
//    ++it;
//    assert(it == j.end_list());

    std::cout << "passed" << std::endl;
}

void test_json_dictionary() {
    std::cout << "testing json dictionary changes... ";
    // elements
    json number1;
    number1.set_number(1.0);

    json number2;
    number2.set_number(2.0);

    json string;
    string.set_string("test");

    json j;
    j.set_dictionary();
    assert(j.is_dictionary());

    j["string"] = string;
    assert(j["string"].get_string() == "test");
    assert(j["string"].is_string());
    j["number"] = number1;
    assert(j["number"].is_number());
    assert(j["number"].get_number() == 1.0);
    j["number"] = number2;
    assert(j["number"].is_number());
    assert(j["number"].get_number() == 2.0);

    // untestable: iterators are only forward declared

//    auto it = j.begin_dictionary();
//    assert(it->first == "number");
//    assert(it->second.is_number());
//    assert(it->second.get_number() == 2.0);
//    ++it;
//    assert(it->first == "string");
//    assert(it->second.is_string());
//    assert(it->second.get_string() == "test");
//    ++it;
//    assert(it == j.end_dictionary());

    std::cout << "passed" << std::endl;
}

void test_json_exceptions() {
    cout << "testing json exceptions... ";
    json j;
    j.set_number(1.0);

    try {
        j.get_string();
        assert(false);
    } catch (json_exception &e) {
        assert(true);
    }

    try {
        j.get_bool();
        assert(false);
    } catch (json_exception &e) {
        assert(true);
    }

    try {
        j.push_back(json());
        assert(false);
    } catch (json_exception &e) {
        assert(true);
    }

    try {
        j["test"] = json();
        assert(false);
    } catch (json_exception &e) {
        assert(true);
    }

    cout << "passed" << endl;
}

int main() {
    try {
        test_json_constructor();
        test_json_number();
        test_json_bool();
        test_json_string();
        test_json_copy_constructor();
        test_json_move_constructor();
        test_json_list();
        test_json_dictionary();
        test_json_exceptions();
    } catch (json_exception e) { // NOLINT
        cout << "failed: " << endl;
        cout << e.msg << endl;
        throw e; // NOLINT
    }
}
