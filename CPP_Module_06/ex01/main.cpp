#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *data = new Data(4242);
    uintptr_t serialized = Serializer::serialize(data);
    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Original: " << data->getVal() << std::endl;
    std::cout << "Deserialized: " << deserialized->getVal() << std::endl;

    delete data;
    // delete deserialized;
    return 0;
}