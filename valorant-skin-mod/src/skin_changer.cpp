#include "skin_changer.h"
#include "memory_utils.h"
#include <iostream>
#include <unordered_map>

SkinChanger::SkinChanger() : process_id_(0), process_handle_(nullptr), attached_(false) {}

SkinChanger::~SkinChanger() {
    if (attached_) {
        MemoryUtils::close_process(process_handle_);
    }
}

bool SkinChanger::attach_to_process() {
    process_id_ = MemoryUtils::find_process_id("VALORANT-Win64-Shipping.exe");
    if (process_id_ == 0) {
        std::cerr << "[ERROR] Valorant process not found." << std::endl;
        return false;
    }

    process_handle_ = MemoryUtils::open_process(process_id_);
    if (process_handle_ == nullptr) {
        std::cerr << "[ERROR] Failed to open process." << std::endl;
        return false;
    }

    attached_ = true;
    std::cout << "[INFO] Attached to Valorant (PID: " << process_id_ << ")" << std::endl;
    return true;
}

bool SkinChanger::is_attached() const {
    return attached_;
}

bool SkinChanger::change_skin(const std::string& weapon_name, uint32_t new_skin_id) {
    if (!attached_) {
        std::cerr << "[ERROR] Not attached to process." << std::endl;
        return false;
    }

    uintptr_t skin_offset = find_skin_offset(weapon_name);
    if (skin_offset == 0) {
        std::cerr << "[ERROR] Unknown weapon: " << weapon_name << std::endl;
        return false;
    }

    // Base address placeholder (0x0 in this example)
    uintptr_t base_address = 0x7FF600000000;
    uintptr_t target_address = base_address + skin_offset;

    if (!MemoryUtils::write_memory(process_handle_, target_address, &new_skin_id, sizeof(new_skin_id))) {
        std::cerr << "[ERROR] Failed to write skin ID." << std::endl;
        return false;
    }

    std::cout << "[INFO] Changed " << weapon_name << " skin to ID " << new_skin_id << std::endl;
    return true;
}

uintptr_t SkinChanger::find_skin_offset(const std::string& weapon_name) {
    static const std::unordered_map<std::string, uintptr_t> weapon_offsets = {
        {"Vandal", 0x1234A0},
        {"Phantom", 0x1234B0},
        {"Operator", 0x1234C0},
        {"Classic", 0x1234D0},
        {"Sheriff", 0x1234E0}
    };

    auto it = weapon_offsets.find(weapon_name);
    if (it != weapon_offsets.end()) {
        return it->second;
    }
    return 0;
}