#include "UniquePtr.h"

#include <algorithm>

UniquePtr::UniquePtr() {
    _ptr = nullptr;
}

UniquePtr::UniquePtr(ValueType* ptr) {
    _ptr = ptr;
}

UniquePtr::UniquePtr(UniquePtr&& o) {
    this->_ptr = o._ptr;
    o._ptr = nullptr;
}

UniquePtr& UniquePtr::operator=(UniquePtr&& o) {
    if (o == *this) {
        return *this;
    }
    std::swap(_ptr, o._ptr);
    delete o._ptr;
    return *this;
}

UniquePtr& UniquePtr::operator=(ValueType* ptr) {
    delete _ptr;
    _ptr = ptr;
    return *this;
}

void UniquePtr::reset() {
    reset(nullptr);
}

void UniquePtr::reset(ValueType* ptr) {
    delete _ptr;
    _ptr = ptr;
}

void UniquePtr::release() {
    _ptr = nullptr;
}

UniquePtr::operator bool() const {
    return _ptr;
}

ValueType& UniquePtr::operator*() const {
    return *_ptr;
}

ValueType* UniquePtr::operator->() const {
    return _ptr;
}

ValueType* UniquePtr::get() const {
    return _ptr;
}

bool UniquePtr::operator==(UniquePtr& other) const {
    return _ptr == other._ptr;
}

bool UniquePtr::operator!=(UniquePtr& other) const {
    return _ptr != other._ptr;
}
