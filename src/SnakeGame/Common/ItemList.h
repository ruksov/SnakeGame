#pragma once
#include "Input.h"

namespace sg
{
    //
    // This utils class represents some type of item list like:
    //      item1
    //    # item2
    //      item3
    //
    // The ItemList handles Up and Down inputs to switching
    // between it's items.
    //
    class ItemList
    {
    public:
        explicit ItemList(std::vector<std::string>&& items);

        void Update(Input input);
        size_t GetCurrentItemIdx();
        std::string FormatItemList();

    private:
        size_t m_currentItemIdx;
        std::vector<std::string> m_items;
    };
}


