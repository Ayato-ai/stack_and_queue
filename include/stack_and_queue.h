// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
// 
// Носков И.А.
#include <iostream>
using namespace std;

//Вектор
template<typename T>
class Mvector {
protected:
    size_t sz;
    size_t capacity;
    T* pMem;
public:
    Mvector(size_t size = 0) : sz(size), capacity(2 * size + 1)
    {
        pMem = new T[capacity];     //Выделяем память 2 * sz + 1
        if (pMem == nullptr)        // Проверка выделения памяти
            throw ("failed_to_allocate_memory");
    }
    Mvector(T* arr, size_t size) : sz(size), capacity(2 * size + 1)
    {
        if (arr == nullptr)
            throw ("arr_is_null");
        pMem = new T[capacity];     //Выделяем память 2 * sz + 1
        if (pMem == nullptr)        // Проверка выделения памяти
            throw ("failed_to_allocate_memory");
        copy(arr, arr + size, pMem);
    }
    Mvector(const Mvector& v) {
        sz = v.sz;
        capacity = v.capacity;
        pMem = new T[capacity];     //Выделяем память 2 * sz + 1
        if (pMem == nullptr)        // Проверка выделения памяти
            throw ("failed_to_allocate_memory");
        for (size_t i = 0; i < sz; i++)
            pMem[i] = v.pMem[i];
    }
    Mvector(Mvector&& v) noexcept {
        sz = 0;
        pMem = nullptr;
        swap(*this, v);
    }
    ~Mvector() {
        delete[] pMem;
        pMem = nullptr;
    }
    Mvector& operator=(const Mvector& v) {
        if (this == &v) return *this;
        if (sz == v.sz) {
            copy(v.pMem, v.pMem + sz, pMem);
            capacity = v.capacity;
        }
        else {
            sz = v.sz;
            capacity = v.capacity;
            delete[] pMem;
            pMem = new T[capacity];
            if (pMem == nullptr)        // Проверка выделения памяти
                throw ("failed_to_allocate_memory");
            copy(v.pMem, v.pMem + sz, pMem);
        }
        return *this;
    }

    size_t size() const noexcept {
        return sz;
    }

    // индексация
    T& operator[](size_t ind) {
        return pMem[ind];
    }
    const T& operator[](size_t ind) const {
        return pMem[ind];
    }

    // сравнение
    bool operator==(const Mvector& v) const noexcept {
        if (sz != v.sz) return 0;
        for (size_t i = 0; i < sz; i++)
            if (pMem[i] != v.pMem[i]) return 0;
        return 1;
    }
    bool operator!=(const Mvector& v) const noexcept {
        return !(*this == v);
    }
    // операции вектора
    T back() const {
        if (empty())        //Проверка на пустоту
            throw ("null_of_size_vector");
        return pMem[sz - 1];
    }
    size_t _size() const noexcept {
        return sz;
    }
    size_t _capacity() const noexcept {
        return capacity;
    }
    bool full() const {
        if (sz == capacity) return 1;
        else return 0;
    }
    bool empty() const {
        if (sz == 0) return 1;
        else return 0;
    }
    void pop_back() {
        if (!empty())       //Проверка на пустоту
            pMem[sz - 1] = T(0);
        else
            throw ("null_of_size_vector");
        sz--;
    }
    void push_back(T elem) {
        if (!full())        //Проверка на полноту 
            ;
        else
            resize(sz * 2);
        pMem[sz] = elem;
        sz++;
    }
    // Перепаковка
    void resize(size_t size) {
        T* pMem_new = new T[2 * size + 1];
        if (pMem_new != nullptr) {      // Проверка выделения памяти
            copy(pMem, pMem + sz, pMem_new);
            capacity = size * 2 + 1;
            delete[] pMem;
            pMem = pMem_new;
            pMem_new = nullptr;
        }
        else
            throw ("failed_to_allocate_memory");
    }
    void swap(Mvector& left_v, Mvector& right_v) {
        swap(left_v.pMem, right_v.pMem);
        swap(left_v.sz, right_v.sz);
        swap(left_v.capacity, right_v.capacity);
    }
    void erase(size_t index) {
        if (index >= sz)        //Проверка на выход за границу
            throw ("out_of_bounds_index");
        if (!empty()) {         //Проверка на пустоту
            for (int i = index; i < sz - 1; i++)
                pMem[i] = pMem[i + 1];
            pMem[sz - 1] = 0;
            sz--;
        }
        else
            throw ("vector_is_empty!");
    }
};

