#include"ForwardList.h"
#include"ForwardList.cpp"


//#define BASE_CHECK
//#define SIZE_CHECK
//#define HOME_WORK_1
//#define COPY_SEMANTIC_CHECK
//#define PERFORMANCE_CHECK
//#define MOVE_SEMANTIC_CHECK
//#define RANGE_BASED_FOR_ARRAY
//#define RANGE_BASED_FOR_LIST


void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello ForwardList" << endl;

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	//list.push_back(123);
	//list.pop_front();
	//list.pop_back();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(value, index);
	list.print();
#endif // BASE_CHECK

#ifdef SIZE_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);

	list1.print();
	list2.print();
#endif // SIZE_CHECK

#ifdef HOME_WORK_1
	ForwardList list(5);  //Implicit conversion from 'int' to 'ForwardList'
	//Неявное преобразование из 'int' в 'ForwardList'
	list.print();
	for (int i = 0; i < list.get_size(); i++)
	{
		list[i] = rand() % 100;
	}
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << list[i] << tab;
	}
	cout << endl;
#endif // HOME_WORK_1

#ifdef COPY_SEMANTIC_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	list1 = list1;
	list1.print();

	ForwardList list2 = list1; //CopyConstructor
	//ForwardList list2;
//I-value = r-value
	list2 = list1;		//CopyAssigment
	list2.print();
#endif // COPY_SEMANTIC_CHECK

#ifdef PERFORMANCE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list1;
	clock_t start = clock();  //Функция 'clock()' возвращает кол-во тактов и мы сохраняем его в переменную 'start'.
	for (int i = 0; i < n; i++);
	{
		list1.push_front(rand() % 100);
		//list1.push_back(rand() % 100);
	}
	clock_t end = clock();  //Сохраняем кол-во тактов потраченных на заполнение списка.
	//Теперь разность замеров 'start' и 'end' (end - start) - это время, потраченное на заполнение списка в тактах
	//Для того чтобы определить время в секунду, нужно промежуток времени в тактах разделить на количество тактов в 1 секунду
	//list1.print();
	cout << delimiter << endl;
	cout << "list1 заполнен за " << double(end - start) / CLOCKS_PER_SEC << "секунд" << endl;
	cout << delimiter << endl;
	system("PAUSE");
	start = clock();
	ForwardList list2 = list1;
	end = clock();
	cout << delimiter << endl;
	cout << "list2 скопирован за " << double(end - start) / CLOCKS_PER_SEC << "секунд" << endl;
	cout << delimiter << endl;
	//list2.print();
#endif // PERFORMANCE_CHECK

#ifdef MOVE_SEMANTIC_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);

	cout << delimiter << endl;
	ForwardList list3 = list1 + list2;
	cout << delimiter << endl;
	list3.print();
#endif // MOVE_SEMANTIC_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	//Range-based for (for для контейнеров)
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY
#ifdef RANGE_BASED_FOR_LIST

	ForwardList list = { 3,5,8,13,21 };
	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	for (Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_LIST

	//Shallow Copy:
		/*this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		other.size = 0;*/

	ForwardList<int> list1 = { 3, 5, 8,13, 21 };
	ForwardList<int> list2 = { 34,55,89 };
	ForwardList<int> list3 = list1 + list2;
	for (int i : list1) cout << i << tab; cout << endl;
	for (int i : list2) cout << i << tab; cout << endl;
	for (int i : list3) cout << i << tab; cout << endl;
	cout << delimiter << endl;

	//TODO: need check on different types

	ForwardList<double> d_list_1 = { 2.7, 3.14, 1.8, 5.2 };
	ForwardList<double> d_list_2 = { 8.33, 9.11, 7.55 };
	ForwardList<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_1)cout << i << tab; cout << endl;
	for (double i : d_list_2)cout << i << tab; cout << endl;
	for (double i : d_list_3)cout << i << tab; cout << endl;

	ForwardList<std::string> s_list_1 = { "Хорошо", "живет", "на", "Винни", "Пух" };
	ForwardList<std::string> s_list_2 = { "И", "Пятачек", "тоже" };
	ForwardList<std::string> s_list_3 = s_list_1 + s_list_2;
	for (std::string i : s_list_1)cout << i << tab; cout << endl;
	for (std::string i : s_list_2)cout << i << tab; cout << endl;
	for (std::string i : s_list_3)cout << i << tab; cout << endl;


	////1) Создаём добавляемый элемент:
	//	//Element* New = new Element(Data);
	//	//2) Пристыковать новый элемент к началу списка:
	//	//New->pNext = Head;
	////3) Смещаем голову на новый элемент:
	//	//Head = New;
	////1) Создаем новый элемент:
	//	//Element* New = new Element(Data);
	////2) Доходим до нужного элемента:
	////Element<T>* Temp = Head;
	////for (int i = 0; i < Index - 1; i++)
	////{
	////	if (Temp->pNext == nullptr)break;
	////	Temp = Temp->pNext;
	////}
	////3) Добавляем элемент в список:
	////New->pNext = Temp->pNext;
	////Temp->pNext = New;
	////Temp->pNext = new Element<T>(Data, Temp->pNext);
	////size++;
	////1) Запоминаем адрес удаленного элемента:
	////Element<T>* Erased = Head;
	////2) Смещаем голову на след. элемент:
	////Head = Head->pNext;
	////3) Удвляем удаляемый элемент памяти:
	////delete Erased;

	////Element* Temp = Head; //Temp - это итератор.
	//	//Итератор - это указатель, при помощи которого можно перемещаться по элементам структуры данных.
	//	//while (Temp)
	//	//{
	//	//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	//	//	Temp = Temp->pNext; //Важно! Переход на след. элемент. выполняется до тех пор, пока не уйдёт в ноль
	//	//}
	//for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
	//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	//cout << "Количество элементов списка: " << size << endl;
	//cout << "Общее количество элементов: " << Element<T>::count << endl;
	////cout << "Общее количество элементов: " << Head->count << endl;
}
