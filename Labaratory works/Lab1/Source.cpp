#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <math.h>
#include <cmath>
#include "windows.h"
#define endl cout<<"\n";
using namespace std;


class Print
{
public:
    static void print_in_all_codes(vector<bool> first, vector<bool>second, vector<bool>third, int figure)
    {
        if (figure > 0)
        {
            cout << "Number  " << figure << " in binary representation:\n";
        }
        else
        {
            cout << "Number " << figure << " in binary representation:\n";
        }
        cout << "In straight code: ";
        print_result(first);

        cout << "In backward code: ";
        print_result(second);

        cout << "In addition code: ";
        print_result(third);
    }

    static void print_result_operations(vector<bool> first, vector<bool> second, vector<bool> third, int num1, int num2)
    {
        cout << "Summation numbers " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
        cout << "In straight code: ";
        print_result_revers(first);
        cout << "In backward code: ";
        print_result_revers(second);
        cout << "In addition code: ";
        print_result_revers(third);

        endl

    }

    static void print_result(const vector<bool>& vr)
    {
        for (auto i : vr)
        {
            cout << i;
        }

        endl
    }

    static void print_result_revers(vector<bool> vr)
    {
        for (int i = vr.size() - 1; i >= 0; i--)
        {
            cout << vr[i];
        }

        endl
    }

    static void print_multiplications(const deque<bool>& dq)
    {
        for (auto i : dq)
        {
            cout << i;
        }
        endl
    }

    static void print_result_multiplications(deque<bool> first, deque<bool> second, deque<bool> third, int num1, int num2)
    {
        cout << "Multiplications numbers " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
        cout << "In straight code: ";
        print_multiplications(first);
        cout << "In backward code: ";
        print_multiplications(second);
        cout << "In addition code: ";
        print_multiplications(third);
        endl
    }

    static void print_result_deviding(deque<bool> first, deque<bool> second, int num1, int num2)
    {

        cout << "Deviding numbers " << num1 << " / " << num2 << "\n";
        if (num1 < 0 && num2 > 0 || num1 > 0 && num2 < 0) cout << "-";


        print_deviding(first);
        cout << ",";
        print_deviding(second);

        endl

            endl
    }

    static void print_deviding(const deque<bool>& dq)
    {

        for (auto i : dq)
        {
            cout << i;
        }

    }

    static void result_summation_floating_point_numbers(deque<bool> deq, int point, float num1, float num2)
    {
        cout << "Summation floating numbers " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";

        for (int i = 0; i < deq.size(); i++)
        {
            if (i == deq.size() - point && point != 0) cout << ",";
            cout << deq[i];
        }



        endl
    }

};

class Numbers 
{
    friend class Print;
public:

    Numbers();

    Numbers(float num, int bit)
    {
        numbr = num;
        bit_depth = bit;
        converting_to_binary((int)num);
    }

    vector<bool> get_direct_vector()
    {
        return direct;
    }

    vector<bool> get_backward_vector()
    {
        return backward;
    }

    vector<bool> get_additional_vector()
    {
        return  additional;
    }

    vector<bool> get_result_direct_vector()
    {
        return  result_direct;
    }

    vector<bool> get_result_backward_vector()
    {
        return  result_backward;
    }

    vector<bool> get_result_additional_vector()
    {
        return  result_additional;
    }

    deque<bool> get_result_direct_multiplication_vector()
    {
        return  result_multiplication_direct;
    }

    deque<bool> get_result_backward_multiplication_vector()
    {
        return  result_multiplication_backward;
    }

    deque<bool> get_result_additional_multiplication_vector()
    {
        return  result_multiplication_additional;
    }

    deque<bool> get_result_direct_deviding_vector()
    {
        return  result_division_int;
    }

    deque<bool> get_result_direct_deviding_vector_FP()
    {
        return  result_division_float;
    }

    deque<bool> get_result_summation_FP()
    {
        return result_summation_FP;
    }

