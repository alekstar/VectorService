#ifndef VECTORSERVICE_H
#define	VECTORSERVICE_H

#include <vector>
using std::vector;
using std::size_t;

#include <gtest/gtest_prod.h>

template <typename CUSTOM_TYPE>
class VectorService
{
public:
    static void swapElements(vector<CUSTOM_TYPE>& data, 
                     size_t first_element_index, 
                     size_t second_element_index);
    static void swapWithNextElement(vector<CUSTOM_TYPE>& data, size_t index);
    static bool moreThanNextElement(vector<CUSTOM_TYPE>& data, size_t index);
};

template <typename CUSTOM_TYPE>
void VectorService<CUSTOM_TYPE>::swapElements(vector<CUSTOM_TYPE>& data, 
                                              size_t first_element_index, 
                                              size_t second_element_index)
{
    CUSTOM_TYPE temp;
    const unsigned int vector_size = data.size();
    if(first_element_index >= 0 && first_element_index < vector_size && 
       second_element_index >= 0 && second_element_index < vector_size &&
       first_element_index != second_element_index)
    {
        temp = data.at(first_element_index);
        data.at(first_element_index) = data.at(second_element_index);
        data.at(second_element_index) = temp;
    }
}

template <typename CUSTOM_TYPE>
void VectorService<CUSTOM_TYPE>::swapWithNextElement(
        vector<CUSTOM_TYPE>& data, 
        size_t index)
{
    VectorService<CUSTOM_TYPE>::swapElements(data, index, index + 1);
}

template <typename CUSTOM_TYPE>
bool VectorService<CUSTOM_TYPE>::moreThanNextElement(
        vector<CUSTOM_TYPE>& data, 
        size_t index)
{
    if(index >= 0 && index < data.size() - 1)
    {
        return data.at(index) > data.at(index + 1);
    }
    
    return false;
}

#endif	/* VECTORSERVICE_H */
