#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct student
{
    int number;
    string name;
    double score[3];
};
struct group
{
    struct student stu[5];
};
int step_input = 0;
void show_menu()
{
    cout << "****************************************\n"
        << "********* 1----input info-----**********\n"
        << "********* 2-show total score--**********\n"
        << "********* 3 rank in descending**********\n"
        << "********* 4 ----exit sys------**********\n"
        << "****************************************\n";
}
void input_info(student* stu, group* gro)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "input your name :";
        cin >> gro->stu[i].name;
        cout << "input your student number :";
        cin >> gro->stu[i].number;
        cout << "input your scores of 3 classes(separated by ENTER) :\t";
        for (int j = 0; j < 3; j++)
        {
            cin >> gro->stu[i].score[j];
        }
        step_input = 1;
    }
    system("cls");
}
float show_sum(student* stu, group* gro, int seq)
{
    return gro->stu[seq].score[0] + gro->stu[seq].score[1] + gro->stu[seq].score[2];
}
// show_sum must be place before show_info
void show_info(student* stu, group* gro)
{
    if (step_input == 1)
    {
        cout << "name\tnumber\tscore1\tscore2\tscore3\tsum\n";
        for (int k = 0; k < 5; k++)
        {
            cout << gro->stu[k].name << "\t" << gro->stu[k].number << "\t" << gro->stu[k].score[0] << "\t" << gro->stu[k].score[0] << "\t" << gro->stu[k].score[2] << "\t" << show_sum(stu, gro, k) << "\n";
        }
    }
    else
    {
        cout << "you haven't input any info yet !";
    }
    system("pause");
    system("cls");
}
void rank_in_order(student* stu, group* gro)
{
    if (step_input == 1)
    {
        sort(gro->stu, gro->stu + 5, [stu, gro](const student& a, const student& b)
            { return show_sum(stu, gro, &a - gro->stu) > show_sum(stu, gro, &b - gro->stu); });
        cout << "Name\tTotal Score\n";
        for (int k = 0; k < 5; k++)
        {
            cout << gro->stu[k].name << "\t" << show_sum(stu, gro, k) << "\n";
        }
    }
    else
    {
        cout << "you haven't input any info yet !";
    }
    system("pause");
    system("cls");
}
int main()
{
    student stu;
    group gro;
    int select;
    while (true)
    {
        show_menu();
        cin >> select;
        switch (select)
        {
        case 1:
            input_info(&stu, &gro);
            break;
        case 2:
            show_info(&stu, &gro);
            break;
        case 3:
            rank_in_order(&stu, &gro);
            break;
        case 4:
            cout << "exit the system successfully\n";
            cout << "name : 左智康\tstudent number : 2312100204";
            return 0;
        default:
            cout << "you should input a number in the menu !\n";
        }
    }
    cout << "name : 左智康\tstudent number : 2312100204";
    system("pause");
    return 0;
}