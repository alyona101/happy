#pragma once

#include <string>

class Person;

// Наблюдатель за состоянием человека.
class PersonObserver {
public:
    // Этот метод вызывается, когда меняется состояние удовлетворённости человека
    virtual void OnSatisfactionChanged(Person& person, int old_value, int new_value) {
        cout << "The Satisfaction changed from " << old_value << " to " << new_value << endl;
    }

protected:
    // Класс PersonObserver не предназначен для удаления напрямую
    virtual ~PersonObserver() = default;
};

/*
    Человек.
    При изменении уровня удовлетворённости уведомляет
    связанного с ним наблюдателя
*/
class Person {
public:
    Person(const std::string& name, int age, PersonObserver* obs, int count)
        :name_ = name
        ,age_ = age
        ,observer_ = obs
    {  
    }

    int GetSatisfaction() const {
        return satisfaction_;
    }

    const std::string& GetName() const {
        return name_;
    }

    // «Привязывает» наблюдателя к человеку. Привязанный наблюдатель
    // уведомляется об изменении уровня удовлетворённости человека
    // Новый наблюдатель заменяет собой ранее привязанного
    // Если передать nullptr в качестве наблюдателя, это эквивалентно отсутствию наблюдателя
    void SetObserver(PersonObserver* observer) {
        // Напишите реализацию самостоятельно
    }

    int GetAge() const {
        return age_;
    }

    // Увеличивает на 1 количество походов на танцы
    // Увеличивает удовлетворённость на 1
    void Dance() {
        count_dance_++;
        satisfaction_++;
    }

    int GetDanceCount() const {
        return count_dance_;
    }

    // Прожить день. Реализация в базовом классе ничего не делает
    virtual void LiveADay() {
        // Подклассы могут переопределить этот метод
    }

protected:
    void SetSatisfaction() {

    }

private:
    std::string name_;
    PersonObserver* observer_ = nullptr;
    int age_;
    int count_dance_;
    int satisfaction_ = 100;
};

// Рабочий.
// День рабочего проходит за работой
class Worker {
public:
    Worker(const std::string& name, int age) {
        // Напишите недостающий код
    }

    // Рабочий старше 30 лет и младше 40 за танец получает 2 единицы удовлетворённости вместо 1

    // День рабочего проходит за работой

    // Увеличивает счётчик сделанной работы на 1, уменьшает удовлетворённость на 5
    void Work() {
        // Напишите тело метода самостоятельно
    }

    // Возвращает значение счётчика сделанной работы
    int GetWorkDone() const {
        // Заглушка. Напишите реализацию самостоятельно
        return 0;
    }
};

// Студент.
// День студента проходит за учёбой
class Student {
public:
    Student(const std::string& name, int age) {
        // Напишите недостающий код
    }

    // День студента проходит за учёбой

    // Учёба увеличивает уровень знаний на 1, уменьшает уровень удовлетворённости на 3
    void Study() {
        // Напишите реализацию самостоятельно
    }

    // Возвращает уровень знаний
    int GetKnowledgeLevel() const {
        // Заглушка, напишите реализацию самостоятельно
        return 0;
    }
};