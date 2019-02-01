# Calculator-with-history
A calculator that takes user input and performs an operation, gives back history, etc.

##  Main.cpp file

In this file, is where all the fun and all the code is. First off, we import our libraries that we will be using. In this case, we will be using vectors and strings, therefore `#include <string>` and `#include <vector>`.

In the next few lines, we initialize our variables that we will be using. We will make them public so we can assign our `keepOn` variable to true when we make an instance of the class. We need to do that so our program can run. We will see that why and how later in the documentation.
```
public:

  string userInput;
  bool keepOn;
  string yesOrNo; 
  std::vector<double> calculations;
```

Let's see what each variable will be for. 

Our first variable `string userInput;` will be our, you gussed it, user input placeholder.

Our second variable `bool keepOn;` will be a variable that will keep the looping going on until the user decides to exit the program. When the exit choice has been activated, keepOn's value will be false, therefore breaking the main loop. We will see that later in the code. 

The third variable will keep track of whether the user has chosen to perform another operation, to choose to show the history of the operations that have been performed, or to simply exit the program. Again, we will see that later in the documentation. 

Then finally, our fourth variable `std::vector<double> calculations;` will be our vector that will store the results that we will later show as a *history*. We choose to use vector here, because it is more effiecient and it is easier since C++ gives us the  option to use the `push_back()` method which allows us to easily push items into the vector.

The next couple of lines are: 

```
void start() {
    cout << "Welcome to my Calculator";
    while(keepOn == true) {
      calculate();
    }
}
```
This basically says: "Hey, start the calculator with a message 'Welcome to my calculator!' and keep calculating until the user hasn't chosen to exit from our program.". The **calculate()** method we are using here has not yet been intialized, but we will initialize it soon enough.

After starting our program, we ask the user what operation he wants our calculator to perform (*addition, multiplication, subtraction, division*). Then we return what the user has given us so we can store the value later on to a local variable which we will be able to manipulate.

```
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
```

After asking the user for what operation he wants to perform, the next thing we do is creating `getFirstNumber()` and `getSecondNumber()` methods. What these methods do, is basically asking the user to input his first and second number and then we are returning this particular value so we can assign it to a variable which will help us to manipulate this value later on.

```
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
```

After this, we are creating all of the operations our Calculator will be performing -- *addition, multiplication, subtraction, division*. 

```
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
  cout<<"\n";  
}
```

Each method will take 2 parameters. These parameters will be the values that the user has chosen. We will see how to do it later in our `calculate()` method later in the program. But what essentially these methods do is just take 2 numbers adding the result from them to our vector `calculations` and then just printing the result. 

The following method `showMenu()` will show us the menu that will be displayed after the user has performed an operation. It will ask the user whether he wants to perform another operation, to load the history, or to exit the program. If the user has given **1** then we will invoke our `calculate()` method which will ask the user for the two numbers and then give the result and add the result to our vector. If he has given us **3**, then in that case we will make our `keepOn` variable to `false` because that way we will stop our `start()` method which means our program will stop. We are also calling `exitMessage()` method that we will initialize shortly. And finally, if the user has given us **2**, that means he wants us to show his history of results he has gotten so far. So we call our function `loadHistory()`, which we will initialize shortly. 

```
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
```

The next method we create, is called `loadHistory()`. It prints a message and then we are looping through our vector printing each item in it. Remember, the items in our vector are the results that the user has gotten from his operations he has done so far.

```
void loadHistory() {
  cout<<"Here are the calculations you have done so far: ";
  cout<<"\n";

  for (int i = 0; i < calculations.size(); i++){
    cout<<calculations[i];
    cout<<"\n";
  }
}
```

The next one is the exit message we want to execute if the user has given us **3**. We quickly give him the operations he has done so far (*just a preference*) and display a *thank you* message. 

```
void exitMessage() {
  cout<<"Here are the results of calculations you have done so far: ";

  cout<<"\n";

  for (int i = 0; i < calculations.size(); i++){
    cout<<calculations[i];
    cout<<"\n";
  }

  cout<<"Thank you for using our program! Hope you enjoyed the experience!";
}
```

And then finally, our last and maybe in fact most important method -- `calculate()`. Okay, here in this method we are basically combining all of the upper methods we have created. Firstly, we initialize 2 variables that we will be used for looping purposes. Then we initialize a **string** variable that will hold the operation that the user has chosen. 

We are asking the user to choose an operation by calling the `chooseOperator()` method (*look it up upper in this documentation for clarification*). After that, we have a couple of if statements that check what the operation the user has chosen. Based on his chosen operation, we get the numbers he wants (*look `getFirstNumber()` and `getSecondNumber()` for clarification*), perform the corresponding operation by calling the corresponding method (`addition()`, `sub()`, `division()` or `mult()`) and then finally we make x = 1 to end the asking for operation loop. Then after the operation has been performed successfully (or in other words `x = 1`), we call our method `showMenu()`. 

```
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
```

And then finally, we have our little function `main()` that will just make an instance of our class and call our `start()` method.

```
int main() {
  Calculator calc;
  calc.keepOn = true;
  calc.start();
}
```

# THANK YOU! :punch:
