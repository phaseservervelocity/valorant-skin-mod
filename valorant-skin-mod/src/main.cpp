#include <iostream>
#include "skin_changer.h"

int main() {
    std::cout << "=== Valorant Skin Mod v1.0 ===" << std::endl;

    SkinChanger changer;
    if (!changer.attach_to_process()) {
        std::cerr << "Failed to attach. Run as administrator." << std::endl;
        return 1;
    }

    // Example: change Vandal skin to ID 42
    if (changer.change_skin("Vandal", 42)) {
        std::cout << "Skin changed successfully!" << std::endl;
    } else {
        std::cerr << "Skin change failed." << std::endl;
    }

    // Example: change Phantom skin to ID 99
    changer.change_skin("Phantom", 99);

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
    return 0;
}