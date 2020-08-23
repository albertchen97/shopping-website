#pragma once
#include <string>

class User
{
private:
    std::string username;
    std::string password;
public:
    User();
    User(std::string initialUsername, std::string initialPassword);

    std::string getUsername() const;
    std::string getPassword() const;

    void setUsername(std::string initialUsername);
    void setPassword(std::string initialPassword);
};

