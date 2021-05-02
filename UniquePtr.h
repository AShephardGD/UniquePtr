#ifndef UNIQUEPTR_H_INCLUDED
#define UNIQUEPTR_H_INCLUDED

using ValueType = char;

class UniquePtr {
private:
    ValueType* _ptr;
public:
    // Конструктор
    UniquePtr();
    // Конструктор из указателя
    explicit UniquePtr(ValueType* ptr);

    // Конструктор перемещения
    UniquePtr(UniquePtr&& o);

    // Конструктор копирования
    UniquePtr(const UniquePtr& o) = delete;

    // оператор присваивания через перемещение
    UniquePtr& operator=(UniquePtr&& o);

    // оператор присваивания через копирование
    UniquePtr& operator=(const UniquePtr& o) = delete;

    // оператор присваивания - присвоить новый указатель
    // Не забывать про старую память
    UniquePtr& operator=(ValueType* ptr);

    // сбрасывает _ptr в nullptr
    // не забыть почистить память память память!
    void reset();

    // reset + присвоение нового указателя
    void reset(ValueType* ptr);

    // "Освобождение" указателя
    // без удаления памяти
    void release();

    // возвращает, внутри nullptr или нет
    operator bool() const;

    // разыменовывание
    ValueType& operator*() const;

    // оператор стрелочки
    ValueType* operator->() const;

    // возвращает указатель
    ValueType* get() const;

    bool operator==(UniquePtr& other) const;
    bool operator!=(UniquePtr& other) const;
};

#endif // UNIQUEPTR_H_INCLUDED
