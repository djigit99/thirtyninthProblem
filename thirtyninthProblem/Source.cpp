#include <iostream>

using namespace std;

int** graph;
char* used;
int number_of_verti�es;
bool depth_first_search(int current_vertex, char current_color) {
	used[current_vertex] = current_color;
	for (int index = 0; index < number_of_verti�es; index++) {
		if (graph[current_vertex][index] == 0)
			continue; 
		if (used[index] == 0) {
			/*If we got false in recursive search then return false */
			if (!depth_first_search(index, (current_color == 1 ? 2 : 1)) )
				return false;
		}
		else {
			/*Adjacent vertices has the same colors */
			if (used[index] == current_color)
				return false;
		}
	}
	return true;
}
int main() {
	cin >> number_of_verti�es;
	graph = new int*[number_of_verti�es];
	used = new char[number_of_verti�es];
	for (int indexI = 0; indexI < number_of_verti�es; indexI++) {
		graph[indexI] = new int[number_of_verti�es];
		for (int indexJ = 0; indexJ < number_of_verti�es; indexJ++)
			graph[indexI][indexJ] = 0;
		used[indexI] = 0;
	}
	for (int indexI = 0; indexI < number_of_verti�es; indexI++) {
		for (int indexJ = 0; indexJ < number_of_verti�es; indexJ++) {
			cin >> graph[indexI][indexJ];
		}
	}
	bool ans = true;
	for (int index = 0; index < number_of_verti�es; index++) {
		if (used[index] == 0)
			ans = depth_first_search(index, 1);
		if (!ans)
			break;
	}
	puts(ans ? "YES" : "NO");
	system("pause");
	return 0;
}