#include "user_profile.h"

UserProfile::UserProfile()
:_log_count(1), _guess_count(0), _correct_guess(0), 
_prcentage_correct(0), _current_level("beginner")
{
	_player = "guest";
}

UserProfile::UserProfile(string user_name, string level)
:_player(user_name), _current_level(level), _log_count(1),
_guess_count(0), _correct_guess(0), _prcentage_correct(0)
{}

ostream& operator<<(ostream& os, UserProfile& rhs)
{
	rhs.prcentage_correct();
	os << rhs.get_player() << ' '
		<< rhs.get_current_level() << ' '
		<< rhs.get_log_count() << ' '
		<< rhs.get_guess_count() << ' '
		<< rhs.get_correct_guess() << ' '
		<< rhs.get_precentage() << endl;
	return os;
}

void operator>>(istream& is, UserProfile& rhs)
{
	string name, level;
	int log_count, guess_count, correct_guess;
	is >> name >> level >> log_count
		>> guess_count >> correct_guess;
	rhs.set_player(name);
	rhs.set_current(level);
	rhs.set_log_count(log_count);
	rhs.set_guess_count(guess_count);
	rhs.set_correct_guess(correct_guess);
	rhs.prcentage_correct();

}

void UserProfile::prcentage_correct() const
{
	if (0 == _guess_count)
	{
		_prcentage_correct = 0;
		return;
	}
	// int除int 小于 1时结果总为0，因此需要进行类型转换
	_prcentage_correct = (double)_correct_guess / _guess_count;
}