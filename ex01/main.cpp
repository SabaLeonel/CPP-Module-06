#include "Serializer.hpp"

int main()
{
    Data originalData = {"SampleString", 12};
    Data* originalPtr = &originalData;

    std::cout <<  "Initial Data: " <<  originalPtr->n << ", " << originalPtr->s1 << "\n\n";

    uintptr_t serialized = Serializer::serialize(originalPtr);
    Data* newDeserializedData = Serializer::deserialize(serialized);

    if (newDeserializedData == originalPtr)
    {
        std::cout << "Serialization/Derialization complete.\n\n";
        std::cout << "Post-Deserialization Data: "  << newDeserializedData->n << ", " << newDeserializedData->s1 << "\n";
    }
    return 0;
}