//Стек
template<typename T>
class Mstack : public Mvector<T> {
private:
    using Mvector<T>::sz;
    using Mvector<T>::capacity;
    using Mvector<T>::pMem;
    using Mvector<T>::pop_back;
    using Mvector<T>::push_back;
    using Mvector<T>::resize;
public:
    Mstack() : Mvector<T>(0) {}
    using Mvector<T>::full;
    using Mvector<T>::empty;
    using Mvector<T>::size;
    using Mvector<T>::_capacity;
    using Mvector<T>::operator[];
    using Mvector<T>::back;

    void pop() {
        pop_back();
    }
    void push(T elem) {
        push_back(elem);
    }
    T top() {
        return back();
    }
};

//Очередь
template<typename T>
class Mqueue : public Mvector<T> {
private:
    using Mvector<T>::sz;
    using Mvector<T>::capacity;
    using Mvector<T>::pMem;
    size_t front, back;
    using Mvector<T>::push_back;
    using Mvector<T>::resize;
public:
    Mqueue() : Mvector<T>(0), front(0), back(0) {}
    using Mvector<T>::full;
    using Mvector<T>::empty;
    using Mvector<T>::size;
    using Mvector<T>::_capacity;


    void pop() {
        if (!empty()) {         // Проверка на пустоту
            pMem[front] = 0;
            if (front == capacity - 1)
                front = 0;
            else
                front++;
            sz--;
        }
        else
            throw ("null_of_size_quele");
    }
    void push(T elem) {
        if (full())
            resize(2 * sz);
        pMem[back] = elem;
        if (back == capacity - 1)
            back = 0;
        else
            back++;
        sz++;
    }
    T get_front_elem() {
        return pMem[front];
    }
    T get_back_elem() {
        if (back == 0)
            return pMem[capacity - 1];
        else
            return pMem[back - 1];
    }
};

//Очередь на двух стеках
template<typename T>
class Mqueue_on_stacks : public Mvector<Mstack<T>> {
private:
    using::Mvector<Mstack<T>>::pMem;
    size_t sz;
    size_t capacity;
public:
    Mqueue_on_stacks() : Mvector<Mstack<T>>(2), sz(0), capacity(2) {};

    size_t size_() const noexcept { return sz; };
    size_t capacity_() const noexcept { return capacity; };
    bool empty() const noexcept { return (sz == 0); };
    bool full() const noexcept { return (sz == capacity); };

    void push(T elem) {
        pMem[0].push(elem);
        sz++;
    }
    void pop() {
        if (!empty()) {         // Проверка на пустоту
            if (pMem[1].empty())
                while (!pMem[0].empty()) {
                    T mem = pMem[0].top();
                    pMem[1].push(mem);
                    pMem[0].pop();
                }
        }
        else
            throw ("null_of_size_quele");
        pMem[1].pop();
        sz--;
    }
    T get_back_elem() {
        if (!pMem[1].empty())
            return pMem[1][0];
        if (!pMem[0].empty())
            return pMem[0][pMem[0].size()];
        else
            return 0;
    }
    T get_front_elem() {
        if (!pMem[1].empty())
            return pMem[1][pMem[1].size()];
        if (!pMem[0].empty())
            return pMem[0][0];
        else
            return 0;
    }
};