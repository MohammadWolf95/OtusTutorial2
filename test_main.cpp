#include "filter.h"

#define BOOST_TEST_MODULE test_main 

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

//Тест для проверки нахождения ip адресов, у которых 1-ый байт равен 1
BOOST_AUTO_TEST_CASE(Filter_1_byte){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"1","7","1","1"},
										{"4","6","10","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"1","7","1","1"},
										{"1","60","10","1"}
									};
	//Что бы проверить равенство векторов, у которых одинаковые элементы, но упорядочены
	//не по порядку, надо сначала их отсортировать
	sort(result.begin(), result.end());

	//проверяем нашу функцию
	vector<vector<string>> vec1 = filter(pool_ip, 1);

	//сортируем результируемый вектор
	sotr(vec1.begin(), vec1.end());

	BOOST_CHECK_EQUAL(vec1, result);
}

//Тест для проверки нахождения ip адресов, у которых 1-ый байт и 2-ой байт равны 100 и 10
//соответственно
BOOST_AUTO_TEST_CASE(Filter_1_2_bytes){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"100","10","1","1"},
										{"4","6","10","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"100","10","6","7"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"100","10","1","1"},
										{"100","10","6","7"}
									};
	//Что бы проверить равенство векторов, у которых одинаковые элементы, но упорядочены
	//не по порядку, надо сначала их отсортировать
	sort(result.begin(), result.end());

	//проверяем нашу функцию
	vector<vector<string>> vec1 = filter(pool_ip, 100,10);

	//сортируем результируемый вектор
	sotr(vec1.begin(), vec1.end());

	BOOST_CHECK_EQUAL(vec1, result);
}

//Тест для проверки нахождения ip адресов, у которых 1-ый байт, 2-ой
//и 3-ий байты равны 7, 10 и 4 соответственно
BOOST_AUTO_TEST_CASE(Filter_1_2_3_bytes){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"100","10","1","1"},
										{"7","10","4","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"100","10","6","7"},
										{"7","10","4","66"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"7","10","4","1"},
										{"7","10","4","66"}
									};
	//Что бы проверить равенство векторов, у которых одинаковые элементы, но упорядочены
	//не по порядку, надо сначала их отсортировать
	sort(result.begin(), result.end());

	//проверяем нашу функцию
	vector<vector<string>> vec1 = filter(pool_ip, 7,10, 4);

	//сортируем результируемый вектор
	sotr(vec1.begin(), vec1.end());

	BOOST_CHECK_EQUAL(vec1, result);
}

//Тест для проверки нахождения ip адреса
BOOST_AUTO_TEST_CASE(Find_ip){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"100","10","1","1"},
										{"7","10","4","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"100","10","6","7"},
										{"7","10","4","66"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"7","10","4","1"},
									};
	//Что бы проверить равенство векторов, у которых одинаковые элементы, но упорядочены
	//не по порядку, надо сначала их отсортировать
	sort(result.begin(), result.end());

	//проверяем нашу функцию
	vector<vector<string>> vec1 = filter(pool_ip, 7, 10, 4, 1);

	//сортируем результируемый вектор
	sotr(vec1.begin(), vec1.end());

	BOOST_CHECK_EQUAL(vec1, result);
}

//Тест для проверки компаратора для функции qsort
BOOST_AUTO_TEST_CASE(Compare){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"100","10","1","1"},
										{"7","10","4","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"100","10","6","7"},
										{"7","10","4","66"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"0","6","10","1"},
										{"1","60","10","1"},
										{"7","10","4","1"},
										{"7","10","4","66"},
										{"8","4","3","200"},
										{"15","2","4","7"},
										{"100","10","1","1"},
										{"100","10","6","7"},
									};

	//проверяем нашу функцию
	qsort(&pool_ip[0], pool_ip.size(), sizeof(vector<string>), compare);

	BOOST_CHECK_EQUAL(pool_ip, result);
}

//Тест для проверки функции filter_any. Находим ip адреса, где присутствует байт, равный 1
BOOST_AUTO_TEST_CASE(Filter_any){
	vector<vector<string>>pool_ip = {	
										{"0","6","10","1"},
										{"100","10","1","1"},
										{"7","10","4","1"},
										{"1","60","10","1"},
										{"15","2","4","7"},
										{"100","10","6","7"},
										{"7","10","4","66"},
										{"8","4","3","200"}
									};

	vector<vector<string>>result = {	
										{"0","6","10","1"},
										{"1","60","10","1"},
										{"7","10","4","1"},
										{"100","10","1","1"},
									};

	sort(result.begin(), result.end());

	//проверяем нашу функцию
	vector<vector<string>>vec1 = filter_any(ip_pool, 1);

	sort(vec1.begin(), vec1.end());

	BOOST_CHECK_EQUAL(vec1, result);
}