    int Get_deqree_numbers()
    {
        return deqree_numbers;
    }

    float get_numbr()
    {
        return numbr;
    }

    int get_point()
    {
        return point;
    }

    void converting_to_binary(int number)
    {
        bool isPositiveNumber = true;
        int Dec_number = number;
        stack<int> steck;

        if (number < 0)
        {
            number = abs(number);
            isPositiveNumber = false;
        }

        while (number >= 1)
        {
            steck.push(number % 2);
            number = number / DIVIDER;

        }

        if (steck.size() < bit_depth)
        {
            for (int i = 0; i < bit_depth - steck.size(); i++)
            {
                direct.push_back(0);
            }
        }

        while (!steck.empty())
        {
            direct.push_back(steck.top());
            steck.pop();
        }

        if (isPositiveNumber)
        {
            backward = direct;
            additional = direct;
        }

        else
        {
            backward = direct;
            convertin_to_backward();
            additional = backward;
            convertin_to_additional(bit_depth);
        }

        endl

    }

    void convertin_to_backward()
    {
        for (int i = 0; i < backward.size(); i++)
        {
            if (backward[i] == 0) backward[i] = 1;
            else backward[i] = 0;

        }
    }

   void  conveting_to_backward_division()
    {
        for (int i = 0; i < second_number_dividing_additional.size(); i++)
        {
            if (second_number_dividing_additional[i] == 0) second_number_dividing_additional[i] = 1;
            else second_number_dividing_additional[i] = 0;

        }
    }

    int convertin_to_additional(int n)
    {
        n--;
        if (n == 0)
        {
            if (additional[0] == 0) additional[0] = 1;
            else
            {
                additional[0] = 0;
                additional[7] = 1;
            }
        }
        if (additional[n] == 0)
        {
            additional[n] = 1;
            return NULL;
        }
        else
        {
            additional[n] = 0;
            return convertin_to_additional(n);

        }
    }

    int convertin_to_additional_multiplication(int n)
    {
        n--;
        if (n == 0)
        {
            if (result_multiplication_additional[0] == 0) result_multiplication_additional[0] = 1;
            else
            {
                result_multiplication_additional[0] = 0;
                result_multiplication_additional[7] = 1;
            }
        }
        if (result_multiplication_additional[n] == 0)
        {
            result_multiplication_additional[n] = 1;
            return NULL;
        }
        else
        {
            result_multiplication_additional[n] = 0;
            return convertin_to_additional_multiplication(n);

        }
    }

    int backward_for_summ(int n)
    {
        n++;
        if (n == 7)
        {
            if (result_backward[7] == 0) result_backward[0] = 1;
            else
            {
                result_backward[7] = 0;

            }
        }
        if (result_backward[n] == 0)
        {
            result_backward[n] = 1;
            return NULL;
        }
        else
        {
            result_backward[n] = 0;
            return backward_for_summ(n);

        }
    }

    void reverse_backward_for_direct()
    {
        for (int i = 0; i < result_direct.size(); i++)
        {
            if (result_direct[i] == 0) result_direct[i] = 1;
            else result_direct[i] = 0;

        }
    }

    int convertin_to_additional_deviding(int n)
    {
        n--;
        if (n == 0)
        {
            if (second_number_dividing_additional[0] == 0) second_number_dividing_additional[0] = 1;
            else
            {
                second_number_dividing_additional[0] = 0;
                second_number_dividing_additional[7] = 1;
            }
        }
        if (second_number_dividing_additional[n] == 0)
        {
            second_number_dividing_additional[n] = 1;
            return NULL;
        }
        else
        {
            second_number_dividing_additional[n] = 0;
            return convertin_to_additional_deviding(n);

        }
    }

