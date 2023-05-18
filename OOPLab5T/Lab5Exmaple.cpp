#include "Lab5Exmaple.h"
#include <fstream>
#include <iostream>
using namespace std;

/*Створити клас студент, що має поля: ПІБ(прізвище, ім'я, по-батькові) курс
і ідентифікаційний номер. Визначити конструктори, деструктор і функцію друку.
Створити похідний клас – студент-дипломник, що має тему диплома. Визначити
конструктори за замовчуванням і з різним числом параметрів, деструктори, функцію
друку. Визначити функції перепризначення назви диплома та ідентифікаційного
номера. Написати програму тестування всіх можливостей цього класу.*/

class PIB {
  public:
  string surname;
  string name;
  string lastname;
  int course;
  int ID;

public:
  PIB() {
    name = "No name";
    surname = "No surname";
    lastname = "No lastname";
    course = 0;
    ID = 0;
  }
  PIB(string n) {
    name = n;
    surname = "No surname";
    lastname = "No lastname";
    course = 0;
    ID = 0;
  }
  PIB(string n, string surn, string lastn) {
    name = n;
    surname = surn;
    lastname = lastn;
    course = 0;
    ID = 0;
  }
  PIB(string n, string surn, string lastn, int cour, int id) {
    name = n;
    surname = surn;
    lastname = lastn;
    course = cour;
    ID = id;
  }
  PIB(const PIB &p) {
    name = p.name;
    surname = p.surname;
    lastname = p.lastname;
    course = p.course;
    ID = p.ID;
  }
  ~PIB() {}

  void print() {
    cout << "PIB:" << surname << " " << name << " " << lastname << " course:" << course
         << " ID:" << ID;
  };
  friend ostream &operator<<(ostream &os, PIB &a);
  friend istream &operator>>(istream &os, PIB &a);
};
ostream &operator<<(ostream &out, PIB &a) {
  out << a.surname << " " << a.name << " " << a.lastname << " " << a.course
      << " " << a.ID;
  return out;
}
istream &operator>>(istream &in, PIB &a) {
  in >> a.surname;
  in >> a.name;
  in >> a.lastname;
  in >> a.course;
  in >> a.ID;
  return in;
}

class GraduateStudent {
protected:
	string titleOfSubject;
	PIB name;
public:
  GraduateStudent() {
    titleOfSubject = "None";
  }
	GraduateStudent(PIB n) {
    name = n;
    titleOfSubject = "None";
  }
  GraduateStudent(PIB n, string title) {
    name = n;
    titleOfSubject = title;
  }
  ~GraduateStudent() {}
  void print() {
    name.print();
    cout << " SubjectName:" << titleOfSubject << endl;
  }
  void changeSubjectName(string subj) {
    titleOfSubject = subj;
  }
  void changeID(int id) {
    name.ID = id;
  }
};

void exersice1() {
  cout << "Create PIB" << endl;
  PIB ol("Dmytro", "Yuzko", "Romanovich", 1, 5643);
  ol.print();
  cout << endl;
  cout << "Create Graduate student with math project" << endl;
  GraduateStudent olex(ol, "Math");
  olex.print();
  cout << "Change subject name to Geometry" << endl;
  olex.changeSubjectName("Geometry");
  olex.print();
  cout << "Change ID to 7777" << endl; 
  olex.changeID(7777);
  olex.print();
};


/*Створити клас кімната, що має площа. Визначити конструктор і метод
доступу. Створити клас однокімнатних квартира, що містить кімнату й кухню (її
площа), поверх (кімната втримується в класі однокімнатна квартира). Визначити
конструктори, методи доступу. Визначити public-похідний клас однокімнатних
квартир різних міст ( додатковий параметр - назва міста). Визначити конструктори,
деструктор і функцію друку.*/


class Room {
  public:
    int area;
  Room() {
    area = 0;
  };
  Room(int ar) {
    area = ar;
  }
  void print() {
    cout << "Room:" << area << " meters";
  }
  ~Room() {};
};

