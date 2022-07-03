#include <iostream>

template <typename T>
class MyArray
{
	private:
		int m_len;
		T *m_data;
	public:
		MyArray(int len)
		{
			m_data = new T[len];
			m_len = len;
		}

		~MyArray()
		{
			reset();
		}
		
		void reset()
		{
			delete[] m_data;
			m_data = nullptr;
			m_len = 0;
		}

		T &operator[](int index)
		{
			assert (index >= 0 && index < m_len);
			return m_data[index];
		}

		int getLen()
		{
			return m_len;
		}
		void print()
		{
			for (int i=0; i<m_len; i++)
				std::cout << m_data[i] << " ";
			std::cout << std::endl;
		}
};

int main()
{
	MyArray<char> my_array(10);

	for (int i =0; i< my_array.getLen(); ++i)
		my_array[i] = i + 65;

	my_array.print();
	return 0;
}
