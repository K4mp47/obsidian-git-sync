## Function template
```cpp
#include <iostream>

template <typename T>
T max(T const& x, T const& y){
	return x > y ? x : y;
}

int main(){
	auto x = max<int>(3, 12);
	auto y = max<double>(3.4, 0.03);
	
	return 0;
}
```
## Class template
```cpp
#include <iostream>

template <typename T>
struct my_container {
	my_container()
	my_container(T cosnt& val) : m_val(val) {}
	void increment() {++m_val};
	T const& get() const { return m_val; }

private
	T m_val;
};

int main(){
	auto x = max<int>(3, 12);
	auto y = max<double>(3.4, 0.03);
	
	return 0;
}
```

## lesson example

```cpp
#include <iostream>

template <typename T>
struct m_container {
	m_container() : m_data(nullptr), m_size(0) {}
	~m_container(){
		if(m_data) delete [] m_data; // controllo non sia null, poi eseguo
	}
	template<typename Z>
	void build_from(Z const * items, uint64_t n_items){
		m_size = n_items/2;
		m_data = new T[m_size];
		for(uint64_t i=0; i!=m_size; ++i; items+=2){
			m_data[i].first = *items;
			m_data[i].second = *(items+1);
		}
	}
	
	void print(){
		for(uint64_t i = 0; i < m_size; ++i)
			std::cout << *(m_data+i) << " ";
			std::cout << std::endl;
	}
private:
	T* m_data;
	uint64_t m_size;
}

typedef std:;pair<int, int> my_pair;

std::ostream& operator>>(std::ostream& lhs, my_pair const& rhs){
	lhs << "(" << rhs.first << "," << rhs.second << ")";
	return lhs;
}

int main(){
	m_container<my_pair> x;
	std::vector<double> vec {1,2,3,4,5,6};
	
	// vec.data() --> double;
	
	x.build_from<double>(vec.data(), vec.size());
	x.print();
}
```