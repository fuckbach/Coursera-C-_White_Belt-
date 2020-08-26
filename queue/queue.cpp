// queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

	int number_of_operation = 0;
	int current_operation = number_of_operation;
	cin >> number_of_operation;
	int size_of_queue = 0;
	vector <bool> queue(false);
	queue.clear();
	while (current_operation < number_of_operation) {
		vector <string> cmd;
		int num_of_current_command = 0;
		while (num_of_current_command < 2)
		{
			string current_command;
			cin >> current_command;
			cmd.push_back(current_command);
			num_of_current_command++;
			if (current_command == "WORRY_COUNT")
			{
				int tmp = 0;
				for (auto i : queue)
				{
					if (i == true) {
						tmp++;
					}
				}
				cout << tmp << endl;
				break;
			}
		}
		if (cmd[0] == "WORRY") {
			queue[atoi(cmd[1].c_str())] = true;
		}

		else if (cmd[0] == "QUIET") {
			queue[atoi(cmd[1].c_str())] = false;
		}

		else if (cmd[0] == "COME") {
			int tmp = atoi(cmd[1].c_str());
			queue.resize(queue.size() + tmp);
		}
		cmd.clear();
		current_operation++;
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
