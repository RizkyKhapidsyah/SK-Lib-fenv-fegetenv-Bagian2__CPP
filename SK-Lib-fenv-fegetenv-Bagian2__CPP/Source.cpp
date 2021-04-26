// C++ program to illustrate
// fegetenv() function

/*	Source by GeeksForGeeks 
*	Modified for Learning by Rizky Khapidsyah
*/

#include <iostream>
#include <cfenv>
#include <conio.h>

using namespace std;

// rounding direction mode
void rounding_mode() {
	cout << "Rounding mode is ->";

	switch (fegetround()) {
	case FE_TONEAREST:
		// Round to nearest
		cout << "FE_TONEAREST" << endl;
		break;
	case FE_DOWNWARD:
		// Round downward
		cout << "FE_DOWNWARD" << endl;
		break;
	case FE_UPWARD:
		// Round upward
		cout << "FE_UPWARD" << endl;
		break;
	case FE_TOWARDZERO:
		// Round toward zero
		cout << "FE_TOWARDZERO" << endl;
		break;
	default:
		cout << "unknown" << endl;
	};
}

int main(void) {
	fenv_t envp;

	// initial environment
	cout << "Initial environment :" << endl;

	// print the exception raised initially
	cout << "Exception raised -> \n";
	if (fetestexcept(FE_ALL_EXCEPT)) {
		if (fetestexcept(FE_DIVBYZERO))
			cout << "FE_DIVBYZERO " << endl;
		if (fetestexcept(FE_INEXACT))
			cout << "FE_INEXACT " << endl;
		if (fetestexcept(FE_INVALID))
			cout << "FE_INVALID " << endl;
		if (fetestexcept(FE_OVERFLOW))
			cout << "FE_OVERFLOW " << endl;
		if (fetestexcept(FE_UNDERFLOW))
			cout << "FE_UNDERFLOW " << endl;
	}
	else
		cout << "None" << endl;

	// print the rounding direction mode
	rounding_mode();

	// Current environment
	fegetenv(&envp);
	feraiseexcept(FE_ALL_EXCEPT);

	// Set rounding direction mode
	fesetround(FE_DOWNWARD);

	// after environment is change
	cout << endl
		<< "Final environment :" << endl;

	// print the exception raised
	cout << "Exception raised -> \n";
	if (fetestexcept(FE_ALL_EXCEPT)) {
		if (fetestexcept(FE_DIVBYZERO))
			cout << "FE_DIVBYZERO " << endl;
		if (fetestexcept(FE_INEXACT))
			cout << "FE_INEXACT " << endl;
		if (fetestexcept(FE_INVALID))
			cout << "FE_INVALID " << endl;
		if (fetestexcept(FE_OVERFLOW))
			cout << "FE_OVERFLOW " << endl;
		if (fetestexcept(FE_UNDERFLOW))
			cout << "FE_UNDERFLOW " << endl;
	}
	else
		cout << "None" << endl;

	// print the rounding direction mode
	rounding_mode();

	_getch();
	return 0;
}
