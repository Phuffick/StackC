#include <iostream>
#include "classes.h"


int main() {
	Stack st;
	st.append(1);
	st.append(2);
	st.append(3);
	st.append(4);
	st.append(5);

	st.Print();

	st.pop();
	st.pop();
	st.pop();

	st.Print();

	system("pause");
	return 0;
}
