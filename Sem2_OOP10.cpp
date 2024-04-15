#include "file_work.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int length;
    do
    {
        cout << "Введите количество элементов в файле: ";
        cin >> length;
    } while (length <= 0);

    WriteAFile(length);

    bool should_stop = false;

    while (!should_stop)
    {
        cout << endl << endl;
        cout << "1 - перезаписать файл\n2 - удалить все записи, меньше заданной пары\n3 - увеличить все записи на L\n4 - вставить после определенного номера k элементов\n5 - распечатать файл в консоль\n6 - закончить работу программы" << endl;

        int choice;
        cin >> choice;

        Pair comparePair;
        double L;
        int position, k;

        switch (choice)
        {
        case 1:
            do
            {
                cout << "Введите количество элементов в файле: ";
                cin >> length;
            } while (length <= 0);

            WriteAFile(length);
            break;

        case 2:
            cout << "Введите пару, с которой будут сравниваться элементы файла: ";
            cin >> comparePair;

            RemoveAllLesserPair(comparePair);
            break;

        case 3:
            cout << "Введите значение L: ";
            cin >> L;

            AddLToPairs(L);
            break;

        case 4:
            cout << "Введите номер и количество элементов k: ";
            cin >> position >> k;

            AddKMorePairs(position, k);
            break;

        case 5:
            PrintAFile();
            break;

        case 6:
            should_stop = true;
            break;

        default:
            cout << "Невалидное число!" << endl;
            break;
        }
    }

    return 0;
}
