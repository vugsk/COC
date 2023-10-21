
#pragma once

#include <exception>

using std::exception;

//* GOOD
class ErrorOutput : public exception {
public:
    ErrorOutput &operator=(const ErrorOutput &) = delete;
    ErrorOutput &operator=(ErrorOutput &&)      = delete;
    
    const char *what() const noexcept override {
        return "Ошибка: отсутствуют данные для вывода";
    }
};

//* GOOD
class ErrorXY : public exception {
public:
    ErrorXY &operator=(const ErrorXY &) = delete;
    ErrorXY &operator=(ErrorXY &&)      = delete;

    const char *what() const noexcept override {
        return "Ошибка: введены неверные координаты";
    }
};

//* GOOD
class ErrorColorSupport : public exception {
public:
    ErrorColorSupport &operator=(const ErrorColorSupport &) = delete;
    ErrorColorSupport &operator=(ErrorColorSupport &&)      = delete;
    
    const char *what() const noexcept override {
        return "Ошибка: не поддерживается терминалом цвета";
    }
};

//* GOOD
class ErrorSizeLessThanZero : public exception {
public:
    ErrorSizeLessThanZero &operator=(const ErrorSizeLessThanZero &) = delete;
    ErrorSizeLessThanZero &operator=(ErrorSizeLessThanZero &&)      = delete;
    
    const char *what() const noexcept override {
        return "Ошибка: размер меньше 0";
    }
};

//* GOOD
class ErrorVectorEmpty : public exception {
public:
    ErrorSizeLessThanZero &operator=(const ErrorSizeLessThanZero &) = delete;
    ErrorSizeLessThanZero &operator=(ErrorSizeLessThanZero &&)      = delete;
    
    const char *what() const noexcept override {
        return "Ошибка: вектор пустой";
    }
};