#ifndef SKIN_CHANGER_H
#define SKIN_CHANGER_H

#include <string>
#include <cstdint>

class SkinChanger {
public:
    SkinChanger();
    ~SkinChanger();

    bool attach_to_process();
    bool change_skin(const std::string& weapon_name, uint32_t new_skin_id);
    bool is_attached() const;

private:
    uint32_t process_id_;
    void* process_handle_;
    bool attached_;

    uintptr_t find_skin_offset(const std::string& weapon_name);
};

#endif // SKIN_CHANGER_H