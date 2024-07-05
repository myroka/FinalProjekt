#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void hallo() {
    cout << "Привет, бабушка, я твой миросеть и я помощник в интернете." << endl;
    cout << "Что ты хочешь найти сегодня?" << endl;
}

string vopros() {
    string bot_help_babuhka;
    cout << "Введите свой вопрос: ";
    getline(cin, bot_help_babuhka);

    for (char& c : bot_help_babuhka) {
        c = tolower(c);
    }

    return bot_help_babuhka;
}

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&currentTime);

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void poisk_internet(const string& bot_help_babuhka) {
    cout << "Поиск информации " << endl;

    if (bot_help_babuhka.find("прогноз погоды") != string::npos) {
        cout << "Сегодня 37 градусов тепла." << endl;
        cout << "завтра 35 градусов тепла." << endl;
    }
    if (bot_help_babuhka.find("новости") != string::npos) {
        cout
            << "27 июня к бывшему заместителю главы Офис президента Кириллу "
            "Тимошенко пришли с обысками из-за дела со ливнями изНАБУ.Источник: "
            "корреспондент УП с места событий, источник Украинской правды в САП "
            "Детали: По данным журналиста УП, Кирилл Тимошенко находится в "
            "автомобиле, вокруг которого работают детективы НАБУ.."
            << endl;
    }

    if (bot_help_babuhka.find("какое сейчас время?") != string::npos) {
        cout << getCurrentTime() << endl;
    }

    else {
        cout << "Найдено столько результатов:" << endl;
        cout << " Результат 1 для Бабушки" << endl;
        cout << " Результат 2 для бабушки" << endl;
        cout << " Результат 3 для бабушки" << endl;
    }
}

void prohanie() {
    cout << "Спасибо, что воспользовались мной шлю..))) сегодня! Хорошего дня!"
        << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");

    hallo();

    string bot_help_babuhka = vopros();
    poisk_internet(bot_help_babuhka);

    prohanie();

    return 0;
}