#include "../test/logging.h"
#include "key_value.h"
#include "dlistNico.h"
#include "map.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::transform;
using std::cin;

struct Player {
	Player(string n, string t, int j) : name(n), team(t), jersey_number(j) {}
	string name; 
	string team;
	int jersey_number;
};

	typedef map<string, Player> PlayerMap; 
	typedef map<string, Player>::iter PlayerMapIter;
	typedef key_value<string,Player> KV;

void AddPlayer(PlayerMap* player_map, string name, string team, int number) {
	Player player(name, team, number);
	player_map->insert(KV(name, player));
}

ostream& operator<<(ostream& os, Player p){
	os << p.name <<" " << p.jersey_number <<" " <<p.team <<"    ";
	return os;
}

int main() {

	BEGIN_TESTS();

	

	PlayerMap m;
	// CHECK_EQ(m.empty(), true);
	// Player kobe("Kobe", "Lakers", 24);
	// m.insert(KV("Kobe", kobe));
	// AddPlayer(&m, "Klay", "Warriors", 11);
	// Player curry("Curry", "Warriors", 30);
	// m.insert(KV("Curry", curry));
	// Player Lebron("Lebron", "Cavaliers", 23);
	// m.insert(KV("Lebron", Lebron));
	// PlayerMapIter it = m.find("Curry");
	// CHECK_EQ(it==m.end(), false);
	// cout << m <<endl;
	// CHECK_EQ(m.size(), 4);
	// Player g("Kobe", "Lakers", 24);
	// cout << g;

	// Add the players
  AddPlayer(&m, "Kobe Bryant", "Lakers", 24);
  AddPlayer(&m, "Stephen Curry", "Warriors", 30);
  AddPlayer(&m, "Michael Jordan", "Bulls", 23);
  AddPlayer(&m, "Shaquille O'Neal", "Magic", 34);
  AddPlayer(&m, "LeBron James", "Caveliers", 23);
  AddPlayer(&m, "Klay Thompson", "Warriors", 11);
  AddPlayer(&m, "Tristen Thompson", "Caveliers", 13);

	//Search database
	while(true){
		string name;
		cout << "Enter Player Name: ";
		cin >> name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		cout <<"Name = "<<name <<endl;
		if(name == "q"){
			break;
		}
		PlayerMapIter it = m.begin();
		bool found = false;
		while(it!=m.end()){
			string key = it.data().key;
			transform(key.begin(), key.end(), key.begin(), ::tolower);

			string::size_type index = key.find(name);
			if(index!=string::npos){
				found = true;
				cout <<it.data().value <<endl;
			}
			it = it.next();
		}
		if(!found){
			cout << "Player " << name << " is not in database" << endl;
		}
	}
}