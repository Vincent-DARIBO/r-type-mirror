#include "./Components/IComponent.hpp"
#include "./System/Core.hpp"
#include "./Entity/Entity.hpp"
#include <iostream>
#include <memory>

int main()
{
    try {
        Core core({1700, 800}, "r-type", 60);
    } catch (std::string e) {
        std::cout << "error :" << e << std::endl;
    }
}