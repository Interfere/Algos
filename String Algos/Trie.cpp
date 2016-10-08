#include "Trie.hpp"

struct TrieNode {
    size_t m_no = -1;
    std::unordered_map<char, TrieNodeRef> m_children;
};

Trie::Trie(const std::vector<std::string>& lookupTable) {
    m_root = std::make_shared<TrieNode>();
    for (size_t i = 0; i < lookupTable.size(); ++i) {
        TrieNodeRef node = m_root;
        const std::string& str = lookupTable[i];
        for (auto& ch : str) {
            auto it = node->m_children.find(ch);
            if (it == node->m_children.end()) 
                node->m_children.emplace(ch, std::make_shared<TrieNode>());
            node = node->m_children[ch];
        }
        node->m_no = i;
    }
}

bool Trie::find(const std::string& str) const {
    TrieNodeRef node = m_root;
    for (auto& ch : str) {
        auto it = node->m_children.find(ch);
        if (it == node->m_children.end())
            return false;
        node = it->second;
    }
    return node->m_no != -1;
}

