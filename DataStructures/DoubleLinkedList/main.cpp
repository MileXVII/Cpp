#include "List.hpp"

/* ========================================================= Main =========================================================*/
int main(void) {
    List<std::string> people;
    people.push_front("Francesco");
    people.push_back("Luca");
    people.push_front("Kevin");
    people.push_front("Josh");
    
    std::cout << "List size: " << people.getSize() << std::endl;
    people.printList();
    people.printMemoryDump();
    
    try {
        std::cout << "\nPopped front: " << people.pop_front() << std::endl;
        std::cout << "Popped back: " << people.pop_back() << std::endl;
        std::cout << "New size: " << people.getSize() << std::endl;
        people.printList();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
