#include <iostream>
#include <cassert>
#include "skin_changer.h"

void test_attach_fails_without_process() {
    SkinChanger changer;
    assert(!changer.is_attached());
    assert(!changer.attach_to_process()); // Valorant not running in test env
    std::cout << "[PASS] test_attach_fails_without_process" << std::endl;
}

void test_change_skin_fails_when_not_attached() {
    SkinChanger changer;
    assert(!changer.change_skin("Vandal", 1));
    std::cout << "[PASS] test_change_skin_fails_when_not_attached" << std::endl;
}

int main() {
    test_attach_fails_without_process();
    test_change_skin_fails_when_not_attached();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}