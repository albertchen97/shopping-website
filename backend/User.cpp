#include "User.h"

User::User() {};
User::User(std::string initialUsername, std::string initialPassword)
	: username(initialUsername), password(initialPassword) {};

std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }

void User::setUsername(std::string initialUsername) { username = initialUsername; }
void User::setPassword(std::string initialPassword) { password = initialPassword; }