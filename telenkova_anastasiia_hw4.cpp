#include <iostream>
#include <vector>
using namespace std;

//Написати функцію, яка отримує на вхід вектор стрінгів та int значення.
// Функція перевіряє, яка пара зі стрінгів у векторі має найбільшу сумарну довжину.
// Далі, ця найбільша довжина порівнюються із int параметром (який виступає пороговим значенням) -
// якщо довжина більша за порогове, то до вектора додається новий стрінг,
// який є зконкатенованою парою найкоротших стрінгів у векторі.
// Вектор необхідно вивести в консоль у ф-ї main().


void compare(vector<string> &words, int border){
    int max = 0;
    int min = (2^32) - 1;
    int length = 0;
    string new_word = "";
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if (i != j){          //i не повинно дорівнювати j, тому що з умови завдання ми порівнюємо саме пари стрінгів,
                                  //інакше ми б враховували суму одного й того ж самого стрінга
                length = words[i].size() + words[j].size();
                if (length > max){
                    max = length;
                }
                if (min > length) {
                    min = length;
                    new_word = words[i] + words[j];
                }
            }
        }
    }
    if (max > border){
        words.push_back(new_word);
    }
}




int main() {
    vector<string> words;
    string word;
    int border;
    cout << "insert your words, to stop insert 0" << endl;
    while (true){
        cin >> word;
        if (word == "0"){
            break;
        }
        else {
            words.push_back(word);
        }
    }
    cout << "insert the border value" << endl;
    cin >> border;

    compare(words, border);



    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
    return 0;
}