    void summation_algorithm(deque<bool>& first, deque<bool>& second , deque<bool>& result_summation)
    {
        bool remains = true;
        for (int i = first.size() - 1; i >= 0; i--)
        {

            if (first[i] == 0 && second[i] == 1 && remains || first[i] == 1 && second[i] == 0 && remains)
            {
                result_summation.push_back(1);
                continue;
            }

            else if (first[i] == 0 && second[i] == 1 && remains == false || first[i] == 1 && second[i] == 0 && remains == false)
            {
                result_summation.push_back(0);
                remains = false;
                continue;
            }

            else if (first[i] == 0 && second[i] == 0 && remains)
            {
                result_summation.push_back(0);
                continue;
            }

            else if (first[i] == 0 && second[i] == 0 && remains == false)
            {
                result_summation.push_back(1);
                remains = true;
                continue;
            }

            else if (first[i] == 1 && second[i] == 1 && remains)
            {
                result_summation.push_back(0);
                remains = false;
                continue;
            }

            else
            {
                result_summation.push_back(1);
                remains = false;
                continue;
            }

        }
    }

    const Numbers& operator+(const Numbers& num)
    {
        result_direct.clear();
        result_backward.clear();
        result_additional.clear();
        bool two_positive_numbers = false, remains, two_negative_numbers = false, one_negative = false;
        if (this->numbr > 0 && num.numbr > 0) two_positive_numbers = true;
        if (this->numbr < 0 && num.numbr < 0) two_negative_numbers = true;
        else one_negative = true;
        if (two_positive_numbers)
        {
            remains = true;
            for (int i = this->direct.size() - 1; i >= 0; i--)
            {

                if (this->direct[i] == 0 && num.direct[i] == 1 && remains || this->direct[i] == 1 && num.direct[i] == 0 && remains)
                {
                    result_direct.push_back(1);
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 1 && remains == false || this->direct[i] == 1 && num.direct[i] == 0 && remains == false)
                {
                    result_direct.push_back(0);
                    remains = false;
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 0 && remains)
                {
                    result_direct.push_back(0);
                    continue;
                }

                else if (this->direct[i] == 0 && num.direct[i] == 0 && remains == false)
                {
                    result_direct.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->direct[i] == 1 && num.direct[i] == 1 && remains)
                {
                    result_direct.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_direct.push_back(1);
                    remains = false;
                    continue;
                }

            }
            result_backward = result_direct;
            result_additional = result_direct;

        }

        else
        {
            remains = true;
            for (int i = this->additional.size() - 1; i >= 0; i--)
            {

                if (this->additional[i] == 0 && num.additional[i] == 1 && remains || this->additional[i] == 1 && num.additional[i] == 0 && remains)
                {
                    result_additional.push_back(1);
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 1 && remains == false || this->additional[i] == 1 && num.additional[i] == 0 && remains == false)
                {
                    result_additional.push_back(0);
                    remains = false;
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 0 && remains)
                {
                    result_additional.push_back(0);
                    continue;
                }

                else if (this->additional[i] == 0 && num.additional[i] == 0 && remains == false)
                {
                    result_additional.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->additional[i] == 1 && num.additional[i] == 1 && remains)
                {
                    result_additional.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_additional.push_back(1);
                    remains = false;
                    continue;
                }

            }

            //backward
            remains = true;
            for (int i = this->backward.size() - 1; i >= 0; i--)
            {

                if (this->backward[i] == 0 && num.backward[i] == 1 && remains || this->backward[i] == 1 && num.backward[i] == 0 && remains)
                {
                    result_backward.push_back(1);
                    continue;
                }

                else if (this->backward[i] == 0 && num.backward[i] == 1 && remains == false || this->backward[i] == 1 && num.backward[i] == 0 && remains == false)
                {
                    result_backward.push_back(0);
                    remains = false;
                    continue;
                }

                else if (this->backward[i] == 0 && num.backward[i] == 0 && remains)
                {
                    result_backward.push_back(0);
                    continue;
                }

                else if (this->backward[i] == 0 && num.backward[i] == 0 && remains == false)
                {
                    result_backward.push_back(1);
                    remains = true;
                    continue;
                }

                else if (this->backward[i] == 1 && num.backward[i] == 1 && remains)
                {
                    result_backward.push_back(0);
                    remains = false;
                    continue;
                }

                else
                {
                    result_backward.push_back(1);
                    remains = false;
                    continue;
                }

            }

            if (one_negative)
            {
                if (numbr + num.numbr > 0)
                {
                    result_backward = result_additional;
                    result_direct = result_additional;
                }
                else
                {

                    result_direct = result_backward;
                    reverse_backward_for_direct();
                }
            }
            else
            {
                backward_for_summ(-1);
                result_direct = result_backward;
                reverse_backward_for_direct();
                //direct
            }
        }

        return *this;
    }

