#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool pred(std::string const& a, std::string const& b)
{
	return a > b;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> arr;
	std::vector<int> mass;

	for (size_t i = 0; i < n; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return std::tolower(c); });

		auto f = std::find(arr.begin(), arr.end(), tmp);
		if (f == arr.end()) {
			arr.emplace_back(tmp);
			mass.emplace_back(1);
		}
		else {
			mass[std::distance(arr.begin(), f)]++;
		}
	}

	int num = 0;
	for (size_t i = 0; i < mass.size(); i++)
	{
		if (mass[i] > mass[num])
		{
			num = i;
		}
	}

	std::cout << arr[num] << ' ' << mass[num];

	return 0;
}