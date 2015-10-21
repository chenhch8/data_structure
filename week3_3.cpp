#include<iostream>
#include<cstring>
#include<stack>

bool Chart(std::string str) {
    std::stack<char> st;
	int i = 0;
	while (i < str.size()) {
	    if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
		    st.push(str[i]);
		} else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
		    if (!st.empty()) {
		        bool if_true = (str[i] == ')') && (st.top() == '(') ||
			    (str[i] == ']') && (st.top() == '[') ||
			    (str[i] == '}') && (st.top() == '{');
			    st.pop();
			    if (!if_true)
			        return false;
			} else return false;
		}
		i++;
	}
	if (st.empty())
	    return true;;
	return false;
}

int main() {
    std::string str;
	int t;
	std::cin >> t;
	std::cin.ignore();
	while (t--) {
	    getline(std::cin, str);
		if (Chart(str))
		    std::cout << "True";
		else std::cout << "False";
		if (t != 0) std::cout << std::endl;
	}
}
