#include<string>
#include<memory>

class User {
public:
    User();
    std::string id, password, name, nick_name, priority, phone, create_at;
    bool is_available;
    void self_checking() const;
    void change_password();
    User& register_user();
private:
protected:
};