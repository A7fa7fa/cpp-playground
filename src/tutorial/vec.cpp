#include <vector>

int main() {
    std::vector<int> l = std::vector<int>(5);
    l.push_back(1);
    l.assign(5, 10);

}