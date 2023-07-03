#include "InternetDataGenerator.h"

#include <format>

#include "../helpers/HelperDataGenerator.h"
#include "../number/NumberDataGenerator.h"
#include "../person/PersonDataGenerator.h"
#include "data/EmailHosts.h"

namespace faker::internet
{
std::string InternetDataGenerator::username(std::optional<std::string> firstNameInit,
                                            std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit ? *firstNameInit : person::PersonDataGenerator::firstName();

    const auto lastName = lastNameInit ? *lastNameInit : person::PersonDataGenerator::lastName();

    std::string username;

    switch (number::NumberDataGenerator::integer(2))
    {
    case 0:
        username = std::format("{}{}", firstName, number::NumberDataGenerator::integer(99));
        break;
    case 1:
        username =
            std::format("{}{}{}", firstName,
                        helpers::HelperDataGenerator::arrayElement(std::vector<std::string>{".", "_"}), lastName);
        break;
    case 2:
        username = std::format("{}{}{}{}", firstName,
                               helpers::HelperDataGenerator::arrayElement(std::vector<std::string>{".", "_"}), lastName,
                               number::NumberDataGenerator::integer(99));
        break;
    }

    return username;
}

std::string InternetDataGenerator::email()
{
    return username() + emailHosts[0];
}

}