    const Numbers& operator*(const Numbers& num)
    {
        deque<int> first_sum;
        first_sum.clear();
        int counter = 0;
        result_multiplication_direct.clear();
        result_multiplication_backward.clear();
        result_multiplication_additional.clear();
        bool remains, one_negative_numbr = false;
        if (numbr < 0 || num.numbr < 0) one_negative_numbr = true;
        if (numbr < 0 && num.numbr < 0) one_negative_numbr = false;

        for (int i = 0; i < bit_depth; i++)
        {
            result_multiplication_direct.push_back(0);
        }

        for (int i = this->direct.size() - 1; i >= 0; i--)
        {

            if (num.direct[i] == 1)
            {
                first_sum.clear();


                for (int j = direct.size() - 1; j >= 0; j--)
                {

                    if (direct[j] == 1) first_sum.push_front(1);
                    else first_sum.push_front(0);

                }

                for (int q = 0; q < counter; q++)
                {
                    first_sum.push_back(0);
                    first_sum.pop_front();
                }
                remains = true;
                for (int i = first_sum.size() - 1; i >= 0; i--)
                {

                    if (first_sum[i] == 0 && result_multiplication_direct[i] == 1 && remains || first_sum[i] == 1 && result_multiplication_direct[i] == 0 && remains)
                    {
                        result_multiplication_direct[i] = 1;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 1 && remains == false || first_sum[i] == 1 && result_multiplication_direct[i] == 0 && remains == false)
                    {
                        result_multiplication_direct[i] = 0;
                        remains = false;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 0 && remains)
                    {
                        result_multiplication_direct[i] = 0;
                        continue;
                    }

                    else if (first_sum[i] == 0 && result_multiplication_direct[i] == 0 && remains == false)
                    {
                        result_multiplication_direct[i] = 1;
                        remains = true;
                        continue;
                    }

                    else if (first_sum[i] == 1 && result_multiplication_direct[i] == 1 && remains)
                    {
                        result_multiplication_direct[i] = 0;
                        remains = false;
                        continue;
                    }

                    else
                    {
                        result_multiplication_direct[i] = 1;
                        remains = false;
                        continue;
                    }

                }
                counter++;
            }

            else counter++;
        }

        if (one_negative_numbr)
        {

            result_multiplication_backward = result_multiplication_direct;

            for (int i = 0; i < result_multiplication_backward.size(); i++)
            {
                if (result_multiplication_backward[i] == 0) result_multiplication_backward[i] = 1;
                else result_multiplication_backward[i] = 0;

            }

            result_multiplication_additional = result_multiplication_backward;
            convertin_to_additional_multiplication(bit_depth);
        }

        else
        {

            result_multiplication_backward = result_multiplication_direct;
            result_multiplication_additional = result_multiplication_backward;
        }


        return *this;
    }

