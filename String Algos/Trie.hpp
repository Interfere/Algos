#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

struct TrieNode;
typedef std::shared_ptr<TrieNode> TrieNodeRef;

class Trie {
public:
    explicit Trie(const std::vector<std::string>& lookupTable);

    bool find(const std::string& str) const;

private:
    TrieNodeRef         m_root;
};
