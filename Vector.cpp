#include <iostream>
template<typename T, size_t S>
class Vector
{
public:
	Vector()
	{
		//std::cout << "Added!" << std::endl;
		m_vector = new T[S];
		displacement = 0;
	}
	~Vector()
	{
		//std::cout << "Deleted!" << std::endl;
		delete[] m_vector;
	}
	const size_t size() const { return S + displacement; }
	T& operator[] (int index)
	{
		return m_vector[index];
	}
	void setVector(T*& vector, size_t size)
	{
		delete[] m_vector;
		m_vector = vector;
		displacement = size - S;
	}
	void push_back(T elem)
	{
		displacement++;
		T* newVector = new T[S + displacement];
		std::copy(m_vector, m_vector + S + displacement - 1, newVector);
		delete[] m_vector;
		m_vector = newVector;
		m_vector[S + displacement - 1] = elem;
	}
	void insert_index(int index, T elem)
	{
		if (index > size() - 1)
		{
			std::cout << "Index is too large. If you're trying to insert to the back,\nuse push_back()." << std::endl;
		}
		displacement++;
		T* newVector = new T[S + displacement];
		std::copy(m_vector, m_vector + index, newVector);
		std::copy(m_vector + index, m_vector + S + displacement, newVector + index + 1);
		newVector[index] = elem;
		delete[] m_vector;
		m_vector = newVector;
	}
	void remove(int index)
	{
		if (size() == 0)
		{
			std::cout << "Can't remove any more elements!" << std::endl;
		}
		else if (index > S + displacement - 1 || index < 0)
		{
			std::cout << "Index out of range!" << std::endl;
		}
		else
		{
			displacement--;
			T* newVector = new T[S + displacement];
			std::copy(m_vector, m_vector + index, newVector);
			if (S + displacement != index)
			{
				std::copy(m_vector + index + 1, m_vector + S + displacement + 1, newVector + index);
			}
			delete[] m_vector;
			m_vector = newVector;
		}
	}
	T pop_back()
	{
		if (size() == 0)
		{
			std::cout << "Can't remove any more elements!" << std::endl;
		}
		else
		{
			T last = m_vector[size() - 1];
			remove(size() - 1);
			return last;
		}
	}
private:
	T* m_vector;
	int displacement;
};
