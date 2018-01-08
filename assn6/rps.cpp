#include <iostream>
#include <map>

using namespace std;

typedef struct {
    char win;
    char lose;
} Rel;

class Tool {
	/* Fill in */
    public:
        static map<char, Rel> rels;

        char type;       
        int strength;
        Tool(int);
        bool fight(const Tool&);
};
Tool::Tool(int s) {
    strength = s;
}
bool Tool::fight(const Tool& t) {
    float my_s = (float) strength;
    auto rel = Tool::rels.find(type);

    if (t.type == rel->second.lose)
        my_s /= 2;
    else if (t.type == rel->second.win)
        my_s *= 2;
    return my_s > t.strength;
}

map<char, Rel> Tool::rels = {
    {'r', {'s', 'p'}},
    {'s', {'p', 'r'}},
    {'p', {'r', 's'}},
};

/*
	Implement class Scissors
*/

class Scissors: public Tool {
    public:
        Scissors(int);
        // bool fight(const Tool&);
};
Scissors::Scissors(int s)
: Tool(s) {
    type = 's';
}

/*
	Implement class Paper
*/
class Rock: public Tool {
    public:
        Rock(int);
        // bool fight(const Tool&);
};

Rock::Rock(int s)
: Tool(s) {
    type = 'r';
}
/*
	Implement class Rock
*/
class Paper: public Tool {
    public:
        Paper(int);
        // bool fight(const Tool &);
};

Paper::Paper(int s)
    : Tool(s) {
    type = 'p';
}

int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;
    
    // cout << "--------------------------" << endl;

	// Tool *s2 = new Scissors(5);
	// Tool *p2 = new Paper(7);
	// Tool *r2 = new Rock(15);
	// cout << s2->fight(*p2) << p2->fight(*s2) << endl;
	// cout << p2->fight(*r2) << r2->fight(*p2) << endl;
	// cout << r2->fight(*s2) << s2->fight(*r2) << endl;

	return 0;
}