    const Numbers& operator/(const Numbers& num)
    {
        
        result_division_int.clear();
        int first_number = abs(numbr), num1 = abs(numbr);
        int second_numbr = abs(num.numbr), num2 = abs(num.numbr);
        bool stop = true, equals = false;
        if (num1 == num2)  equals = true;
       

        deque<bool> first_number_for_deviding, second_number_for_deviding;
        while (first_number >= 1)
        {
            first_number_for_deviding.push_front(first_number % 2);
            first_number = first_number / DIVIDER;
        }

        while (second_numbr >= 1)
        {
            second_number_for_deviding.push_front(second_numbr % 2);
            second_numbr = second_numbr / DIVIDER;
        }

        second_number_dividing_additional = second_number_for_deviding;
        conveting_to_backward_division();
        convertin_to_additional_deviding(second_number_dividing_additional.size());

          
            bool trigger = false, null,remains, surplace=false;
            int iterator = 0, count;
            
            if (equals)
            {
                for (int i = 0; i < bit_depth; i++)
                {
                    if (i == 0) result_division_int.push_front(1);
                    else result_division_int.push_front(0);
                }
            }
            else
            {
                while (true)
                {
                    null = false;
                    count = 0;

                    for (int i = 0; i < first_number_for_deviding.size(); i++)  //������� ���� �������� ������ ���� � ������ ������ ���������� � ���������
                    {
                        if (first_number_for_deviding[i] == 0) count++;
                    }

                    if (count == first_number_for_deviding.size()) null = true;

                    if (null)//������� ����� �����
                    {
                        while (count != 0)
                        {
                            result_division_int.push_back(0);
                            count--;
                        }

                        break;
                    }

                    if (first_number_for_deviding.size() < second_number_for_deviding.size()) //�������� � ����������� �������� && surplace
                    {
                        int stopper = 0;
                        result_division_float.clear();
                        for (int i = 0; i < second_number_for_deviding.size() - first_number_for_deviding.size(); i++)
                        {
                            result_division_float.push_back(0);
                        }
                       
                            for (int i = 0; i < first_number_for_deviding.size(); i++)
                            {
                              
                                result_division_float.push_back(first_number_for_deviding[i]);
                            }
                            
                            if (result_division_float.size() < 5)
                            {
                                for (int i = 0; i < result_division_float.size() - 5; i++)
                                {
                                    result_division_float.push_back(0);
                                }
                            }
                            else
                            {
                              
                                
                                for ( int i = 0; i < result_division_float.size() - 5; i++)
                                {
                                    result_division_float.pop_back();
                                }
                            }
                        
                        break;
                    }

                    if (first_number_for_deviding.size() >= second_number_for_deviding.size())  //������ ����� ���������� ����� ��� ����������� �� ����������&& first_in
                    {
                        //first_in = false;
                        surplace = true;
                        result_division_int.push_back(1);
                        remains = true;
                        for (int i = second_number_for_deviding.size() - 1; i >= 0; i--)
                        {
                            if (first_number_for_deviding[i] == 0 && second_number_dividing_additional[i] == 1 && remains || first_number_for_deviding[i] == 1 && second_number_dividing_additional[i] == 0 && remains)
                            {
                                first_number_for_deviding[i] = 1;
                                continue;
                            }

                            else if (first_number_for_deviding[i] == 0 && second_number_dividing_additional[i] == 1 && remains == false || first_number_for_deviding[i] == 1 && second_number_dividing_additional[i] == 0 && remains == false)
                            {
                                first_number_for_deviding[i] = 0;
                                remains = false;
                                continue;
                            }

                            else if (first_number_for_deviding[i] == 0 && second_number_dividing_additional[i] == 0 && remains)
                            {
                                first_number_for_deviding[i] = 0;
                                continue;
                            }

                            else if (first_number_for_deviding[i] == 0 && second_number_dividing_additional[i] == 0 && remains == false)
                            {
                                first_number_for_deviding[i] = 1;
                                remains = true;
                                continue;
                            }

                            else if (first_number_for_deviding[i] == 1 && second_number_dividing_additional[i] == 1 && remains)
                            {
                                first_number_for_deviding[i] = 0;
                                remains = false;
                                continue;
                            }

                            else
                            {
                                first_number_for_deviding[i] = 1;
                                remains = false;
                                continue;
                            }

                        }

                        count = 0;
                        for (int i = 0; i < second_number_dividing_additional.size(); i++)
                        {

                            if (first_number_for_deviding[0] == 0) first_number_for_deviding.pop_front();
                            else break;
                            count++;
                        }

                        count = second_number_dividing_additional.size() - (count + 1);
                        if (count >= 0)
                        {
                            for (int i = 0; i < count; i++)
                            {
                                result_division_int.push_back(0);
                            }
                        }

                    }

                }
            }
       

       if (result_division_int.size() < bit_depth)
        {
            int bit_size = bit_depth - result_division_int.size();
            for (int i = 0; i < bit_size; i++)
            {
                result_division_int.push_front(0);
            }
        }
        

        return *this;
    }

