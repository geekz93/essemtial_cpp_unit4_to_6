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

istream& operator>>(istream& is, UserProfile& rhs)
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
	return is;
}

void UserProfile::prcentage_correct() const
{
	//使用三目运算符
	// int除int 小于 1时结果总为0，因此需要进行类型转换
	_prcentage_correct = _guess_count ? 
		(double)_correct_guess / _guess_count : 0.0;
}

void UserProfile::_init_level()
{
	_level_map["beginner"] = beginner;
	_level_map["intermedia"] = intermedia;
	_level_map["advance"] = advance;
	_level_map["guru"] = guru;
}

string UserProfile::get_current_level()
{//限定只有四个等级
	if ( _level_map.empty() )
		_init_level();

	string level_table[] = { "beginner",
		"intermedia", "advance", "guru" };

	map<string, uLevel>::iterator it;
	uLevel level;
	level = ((it = _level_map.find(_current_level)) != _level_map.end()) ?
		it->second : beginner;
	return level_table[level];
}