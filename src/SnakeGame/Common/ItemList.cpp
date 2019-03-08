#include "stdafx.h"
#include "ItemList.h"

namespace sg
{
    ItemList::ItemList(std::vector<std::string>&& items)
        : m_currentItemIdx(0)
        , m_items(std::move(items))
    {
    }

    void ItemList::Update(Input input)
    {
        switch (input)
        {
        case Input::Up:
            if (m_currentItemIdx != 0)
            {
                --m_currentItemIdx;
            }
            break;

        case Input::Down:
            if (m_currentItemIdx != (m_items.size() - 1))
            {
                ++m_currentItemIdx;
            }
            break;

        default:
            break;
        }
    }

    size_t ItemList::GetCurrentItemIdx()
    {
        return m_currentItemIdx;
    }

    std::string ItemList::FormatItemList()
    {
        std::ostringstream os;
        for (size_t i = 0; i < m_items.size(); ++i)
        {
            os << (i == m_currentItemIdx ? "  # " : "    ") << m_items.at(i) << '\n';
        }

        return os.str();
    }
}