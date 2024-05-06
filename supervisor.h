#pragma once

#include "people.h"

/*
    Надзиратель за уровнем удовлетворённости.
    Способен наблюдать за состоянием человека
    Если уровень удовлетворённости человека опустится ниже минимального уровня, Надзиратель
    побуждает человека танцевать до тех пор, пока уровень уровень удовлетворённости
    не станет больше или равен максимальному значению
*/
class SatisfactionSupervisor :public PersonObserver {
    int min_satisfaction_ = 0;
    int max_satisfaction_ = 0;
public:


    // Конструктор принимает значение нижнего и верхнего уровня удовлетворённости
    SatisfactionSupervisor(int min_satisfaction, int max_satisfaction) {
        min_satisfaction_ = min_satisfaction;
        max_satisfaction_ = max_satisfaction;
    }
    void OnSatisfactionChanged(Person& /*person*/a, int /*old_value*/min, int /*new_value*/max) override
    {
        if (a.GetAge() < min_satisfaction_)
        {
            cout << "Satisfaction level is at a minimum, let's dance!!!" << endl;
            while (a.GetAge() >= max_satisfaction_)
            {
                a.Dance();
            }
        }
        else
        {
            cout << "Satisfaction level is normal" << endl;

        }
    }
};
