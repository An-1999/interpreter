#include <string>
#include <fstream>
#include <vector>
#include <map>

struct Variable
{
    std::string type;
    std::string variable;
    std::string value;
};

class Parser
{
public:
    Parser(const char* str) : m_fstr {str}
    {
        if (!m_fstr.is_open()) {
            std::cout << "cann't open file" << std::endl;
            abort();
        }
        while(std::getline(m_fstr, m_str)) {
            if (m_str.find("#") == 0) continue;
            if (m_str == "") continue;
            if (m_str.find ("ete") == 0 || m_str.find ("cikl") == 0) {
                temprorybool = true;
            }
            if (m_str.find("<-") == 0) {
                temproryLine.push_back(m_str);
                conditionAndLoop();
           } else if (temprorybool) {
                temproryLine.push_back(m_str);
            } else {
                if (m_str.find("<-") == 0) continue;
                pars();
                m_token.clear();
            }
        }
    }
    ~Parser() = default;
private:
    void pars_token();
    void pars(bool temp = true);
    void parsTemproryIf(int& index);
    void parsTemproryFor(int& index);
    void input(bool temp = true);
    void output(bool temp = true);
    void integers(bool temp = true);
    void doubles(bool temp = true);
    void boolean(bool temp = true);
    void characters(bool temp = true);
    void withoutTypeVariable(bool temp = true);
    void print();
private:
    bool isNumberI(const std::string&) const;
    bool isNumberD(std::string&);
    bool isSimbol (const std::string&) const;
    bool haveVariable(const std::string&) const;
    bool haveVariableInStaticVector (const std::string&) const;
    std::string getValueHaveVariable (const std::string&) const;
    std::string getValueHaveVariableStatic (const std::string&) const;
    void changeValue(const std::string& str_name, std::string& str_value, bool temp = true);
    std::string cinRightValu(const std::string&);
    std::string rightValu(const std::string& type, std::string value, bool temp = true);
    std::string calculate (const char signOfAction, std::string nameRvalu1, std::string nameRvalu2, bool temp = true);
    double helperOperations (const char, double, double);
    int indexCloseScope(int indexOpenScope);
    std::string operation(int index);
    double helpExpression(std::string str, bool temp = true);
    bool expression(std::string loperand, std::string operation, std::string roperand, bool temp = true);
    int operationSign() const;
    bool condition(bool temp = true);
    void conditionAndLoop();
private:
    std::string m_str;
    std::vector<Variable> m_variable;
    std::vector<std::string> m_token;
    std::vector<std::string> temproryLine;
    static std::vector<Variable> s_variable;
    std::vector<Variable> t_variable;
    std::fstream m_fstr;
    bool temprorybool = false;
};


