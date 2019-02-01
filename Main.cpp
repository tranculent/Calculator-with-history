#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculator {
  public:

  string userInput;
  bool keepOn;
  string yesOrNo; 
  std::vector<double> calculations;
  
  void start() {
    cout << "Welcome to my Calculator";
    while(keepOn == true) {
      calculate();
    }
  }

  string chooseOperator() {
    cout << "What to do?"<<
            "\n + for add"<<
            "\n - for minus"<<
            "\n * for multiply"<<
            "\n / for divide";
    cout << "\n";
    string chosenOperator;
    cin>>chosenOperator;
    return chosenOperator;
  }

  double getFirstNumber() {
    cout<<"Input the 1st number ";
    double firstNum;
    cin>>firstNum;
    return firstNum;
  }

  double getSecondNumber() {
    cout<<"Input the 2nd number ";
    double secondNum;
    cin>>secondNum;
    return secondNum;
  }

  void addition(double a, double b) {
    calculations.push_back(a+b);
    cout<<"The Num is: "<<a+b;
    cout<<"\n";
  }
  void sub(double a, double b) {
    calculations.push_back(a-b);
    cout<<"The Num is: "<<a-b;
    cout<<"\n";
  }
  void mult(double a, double b) {
    calculations.push_back(a*b);
    cout<<"The Num is: "<<a*b;
    cout<<"\n";
  }
  void division(double a, double b) {
    calculations.push_back(a/b);
    cout<<"The Num is: "<<a/b;
    cout<<"\n";  }

  void showMenu() {
    int z = 0;
    while (z != 1){ 
      cout<<"Please press the corresponding number for the operation you wish to perform.";
      cout<<"\n";
      cout<<"1. Another operation?";
      cout<<"\n";
      cout<<"2. History?";
      cout<<"\n";
      cout<<"3. Exit?";
      cout<<"\n";
      
      cin>>yesOrNo;

      if(yesOrNo == ("1")) {
        z = 1;
        calculate();
      }
      else if (yesOrNo == ("3")) {
        z = 1;
        keepOn = false;
        exitMessage();
      }
      else if (yesOrNo ==("2")){
        loadHistory();
      }
    }
  }

  void loadHistory() {
    cout<<"Here are the calculations you have done so far: ";
    cout<<"\n";

    for (int i = 0; i < calculations.size(); i++){
      cout<<calculations[i];
      cout<<"\n";
    }
  }

  void exitMessage() {
    cout<<"Here are the results of calculations you have done so far: ";

    cout<<"\n";

    for (int i = 0; i < calculations.size(); i++){
      cout<<calculations[i];
      cout<<"\n";
    }

    cout<<"Thank you for using our program! Hope you enjoyed the experience!";
  }

  void calculate() {
    int x = 0; 
    int y = 0; 
    string operation;
    
    while (x < 1) {
      operation = chooseOperator();
      if(operation == ("+")){
        double num1 = getFirstNumber();
        double num2 = getSecondNumber();
        addition(num1, num2);
        x = 1;
      }
      else if (operation == ("-")) {
        double num1 = getFirstNumber();
        double num2 = getSecondNumber();
        sub(num1, num2);
        x = 1;
      }
      else if (operation == ("/")) {
        double num1 = getFirstNumber();
        double num2 = getSecondNumber();
        division(num1, num2);
        x = 1;
      }
      else if (operation == ("*")) {
        double num1 = getFirstNumber();
        double num2 = getSecondNumber();
        mult(num1, num2);
        x = 1;
      }
    }
    if (x == 1) {
      showMenu();
    }
  } 
};

int main() {
  Calculator calc;
  calc.keepOn = true;
  calc.start();
}