class oneRoomApartment {
  public:
    Room room;
    int kitchenArea;
    int floor;
  oneRoomApartment() {
    kitchenArea = 0;
  }
  oneRoomApartment(Room r) {
    room = r;
    kitchenArea = 0;
  }
  oneRoomApartment(Room r, int area) {
    room = r;
    kitchenArea = area;
  }
  oneRoomApartment(Room r, int area, int f) {
    room = r;
    kitchenArea = area;
    floor = f;
  }
  ~oneRoomApartment() {};
  void print() {
    room.print();
    cout << " Kitchen:" << kitchenArea << " meters" << " floor:" << floor;
  }
};

class oneRoomCityApartment : public oneRoomApartment {
  public:
    oneRoomApartment oneRoom;
    string city;
  oneRoomCityApartment() {
    city = "";
  }
  oneRoomCityApartment(oneRoomApartment room) {
    oneRoom = room;
  }
  oneRoomCityApartment(oneRoomApartment room, string c) {
    oneRoom = room;
    city = c;
  }
  ~oneRoomCityApartment() {};
  void print() {
    oneRoom.print();
    cout << " City: " << city; 
  };
};

void exersice2() {
    cout << "Create the room with 32 meters" << endl;
    Room r(32);
    r.print();
    cout << endl;
    cout << "Create one room apartment with 9 meters kitchen and 2 floor" << endl;
    oneRoomApartment room(r, 9, 2);
    room.print();
    cout << endl;
    cout << "Create apartment in city Chernivtsi" << endl;
    oneRoomCityApartment cityRoom(room,  "Chernivtsi");
    cityRoom.print();
    cout << endl;
}

/*Створити ієрархію класів спортивна гра й футбол. Перевизначити вивід у
потік і введення з потоку, конструктори копіювання та перенесення, оператори
присвоювання та перенесення через відповідні функції базового класу.*/


class sportGame {
  public:
    string sportName;
    int players;
  sportGame() {
    sportName = "No sport";
    players = 0;
  }
  sportGame(string sport) {
    sportName = sport;
    players = 0;
  }
  sportGame(string sport, int pl) {
    sportName = sport;
    players = pl;
  }

  sportGame  &operator=(const sportGame &n) {
    players = n.players;
    sportName = n.sportName;
    return *this;
  }

  void print() {
    cout << "Sport Game:" << sportName << " players:" << players << endl; 
  }

  friend istream &operator>>(istream &input, sportGame &n);
  friend ostream &operator<<(ostream &output, const sportGame &n);
};

istream &operator>>(istream &input, sportGame &n) {
  string name;
    int pl;
  input >> name >> pl;
  n.sportName = name;
  n.players =  pl;
  return input;
}

ostream &operator<<(ostream &output, const sportGame &n) {
  output << "Sport Game:" << n.sportName << " players:" << n.players; 
  output << endl;
  return output;
}

class football : public sportGame {
  public:
    string country;
  football() {
    sportName = "Football";
    players = 0;
    country = "No country";
  }
  football(int pl) {
    sportName = "Football";
    players = pl;
    country = "No country";
  }
  football(int pl, string count) {
    sportName = "Football";
    players = pl;
    country = count;
  }
  football  &operator=(const football &n) {
    players = n.players;
    sportName = n.sportName;
    country = n.country;
    return *this;
  }

   friend istream &operator>>(istream &input, football &n);
  friend ostream &operator<<(ostream &output, const football &n);
};

istream &operator>>(istream &input, football &n) {
  string count;
    int pl;
  cout << "Enter country and number of players:";
  input >> count >> pl;
  n.sportName = "Football";
  n.players =  pl;
  n.country = count;
  return input;
}

ostream &operator<<(ostream &output, const football &n) {
  output << "Sport Game:" << n.sportName << " players:" << n.players << " country:" << n.country; 
  output << endl;
  return output;
}

void exersice3() {
  cout << "Create sport game basketball wiht 22 players" << endl;
  sportGame basketball("basketball", 22);
  basketball.print();
  football g, f;
  cin >> g;  
  f = g;
  cout << f;
}
