#include "Serializer.hpp"

int main()
{
    t_data *Data = new t_data;
    Data->i = 42;
    
    uintptr_t serializedData = Serializer::serialize(Data);

    t_data *deserializedData = Serializer::deserialize(serializedData);

    if (deserializedData == Data)
    {
        std::cout << " Data Address: " << Data << std::endl;
        std::cout << " Data: i = " << Data->i << std::endl;
        std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
        std::cout << " Data: i = " << deserializedData->i << std::endl;
    }
    else
        std::cout << "Serialization and Deserialization Failed!" << std::endl;
    delete Data;
    return 0;
}