    const Numbers& summation_two_float_numbers(const Numbers& num)
    {
        result_summation_FP.clear();
        deque<bool> number_first, number_second;
        float num1 = numbr, num2 = num.numbr , num1_int, num2_int, num1_float, num2_float;
        bool remains;
        num1_float = modf(num1, &num1_int);
        num2_float = modf(num2, &num2_int);

        
        while (num1_int >= 1)
        {
            number_first.push_front((int)num1_int % 2);
            num1_int = num1_int / DIVIDER;
        }

        if (num1_float != 0)
        {
            while (num1_float < 1)
            {
                number_first.push_back((int)(num1_float * 2));
                num1_float = num1_float * DIVIDER;
                point++;
            }
        }
     
        while (num2_int >= 1)
        {
            number_second.push_front((int)num2_int % 2);
            num2_int = num2_int / DIVIDER;
        }

        deqree_numbers = number_second.size();
        if (num2_float != 0)
        {
            while (num2_float < 1)
            {
                number_second.push_back((int)(num2_float * 2));
                num2_float = num2_float * DIVIDER;
                point++;
            }
        }

        if (number_first.size() < bit_depth)
        {
             
            while (number_first.size() != bit_depth)
            {
                number_first.push_front(0);
            }
        }

        if ( number_second.size() < bit_depth)
        {
            while (number_second.size() != bit_depth)
            {
                number_second.push_front(0);
            }
        }

        point = point / DIVIDER;

        remains = true;
        for (int i = number_first.size() - 1; i >= 0; i--)
        {

            if (number_first[i] == 0 && number_second[i] == 1 && remains || number_first[i] == 1 && number_second[i] == 0 && remains)
            {
                result_summation_FP.push_front(1);
                continue;
            }

            else if (number_first[i] == 0 && number_second[i] == 1 && remains == false || number_first[i] == 1 && number_second[i] == 0 && remains == false)
            {
                result_summation_FP.push_front(0);
                remains = false;
                continue;
            }

            else if (number_first[i] == 0 && number_second[i] == 0 && remains)
            {
                result_summation_FP.push_front(0);
                continue;
            }

            else if (number_first[i] == 0 && number_second[i] == 0 && remains == false)
            {
                result_summation_FP.push_front(1);
                remains = true;
                continue;
            }

            else if (number_first[i] == 1 && number_second[i] == 1 && remains)
            {
                result_summation_FP.push_front(0);
                remains = false;
                continue;
            }

            else
            {
                result_summation_FP.push_front(1);
                remains = false;
                continue;
            }

        }

        if (result_summation_FP.size() < bit_depth)
        {
            int size = 0;
            size = result_summation_FP.size();
            for (int i = 0; i < bit_depth - size; i++)
            {
                result_summation_FP.push_front(0);
            }
        }

        return *this;
    }

private:
    vector<bool> direct;
    vector<bool> backward;
    vector<bool> additional;
    vector<bool> result_direct;
    vector<bool> result_backward;
    vector<bool> result_additional;
    deque<bool> result_multiplication_direct;
    deque<bool> result_multiplication_backward;
    deque<bool> result_multiplication_additional;
    deque<bool> result_division_int;
    deque<bool>  result_division_float{ 0,0,0,0,0 };
    deque<bool> second_number_dividing_additional;
    deque<bool> result_summation_FP;
    float numbr;
    int bit_depth;
    int deqree_numbers;
    int point;
    const int DIVIDER = 2;
};

