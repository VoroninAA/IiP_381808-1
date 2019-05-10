#pragma once
#pragma once
// Класс вектор для удобного использования динамических массивов
template <typename T>
class MyVector
{
private:
	static const int basic_add = 10; //Стандартное увеличение буфера
	T* elements; // Хранение элементов массива
	int count; // Реальное количество объектов
	int maxcount; //Размер буфера, то есть максимальное число элементов на данный момент
public:
	MyVector();
	MyVector(int size);
	MyVector(const MyVector& _v);
	~MyVector();

	T& operator[](const int &i);
	T& operator[](const int &i) const;
	int GetCount() { return count; };
	void Add(const T& e);// Добавление элемента


};

template<typename T>
MyVector<T>::MyVector()
{
	count = 0;
	maxcount = basic_add;
	elements = new T[basic_add];
}

template<typename T>
MyVector<T>::MyVector(int size)
{
	count = size;
	maxcount = size + basic_add;
	elements = new T[size + basic_add];
}

template<typename T>
MyVector<T>::MyVector(const MyVector & _v)
{
	count = _v.count;
	maxcount = _v.maxcount;
	elements = new T[count + basic_add];
	for (int i = 0; i < maxcount; i++)
		elements[i] = _v.elements[i];
}

template<typename T>
MyVector<T>::~MyVector()
{
	delete[](elements);
	elements = 0;
	count = 0;
	maxcount = 0;
}

template<typename T>
T & MyVector<T>::operator[](const int & i)
{

	return elements[i];
}

template<typename T>
T & MyVector<T>::operator[](const int & i) const
{
	return elements[i];
}

template<typename T>
void MyVector<T>::Add(const T & e)
{
	if (count == maxcount)
		maxcount += basic_add;
	T* tmp;
	tmp = new T[maxcount];
	for (int i = 0; i < count; i++)
		tmp[i] = elements[i];
	delete[](elements);
	elements = new T[maxcount];
	count++;
	for (int i = 0; i < count - 1; i++)
		elements[i] = tmp[i];
	elements[count - 1] = e;
	delete[](tmp);
	tmp = 0;

}

