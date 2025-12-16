#include "List.hpp"

/* ========================================================= Main =========================================================*/

int main(void) {

    List<std::string> people;
    people.push_front("Michael");
    people.push_back("Alfio");
    people.push_front("Mattia");
    people.push_front("Francesco");
    
    std::cout << people.getSize() << std::endl;

    people.printList();

    people.printMemoryDump();

    return 0;
}
