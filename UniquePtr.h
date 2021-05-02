#ifndef UNIQUEPTR_H_INCLUDED
#define UNIQUEPTR_H_INCLUDED

using ValueType = char;

class UniquePtr {
private:
    ValueType* _ptr;
public:
    // �����������
    UniquePtr();
    // ����������� �� ���������
    explicit UniquePtr(ValueType* ptr);

    // ����������� �����������
    UniquePtr(UniquePtr&& o);

    // ����������� �����������
    UniquePtr(const UniquePtr& o) = delete;

    // �������� ������������ ����� �����������
    UniquePtr& operator=(UniquePtr&& o);

    // �������� ������������ ����� �����������
    UniquePtr& operator=(const UniquePtr& o) = delete;

    // �������� ������������ - ��������� ����� ���������
    // �� �������� ��� ������ ������
    UniquePtr& operator=(ValueType* ptr);

    // ���������� _ptr � nullptr
    // �� ������ ��������� ������ ������ ������!
    void reset();

    // reset + ���������� ������ ���������
    void reset(ValueType* ptr);

    // "������������" ���������
    // ��� �������� ������
    void release();

    // ����������, ������ nullptr ��� ���
    operator bool() const;

    // ���������������
    ValueType& operator*() const;

    // �������� ���������
    ValueType* operator->() const;

    // ���������� ���������
    ValueType* get() const;

    bool operator==(UniquePtr& other) const;
    bool operator!=(UniquePtr& other) const;
};

#endif // UNIQUEPTR_H_INCLUDED
