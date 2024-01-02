#include "Serializer.hpp"

int main()
{
    t_data *Data = new t_data;
    Data->i = 42;
    
    uintptr_t serializedData = Serializer::serialize(Data);

    t_data *deserializedData = Serializer::deserialize(serializedData);

    std::cout << "Data Address: " << Data << std::endl;
    std::cout << "Data: i = " << Data->i << std::endl;
    std::cout << "DeserializedData Address: " << deserializedData << std::endl;
    std::cout << "DeserializedData: i = " << deserializedData->i << std::endl;

    delete Data;

    return 0;
}
