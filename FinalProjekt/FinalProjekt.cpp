#include <chrono>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

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
    tm localTime;
    localtime_s(&localTime, &currentTime); // функция localtime_s предотвращает переполнения в буфере и для коректной работы кода

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

}

void prohanie() {
    cout << "Спасибо, что воспользовались мной сегодня! Хорошего дня!" << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // задан вопрос
    cout << "Что вы думаете о бабушке? ";
    string answer;
    getline(cin, answer);

    
    ofstream outputFile("babuska_ozenka.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << answer << endl;
        outputFile.close();
        cout << "Ваша оценка была записана." << endl;
    }
    else {
        cout << "Ошибка при открытии файла для записи." << endl;
    }

    // взаимодействие с бабушкой
    string bot_help_babuhka_input = vopros();
    poisk_internet(bot_help_babuhka_input);

    setlocale(LC_ALL, "Ru");

    hallo();

    bot_help_babuhka_input = vopros();
    poisk_internet(bot_help_babuhka_input);

    prohanie();

    return 0;
}
