#include"user_profile.h"
#include<iostream>
using namespace std;
int main()
{
	UserProfile ann;
	cin >> ann;
	cout << ann;
	ann.guess();
	ann.correct_guess();
	cout << ann;
	return 0;
}