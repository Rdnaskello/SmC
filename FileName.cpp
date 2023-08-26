#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
protected:
	string username;
	int followers;
	int posts;

public:
	User(const string& username, int followers)
		: username(username),
		  followers(followers),
		  posts(0) {
	}

	virtual void get_status() {
		cout << "username is " << username << endl;
		cout << "followers is " << followers << endl;
		cout << "posts " << posts << endl;
	}

	void add_post() {
		posts++;
	}
};

class RegularUser : public User {
public:
	RegularUser(const string& username, int followers)
		: User(username, followers){
	}
};

class InfluencerUser : public User {
private:
	int likes;
public:
	InfluencerUser(const string& username, int followers)
		: User (username, followers), likes(0) {}

	void like_post(){
		likes++;
	}

	void get_status() override {
		User::get_status();
		cout << "AVG likes is " << AvgLikes() <<endl;
	}
private:
	int AvgLikes() {
		if (posts > 0) {
			return likes / posts;
		}
		else {
			return 0;
		}
	}
};

int main() {
	RegularUser regularUser("Anya", 1000);
	InfluencerUser influencer("Dima", 50000);

	regularUser.add_post();

	for (int i = 0; i < 10; i++)
	{
		influencer.add_post();
	}
	
	for (int i = 0; i < 1000; i++)
	{
		influencer.like_post();
	}
	

	cout << "Regular User Status:" << endl;
	regularUser.get_status();

	cout << "\nInfluencer Status:" << endl;
	influencer.get_status();

	return 0;
}