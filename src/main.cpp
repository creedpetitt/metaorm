#include <metaorm/entity/reflection.hpp>

#include <iostream>
#include <string>


/*
 * This is a simple example of using the metaorm library to reflect on a struct.
 * This is for testing one, and will be deleted when the lib is stable. 
 */


struct User {
    int id;
    std::string name;
    double balance;
};

int main() {
    User user{1, "Pegasus", 250.50};

    metaorm::forEachField(user,
        [](std::string_view name, const auto& value) {
            std::cout << name << ": " << value << '\n';
        }
    );
}
