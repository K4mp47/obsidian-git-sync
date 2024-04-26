#include "../include/json.hpp"

using namespace std;

void test_json_decoding_empty() {
    cout << "testing json decoding empty... ";

    std::ifstream file("../assets/in/empty.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_null());

    file.close();
    cout << "passed" << endl;
}

void test_json_decoding_null() {
    cout << "testing json decoding null... ";

    std::ifstream file("../assets/in/null.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_null());

    file.close();
    cout << "passed" << endl;
}

void test_json_decoding_bool() {
    cout << "testing json decoding bool... ";

    std::ifstream file("../assets/in/bool.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_bool());
    assert(j.get_bool());

    file.close();
    cout << "passed" << endl;
}

void test_json_decoding_number() {
    cout << "testing json decoding number... ";

    std::ifstream file("../assets/in/number.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_number());
    assert(j.get_number() == 123.456e12);

    file.close();
    cout << "passed" << endl;
}

void test_json_decoding_string() {
    cout << "testing json decoding string... ";

    std::ifstream file("../assets/in/string.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_string());
    assert(j.get_string() == "testing \\\" \\\\\" string\\n");

    file.close();
    cout << "passed" << endl;
}

void test_json_decoding_list() {
    std::cout << "testing json decoding list... ";

    std::ifstream file("../assets/in/list.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_list());

    // untestable: iterators are only forward declared

//    // [
//    auto it = j.begin_list();
//    assert(it->is_string());
//    assert(it->get_string() == "test");
//    ++it;
//    assert(it->is_string());
//    assert(it->get_string() == "test \\\"string\\\"");
//    ++it;
//    assert(it->is_number());
//    assert(it->get_number() == 34.5);
//    ++it;
//    assert(it->is_bool());
//    assert(it->get_bool());
//    ++it;
//    assert(it->is_null());
//    ++it;
//    assert(it->is_list());
//
//    // [
//    auto it_nested = it->begin_list();
//    assert(it_nested->is_number());
//    assert(it_nested->get_number() == 1);
//    ++it_nested;
//    assert(it_nested->is_number());
//    assert(it_nested->get_number() == 2);
//    ++it_nested;
//    assert(it_nested->is_bool());
//    assert(!it_nested->get_bool());
//    ++it_nested;
//    assert(it_nested->is_number());
//    assert(it_nested->get_number() == 43);
//    ++it_nested;
//    assert(it_nested == it->end_list());
//    // ]
//
//    ++it;
//    assert(it == j.end_list());
//    // ]

    file.close();
    std::cout << "passed" << std::endl;
}

void test_json_decoding_dictionary() {
    std::cout << "testing json decoding dictionary... ";

    std::ifstream file("../assets/in/dictionary.json");
    assert(file.is_open());

    json j;
    file >> j;
    assert(j.is_dictionary());

    assert(j["first key"].is_number());
    assert(j["first key"].get_number() == 5);

    assert(j["second \\\"key\\\""].is_list());

    assert(j["third key"].is_string());
    assert(j["third key"].get_string().empty());

    assert(j["fourth key"].is_dictionary());
    assert(j["fourth key"]["a"].is_number());
    assert(j["fourth key"]["a"].get_number() == 4);
    assert(j["fourth key"]["b"].is_list());

    // untestable: iterators are only forward declared

//    // {
//    auto it = j.begin_dictionary();
//    assert(it->first == "fourth key");
//    assert(it->second.is_dictionary());
//
//    // {
//    auto it_dictionary = it->second.begin_dictionary();
//    assert(it_dictionary->first == "b");
//    assert(it_dictionary->second.is_list());
//
//    // [
//    auto it_dictionary_list = it_dictionary->second.begin_list();
//    assert(it_dictionary_list->is_number());
//    assert(it_dictionary_list->get_number() == 4);
//    ++it_dictionary_list;
//    assert(it_dictionary_list->is_null());
//    ++it_dictionary_list;
//    assert(it_dictionary_list == it_dictionary->second.end_list());
//    // ]
//
//    ++it_dictionary;
//    assert(it_dictionary->first == "a");
//    assert(it_dictionary->second.is_number());
//    assert(it_dictionary->second.get_number() == 4);
//    ++it_dictionary;
//    assert(it_dictionary == it->second.end_dictionary());
//    // }
//
//    ++it;
//    assert(it->first == "third key");
//    assert(it->second.is_string());
//    assert(it->second.get_string() == "test");
//    ++it;
//    assert(it->first == "second \\\"key\\\"");
//    assert(it->second.is_list());
//
//    // [
//    auto it_list = it->second.begin_list();
//    assert(it_list->is_number());
//    assert(it_list->get_number() == 4.12);
//    ++it_list;
//    assert(it_list->is_number());
//    assert(it_list->get_number() == 2);
//    ++it_list;
//    assert(it_list->is_bool());
//    assert(it_list->get_bool());
//    ++it_list;
//    assert(it_list == it->second.end_list());
//    // ]
//
//    ++it;
//    assert(it->first == "first key");
//    assert(it->second.is_number());
//    assert(it->second.get_number() == 5);
//    ++it;
//    assert(it == j.end_dictionary());
//    // }

    file.close();
    std::cout << "passed" << std::endl;
}

void test_json_decoding_exceptions() {
    std::cout << "testing json decoding exceptions... ";

    std::ifstream file("../assets/in/invalid.json");
    assert(file.is_open());

    json j;
    try {
        file >> j;
        std::cout << "failed" << std::endl;
        assert(false);
    } catch (json_exception e) {
        cout << "passed: " + e.msg << endl;
        assert(true);
    }
}

void test_json_encoding() {
    std::cout << "testing json encoding... ";

    std::ifstream file("../assets/in/dictionary.json");
    assert(file.is_open());

    json j;
    file >> j;

    file.close();

    std::ofstream out("../assets/out.json");
    assert(out.is_open());

    out << j;

    out.close();

    // cleanup
    out.open("../assets/out.json");
    out << "";
    out.close();

    std::cout << "passed" << std::endl;
}

void test_json_streaming_stress() {
    std::cout << "testing json streaming stress... ";

    std::ifstream file("../assets/in/stress.json");
    assert(file.is_open());

    json j;
    file >> j;

    file.close();

    std::ofstream out("../assets/out.json");
    assert(out.is_open());

    out << j;

    out.close();

    // cleanup
    out.open("../assets/out.json");
    out << "";
    out.close();

    std::cout << "passed" << std::endl;
}

int main() {
    try {
        test_json_decoding_empty();
        test_json_decoding_null();
        test_json_decoding_bool();
        test_json_decoding_number();
        test_json_decoding_string();
        test_json_decoding_list();
        test_json_decoding_dictionary();
        test_json_decoding_exceptions();
        test_json_encoding();
        test_json_streaming_stress();
    } catch (json_exception e) {
        cout << "failed: ";
        cout << e.msg << endl;
        throw e;
    }
}
