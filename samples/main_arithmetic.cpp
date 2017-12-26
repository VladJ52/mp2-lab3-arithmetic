// реализация пользовательского приложения

#include "arithmetic.h"
#include "stack.h"

int main()
{
	int h = 1;
	while (h == 1)
	{
		string a;
		cout << "Write" << endl;
		getline(cin, a);
		while (!(iscorrect(a)))
		{
			cout << "Write again" << endl;
			getline(cin, a);
		}
		Stack<Lexem> s1;
		s1 = convertstr(a);
		s1 = polishnot(s1);
			cout << sol(s1) << endl;
			cout << "Repeat?" << endl;
			cout << "1 - yes" << endl;
			cout << "2 - no" << endl;
			cin >> h;
	}
	return 0;
}