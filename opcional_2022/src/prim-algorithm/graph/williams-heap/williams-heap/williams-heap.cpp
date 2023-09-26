#include "williams-heap.h"

Williams_heap::Williams_heap(int l)
{
    _heap = std::vector<std::pair<int, int>>(l);
    _positions = std::map<int, int>();
    _next = 0;
}

Williams_heap::~Williams_heap()
{
}

bool Williams_heap::isHeap()
{
    if (_next > _heap.size())
    {
        return false;
    }

    bool isHeap = true;
    long unsigned int i = 0;

    while (isHeap && i < _next)
    {
        isHeap = _heap[(i - 1) / 2] <= _heap[i];
        ++i;
    }
    return isHeap;
}

void Williams_heap::insert(int e, int v)
{
    if (_positions.find(e) == _positions.end())
    {
        _heap[_next] = std::make_pair(e, v);
        _positions.emplace(e, _next);
        _next++;
        wh_float();
    }
}

void Williams_heap::wh_float()
{
    int j = _next - 1;
    while (j > 0 && _heap[(j - 1) / 2].second > _heap[j].second)
    {
        auto aux = _heap[(j - 1) / 2];
        _positions.find(_heap[(j - 1) / 2].first)->second = j;
        _positions.find(_heap[j].first)->second = (j - 1) / 2;
        _heap[(j - 1) / 2] = _heap[j];
        _heap[j] = aux;
        j = (j - 1) / 2;
    }
}

void Williams_heap::deleteMin()
{
    if (_next > 0)
    {
        _heap[0] = _heap[_next - 1];
        _next--;
        sink(0, _next);
    }
}

void Williams_heap::sink(int s, int l)
{
    if (l >= s && s >= 0)
    {
        int j = s;
        while (2 * j + 1 < l)
        {
            int m;
            if (2 * j + 2 < l && _heap[2 * j + 2].second <= _heap[2 * j + 1].second)
            {
                m = 2 * j + 2; // right son is the minimum
            }
            else
            {
                m = 2 * j + 1; // left son is the minimum
            }
            if (_heap[j] > _heap[m])
            {
                auto aux = _heap[m];
                _positions.find(_heap[m].first)->second = j;
                _positions.find(_heap[j].first)->second = m;
                _heap[m] = _heap[j];
                _heap[j] = aux;

                j = m;
            }
            else
            {
                break;
            }
        }
    }
}

std::pair<int, int> Williams_heap::min()
{
    return _heap[0];
}

void Williams_heap::heapsort(std::vector<std::pair<int, int>> &a)
{
    long unsigned int i = 0;
    Williams_heap queue(a.size());
    while (i < a.size())
    {
        queue.insert(a[i].first, a[i].second);
        i++;
    }
    i = 0;
    while (i < a.size())
    {
        a[i] = queue.min();
        queue.deleteMin();
        i++;
    }
}

void Williams_heap::decreaseKey(int key, int sub)
{
    if (_positions.find(key) == _positions.end())
    {
        throw std::invalid_argument("Key does not exists");
    }

    key = _positions.find(key)->second;

    _heap[key].second = sub;

    while (key >= 1)
    {
        if (_heap[key] < _heap[key / 2])
        {
            auto aux = _heap[key];
            _positions.find(_heap[key].first)->second = key / 2;
            _positions.find(_heap[key / 2].first)->second = key;
            _heap[key] = _heap[key / 2];
            _heap[key / 2] = aux;
            key = key / 2;
        }
        else
        {
            break;
        }
    }
}

void Williams_heap::printVector()
{
    for (long unsigned int i = 0; i < _next; ++i)
    {
        std::cout << _heap[i].first << " ";
    }
    std::cout << "\n";
}

bool Williams_heap::empty()
{
    return _next == 0;
}

long unsigned int Williams_heap::next()
{
    return _next;
}
