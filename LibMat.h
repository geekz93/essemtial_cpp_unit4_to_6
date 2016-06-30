////////////////////////////
//LibMat为基类, Book为LibMat
//的派生类, AudioBook为Book
//的派生类。
//
//为什么析构函数加 virtual
////////////////////////////

#include<iostream>
using namespace std;

class LibMat
{
public:
	LibMat(){ cout << "LibMat::LibMat() constructor\n"; }
	virtual ~LibMat(){ cout << "LibMat::~LibMat() destructor\n"; }
	virtual void print() const{ cout << "LibMat::print -- I am a LibMat object\n"; }
};

#include<string>
class Book :public LibMat
{
public:
	Book( string title, string author)
		:_title(title), _author(author)
	{
		cout<<"Book::Book() constructor\n";
	}

	virtual ~Book(){ cout << "Book::~Book() destructor\n"; }
	virtual void print()const
	{
		cout << "Book::print(): a Book object\n";
		cout << "book title: " << _title << '\n'
			<< "book author: " << _author << '\n';
	}

protected:
	string _title;
	string _author;

};

class AudioBook : public Book
{
public:
	AudioBook(string title, string author,
		string narrator) : Book(title, author),
		_narrator(narrator){
		cout << "AudioBook::AudioBook(): constructor\n\n";
	}
	virtual ~AudioBook(){ cout << "\nAudioBook::~AudioBook(): destructor\n"; }
	virtual void print()const
	{
		cout << "AudioBook::print(): a AudioBook object\n";
		cout << "title: " << _title << '\n'
			<< "author: " << _author << '\n'
			<< "narrator: " << _narrator << '\n';
	}
protected:
	string _narrator;
};