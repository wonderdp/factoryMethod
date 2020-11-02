#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
enum CATEGORY {
    TOURISM,
    SPORT,
    FASHION,
    LAPTOP,
    HUNTING,
    STUDYING,
};
enum COLOR {
    RED,
    GREEN,
    BLUE,
    BLACK,
    GRAY,
    WHITE,
    YELLOW,
    ORANGE,
};

string getCategory(CATEGORY category) {
    switch (category) {
        case CATEGORY::TOURISM:
            return "TOURISM";
        case CATEGORY::SPORT:
            return "SPORT";
        case CATEGORY::FASHION:
            return "FASHION";
        case CATEGORY::LAPTOP:
            return "LAPTOP";
        case CATEGORY::HUNTING:
            return "HUNTING";
        case CATEGORY::STUDYING:
            return "STUDYING";
    }
}

string getColor(COLOR color) {
    switch (color) {
        case COLOR::RED:
            return "RED";
        case COLOR::GREEN:
            return "GREEN";
        case COLOR::BLUE:
            return "BLUE";
        case COLOR::BLACK:
            return "BLACK";
        case COLOR::GRAY:
            return "GRAY";
        case COLOR::WHITE:
            return "WHITE";
        case COLOR::YELLOW:
            return "YELLOW";
        case COLOR::ORANGE:
            return "ORANGE";
    }
}

class Backpack {
    string firm;
    string model;
    unsigned int capacity;
    unsigned int price;
    CATEGORY category;
    COLOR color;
public:
    Backpack(const string &firm, const string &model,CATEGORY category, COLOR color, unsigned int capacity, unsigned int price) {
            this->firm = firm;
            this->model = model;
            this->category = category;
            this->color = color;
            this->capacity = capacity;
            this->price = price;
    }

    const string &getFirm() const {
        return firm;
    }

    const string &getModel() const {
        return model;
    }

    CATEGORY getCategory() const {
        return category;
    }

    COLOR getColor() const {
        return color;
    }

    string getDescription() const {
        return firm + " " + model + " " + ::getCategory(category) + " " + ::getColor(color) + " " + to_string(capacity) + ", " + to_string(price);
    }

    static Backpack *createAdidasSportOrange() {
        return new Backpack("Adidas", "Classic-3", CATEGORY::SPORT,COLOR::ORANGE, 30, 5000);
    }

    static Backpack *createNikeSportBlack() {
        return new Backpack("Nike", "Sportswear", CATEGORY::SPORT,COLOR::BLACK, 25, 3000);
    }

    static Backpack *createGucciFashionWhite(COLOR color = COLOR::WHITE) {
        return new Backpack("Gucci", "FACE",CATEGORY::FASHION, color, 20, 20000);
    }
};

class BackpackList {
private:
    vector<const Backpack *> backpacks;
public:
    void add(Backpack &backpack){
        backpacks.push_back(&backpack);
    }

    void print(){
        size_t size = backpacks.size();
        if (size == 0){
            cout << "Пусто" << endl;
        } else {
            for (unsigned short i = 0; i < size; i++)
                cout << i+1 << ". " << backpacks[i]->getDescription() << "р" << endl;
        }
    }
};

int main() {
    BackpackList list;

    list.add(*Backpack::createAdidasSportOrange());
    list.add((*Backpack::createNikeSportBlack()));
    list.add((*Backpack::createGucciFashionWhite()));

    list.print();

    return 0;
}
