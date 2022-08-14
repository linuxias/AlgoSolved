#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used_syms[128];

string check_rule1(string& sentence) {
    string ret = "";

    // 규칙 1이 적용될 문자열은 길이가 3보다 크고, 항상 홀수이다.
    if (sentence.size() < 3 || sentence.size() % 2 == 0)
        return "";

    // 연속된 대문자의 경우 규칙 1에 위배된다.
    if (isupper(sentence[1]))
        return "";

    char check_sym = sentence[1];
    for (int i = 0; i < sentence.size(); i++) {
        if (i % 2 == 0) {
            if (isupper(sentence[i]))
                ret += sentence[i];
            else return "";
        }
        else if (sentence[i] != check_sym)
            return "";
    }

    return ret;
}

string check_rule2(string& sentence) {
    string ret = "";

    for (auto& c : sentence) {
        if (isupper(c)) ret += c;
        else return "";
    }

    return ret;
}

string solution(string sentence) {
    string answer = "";

    for (int i = 0; i < 128; i++) {
        used_syms[i] = false;
    }

    while (sentence.empty() == false) {
        string word = ""; // 복구할 단어
        vector<int> pos;

        if (islower(sentence[0])) {              // 두번째 규칙인지
            char code = sentence[0];

            if (used_syms[code])
                return "invalid";

            string tmp = sentence;
            while (tmp.find(code) != string::npos) {
                int idx = tmp.find(code);
                pos.push_back(idx);
                tmp[idx] = ' ';
            }
            if (pos.size() != 2)
                return "invalid";

            used_syms[code] = true;

            string sub_word = sentence.substr(1, pos.back() - 1);

            word = "";
            if ((word = check_rule1(sub_word)) != "") {
                if (used_syms[sub_word[1]])
                    return "invalid";
                used_syms[sub_word[1]] = true;
            }
            else if ((word = check_rule2(sub_word)) != "") {
                used_syms[sub_word[1]] = true;
            }
            else {
                return "invalid";
            }

            sentence = sentence.substr(pos.back() + 1);
        } else {    // 첫 번째 규칙의 가능성 단어
            if (sentence.size() == 1 || isupper(sentence[1])) { // 글자가 1개 -> 마지막이거나, 다음이 대문자가 이어질때
                word = sentence[0];
                sentence = sentence.substr(1);
            }
            else { // 다음 글자가 기호일 때
                string tmp = sentence;

                // 기호의 위치를 찾아 pos에 저장하고, 해당 위치는 ' ' 으로 치환
                while (tmp.find(sentence[1]) != string::npos) {
                    int idx = tmp.find(sentence[1]);
                    pos.push_back(idx);
                    tmp[idx] = ' ';
                }

                // pos의 개수가 2개가 아니라면 -> 규칙 1 / 2개라면 규칙 2 적용가능.
                if (pos.size() != 2) {

                    // 대문자 시작, 소문자 끝인 경우 처리 ex) HaEaLa, HaEaLab
                    if (sentence.size() - 1 == pos.back() || islower(sentence[pos.back() + 1]))
                        return "invalid";

                    string sub_word = sentence.substr(0, pos.back() + 2);
                    word = "";
                    if ((word = check_rule1(sub_word)) != "") {
                        if (used_syms[sub_word[1]])
                            return "invalid";

                        used_syms[sub_word[1]] = true;
                        sentence = sentence.substr(pos.back() + 2);
                    }
                    else {
                        return "invalid";
                    }
                }
                else {
                    word = sentence[0];
                    sentence = sentence.substr(1);
                }
            }
        }

        answer += word + " ";
    }

    answer.pop_back();

    return answer;
}

int main() {
    vector<pair<string, string>> results = {
        {"HaEaLaLaObWORLDb", "HELLO WORLD"},
        {"SpIpGpOpNpGJqOqA", "SIGONG JOA"},
        {"AxAxAxAoBoBoB", "invalid"},
        {"AxAxAx", "invalid"},
        {"AaAaAcA", "invalid"},
        {"aHeLeLeOa", "HLLO"},
        {"zAAzbBcBb", "AA BB"},
        {"AaAaAbBbBbB", "invalid"},
        {"AA", "invalid"},
        {"aAbAcAcAcAa", "invalid"},
        {"AaABbBbB", "AA B B B"},
        {"AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR", "AA ABA BBBB C BBBB C BB GG GGG RRRRRR"},
        {"aaA", "invalid"},
        {"Aaa", "invalid"}
    };

    for (auto& tc : results) {

        auto ret = solution(tc.first);
        std::cout << ret << " / " << tc.second << std::endl;
    }

    return 0;
}
