#ifndef _USER_PROFILE_H
#define _USER_PROFILE_H

#include<string>
#include<iostream>
#include<map>
using namespace std;
////////////////////////////////////
//问题:
//如何储存名字和对应的信息？
//
//
////////////////////////////////////
class UserProfile
{
public:
	enum uLevel{ beginner, intermedia, advance, guru };

	UserProfile();
	UserProfile(string user_name, string level);

	//get user's information
	string get_player() const{ return _player; }
	string get_current_level();
	int get_log_count() const{ return _log_count; }
	int get_guess_count() const{ return _guess_count; }
	int get_correct_guess() const{ return _correct_guess; }
	double get_precentage() const{ return _prcentage_correct; }

	//set user's info
	void set_player(string name) { _player = name; }
	void set_current(string level) { _current_level = level; }
	void set_log_count(int val) { _log_count = val; }
	void set_guess_count(int val) { _guess_count = val; }
	void set_correct_guess(int val) { _correct_guess = val; }
	void prcentage_correct() const;

	//updata info
	void log(){ _log_count++; }
	void guess(){ _guess_count++; }
	void correct_guess(){ _correct_guess++; }

private:
	map<string, uLevel> _level_map; //使用字典储存用户等级
	void _init_level();
	string _player;
	int _log_count;
	int _guess_count;
	int _correct_guess;
	string _current_level;//beginner, intermediate, advance, guru
	mutable double _prcentage_correct;

};

ostream& operator<<(ostream& os, UserProfile& rhs);
istream& operator>>(istream& is, UserProfile& rhs);

#endif