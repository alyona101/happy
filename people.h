#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>
#include <string>


class Person;

// Наблюдатель за состоянием человека.
class PersonObserver
{
public:
    // Этот метод вызывается, когда меняется состояние удовлетворённости человека
   virtual void OnSatisfactionChanged(Person& /*person*/, int /*old_value*/, int /*new_value*/) {
        // Реализация метода базового класса ничего не делает
    }
protected:
    // Класс PersonObserver не предназначен для удаления напрямую
    ~PersonObserver() = default;
};

class Person
{
public:
    
    Person(const std::string& name, int age)
        : name_(name)
        , age_(age)
    {
    }

virtual ~Person() = default;
    
    int GetSatisfaction() const
    {
        return satisfaction_;
    }

    std::string GetName() const
    {
        return name_;
    }

    int GetAge() const
    {
        return age_;
    }

    // Прожить день. Реализация в базовом классе ничего не делает
    virtual void LiveADay() {}

    void SetObserver(PersonObserver* observer)
    {
        observer_ = observer;
    }

    int GetDanceCount() const
    {
        return count_dance_;
    }

    virtual void Dance()
    {
        SetSatisfaction(satisfaction_ + 1);
        ++count_dance_;
    }



protected:
    void SetSatisfaction(int value)
    {
        if (satisfaction_ != value)
        {
            int old_satisfaction = satisfaction_;
            satisfaction_ = value;
            // Если у человека есть наблюдатель, сообщаем ему об изменении удовлетворённости
            if (observer_)
            {
                observer_->OnSatisfactionChanged(*this, old_satisfaction, satisfaction_);
            }
        }
    }


private:
    std::string name_;
    PersonObserver* observer_ = nullptr;
    int satisfaction_ = 100;
    int age_;
    int count_dance_ = 0;
};

// Рабочий.
// День рабочего проходит за работой

class Worker : public Person
{
public:
    Worker(const std::string& name, int age)
        :Person(name, age)
    {
    }


    void Dance() override
    {
        Person::Dance();
        if (const int age = GetAge(); age > 30 && age < 40)
        {
            SetSatisfaction(GetSatisfaction() + 1);
        }
    }

    // Увеличивает счётчик сделанной работы на 1, уменьшает удовлетворённость на 5
    void Work()
    {
        SetSatisfaction(GetSatisfaction() - 5);
        ++work_;
    }

    // Возвращает значение счётчика сделанной работы
    int GetWorkDone() const
    {
        return work_;
    }

    void LiveADay() override
    {
        SetSatisfaction(GetSatisfaction() - 5);
        ++work_;
    }

private:
    int work_ = 0;
};

// Студент.
// День студента проходит за учёбой
<<<<<<< HEAD
class Student : public Person
{
public:
    Student(const std::string& name, int age)
        :Person(name, age)
    {
    }



    // Учёба увеличивает уровень знаний на 1, уменьшает уровень удовлетворённости на 3
    void Study()
    {
        SetSatisfaction(GetSatisfaction() - 3);
        ++study_;
    }

    // Возвращает уровень знаний
    int GetKnowledgeLevel() const
    {
        return study_;
    }
    void Dance() override
    {
        Person::Dance();
    }

    // День студента проходит за учёбой
    void LiveADay() override
    { 

        SetSatisfaction(GetSatisfaction() - 3);
        ++study_;
    }

private:
    int study_ = 0;
};
=======
class Student :public Person
{
protected:
    int study_;

public:
    void Dance() const
    {
        cout << name << " is dancing"s << endl;
        satisfaction + 3;
    }
    int GetKnowledgelevel() const
    {
        return study_;
    }
    void LiveADay() const override
    {
        satisfaction - 3;
    }
    Student(const& name, int age)
        :Person(name, age)
    {
    }
    void Study()
    {
        cout << GetName() << " is study"s << endl;
    }
};
>>>>>>> 48ad5b29363b779c2d5007a4890ab469083b2586