void main()
{
    char selector = 'NULL';
    float num1, num2, bit = 16;
    int choose;
    cout << "Input first & second numbers:\n";
    cin >> num1 >> num2; 
    cout << "Input (Y) - if you want change bit_depth or (N) - defolt bit_depth = 16:\n";
    cin >> selector;
    if (selector == 'Y' || selector == 'y')
    {
        cout << "Input bit_depth:\n";
        cin >> bit;
    }

    Numbers x1(num1, bit), x2(num2, bit), x3(-num1, bit), x4(-num2, bit);
    //Print out;
    bool breaker = true;
    system("cls");

    while (breaker)
    { 
    cout << "Select and tape key action| 1 - View binary code, 2 - Operations (+, - , * , /), 3 - briefing, 0 - out:\n";
    cin >> choose;
    switch (choose)
    {

    case 1:
    {
            Print::print_in_all_codes(x1.get_direct_vector(), x1.get_backward_vector(), x1.get_additional_vector(), x1.get_numbr());
        endl
            Print::print_in_all_codes(x2.get_direct_vector(), x2.get_backward_vector(), x2.get_additional_vector(), x2.get_numbr());
        endl
            Print::print_in_all_codes(x3.get_direct_vector(), x3.get_backward_vector(), x3.get_additional_vector(), x3.get_numbr());
        endl
            Print::print_in_all_codes(x4.get_direct_vector(), x4.get_backward_vector(), x4.get_additional_vector(), x4.get_numbr());
        endl
            break;

    }

    case 2:
    {
        int chooce;
        bool repeat = true;
        while (repeat)
        {
            cout << "Select and tape key action|\n1 - Operations (+, -)\n2 - Operatios(| x1 | * | x2 |)\n3 - Operatios(| x1 | / | x2 |)\n4 - Summation Float Numbers\n0 - exit:\n";
            cin >> chooce;
            switch (chooce)
            {
            case 0:
            {
                cout << "Esc to main menu!\n";
                repeat = false;
                break;
            }
            case 1:
            {
                x1 + x2;
                Print::print_result_operations(x1.get_result_direct_vector(), x1.get_result_backward_vector(), x1.get_result_additional_vector(), x1.get_numbr(), x2.get_numbr());
                x2 + x3;
                Print::print_result_operations(x2.get_result_direct_vector(), x2.get_result_backward_vector(), x2.get_result_additional_vector(), x2.get_numbr(), x3.get_numbr());
                x3 + x4;
                Print::print_result_operations(x3.get_result_direct_vector(), x3.get_result_backward_vector(), x3.get_result_additional_vector(), x3.get_numbr(), x4.get_numbr());
                x4 + x1;
                Print::print_result_operations(x4.get_result_direct_vector(), x4.get_result_backward_vector(), x4.get_result_additional_vector(), x4.get_numbr(), x1.get_numbr());
                break;
            }

            case 2:
            {  
                try
                {

                    if (num1 == 0 || num2 == 0) throw 3;
                    x1 * x2;
                    Print::print_result_multiplications(x1.get_result_direct_multiplication_vector(), x1.get_result_backward_multiplication_vector(), x1.get_result_additional_multiplication_vector(), x1.get_numbr(), x2.get_numbr());
                    x2 * x3;
                    Print::print_result_multiplications(x2.get_result_direct_multiplication_vector(), x2.get_result_backward_multiplication_vector(), x2.get_result_additional_multiplication_vector(), x2.get_numbr(), x3.get_numbr());
                    x3 * x4;
                    Print::print_result_multiplications(x3.get_result_direct_multiplication_vector(), x3.get_result_backward_multiplication_vector(), x3.get_result_additional_multiplication_vector(), x3.get_numbr(), x4.get_numbr());
                    x4 * x1;
                    Print::print_result_multiplications(x4.get_result_direct_multiplication_vector(), x4.get_result_backward_multiplication_vector(), x4.get_result_additional_multiplication_vector(), x4.get_numbr(), x1.get_numbr());
                  
                   
                }

                catch (int i)
                {
                    if (i == 3)
                    {
                        deque<bool> null_multiplication;
                        for (int i = 0; i < bit; i++)
                        {
                            null_multiplication.push_back(0);
                        }
                        Print::print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x1.get_numbr(), x2.get_numbr());
                        Print::print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x2.get_numbr(), x3.get_numbr());
                        Print::print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x3.get_numbr(), x4.get_numbr());
                        Print::print_result_multiplications(null_multiplication, null_multiplication, null_multiplication, x4.get_numbr(), x1.get_numbr());
                    }
                }
                
                break;
            }

            case 3:
            {
                try
                {
                    if (num1 !=0 && num2 == 0) throw 1;
                    else if (num1 == 0) throw 2;
                    x1 / x2;
                    Print::print_result_deviding(x1.get_result_direct_deviding_vector(), x1.get_result_direct_deviding_vector_FP(), x1.get_numbr(), x2.get_numbr());
                    x1 / x4;
                    Print::print_result_deviding(x1.get_result_direct_deviding_vector(), x1.get_result_direct_deviding_vector_FP(), x1.get_numbr(), x4.get_numbr());
                    x3 / x2;
                    Print::print_result_deviding(x3.get_result_direct_deviding_vector(), x3.get_result_direct_deviding_vector_FP(), x3.get_numbr(), x2.get_numbr());
                    x3 / x4;     
                    Print::print_result_deviding(x3.get_result_direct_deviding_vector(), x3.get_result_direct_deviding_vector_FP(), x3.get_numbr(), x4.get_numbr());
                }

                catch (int i)
                {
                    if (i == 1) cout << "ERROR!!! " << i << " - DEVISION BY ZERO!!!\n";
                    else 
                    {
                        deque<bool> null_deviding;
                        for (int i = 0; i < bit; i++)
                        {
                            null_deviding.push_back(0);
                        }
                        Print::print_result_deviding(null_deviding, null_deviding, x1.get_numbr(), x2.get_numbr());
                        Print::print_result_deviding(null_deviding, null_deviding, x1.get_numbr(), x4.get_numbr());
                        Print::print_result_deviding(null_deviding, null_deviding, x3.get_numbr(), x4.get_numbr());
                        Print::print_result_deviding(null_deviding, null_deviding, x3.get_numbr(), x2.get_numbr());
                    }
                }
                break;
            }

            case 4:
            {
                x1.summation_two_float_numbers(x2);
                Print::result_summation_floating_point_numbers(x1.get_result_summation_FP(),x1.get_point(), x1.get_numbr(), x2.get_numbr());
                break;
            }

            default:
                cout << "Input no define key\n";
                break;
            }
            system("pause");
            system("cls");

        }
        
        break;
       
    }

    case 3:
    {

        cout << "*****************************************************************\n";
        cout << "*           Welcome to my labaratory work 1 on AOIS!            *\n";
        cout << "*    Next, you will have a few questions to clarify the task.   *\n";
        cout << "*                         Good luck!                            *\n";
        cout << "*****************************************************************\n";
        break;

    }
     
    case 0:
    {
        breaker = false;
        break;
    }

    default:
        cout << "Input no define key\n";
        break;
    }

    system("pause");
    system("cls");

  }

}




