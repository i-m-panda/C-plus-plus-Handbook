// CONDITIONAL STATEMENTS
// if
/*
if(condition) {

}
*/

// if-else
/*
if(condition) {
  
} else {

}
*/

// if else-if else
/*
if(condition) {
  
} else if() {
  
} else {

}
*/
// these conditional statements can be nested according to the requirement
// switch case

/*
// control variable(day in the example below) must be of integral type(strings not allowed)
// the expression used in case should be constant('M', 'T', 'W' used below)
// default case is executed if none of the case matches
// break statement after each case is required, because in it's absence if one case matches, 
// all below cases are executed until break is encountered, this condition is called fall through
switch(day) {
  case 'M': std::cout << "Monday" <<"\n";
            break;
  case 'T': std::cout << "Tuesday" << "\n";
            break;
  case 'W': std::cout << "Wednesday" << "\n";
            break;
  default: std::cout << "Sunday" << "\n";
}
*/

// ITERATIVE STATEMENTS
/*
while loop: runs until the condition is true

SYNTAX:
while(condition) {
  statement 1
  statement 2
  .
  .
  .
  statement N
}

for loop: runs until for loop condition is met
SYNTAX:
for (initialization; test condition; updation) {
  statement 1
  statement 2
  .
  .
  .
  statement N
}

// do while loop: runs until while loop condition is true, runs atleast once
do {
  statement 1
  statement 2
  .
  .
  .
  statement N
} while(condition);
*/
// - avoid infinite loops unless it's intentional
// - for fixed initialization and condition use for loop else use while or do while
// - you can nest conditional statement however you like
// - you can use break and continue to control the flow of iterative statements
// - "break": is used to stop the execution of the loop and bring the control back out of the loop
// - "continue": is used to skip the execution of the current iteration of the loop

#include<iostream>

void conditional_statements() {
  // not the best conditions below, but you get the idea, right?
  int age;
  std::cout << "enter your age\n";
  std::cin >> age;
  // if
  if (age > 60)
  {
    std::cout << "You are a senior citizen\n";
  }

  // if-else
  if (age < 10) {
    std::cout << "You are a child!\n";
  } else {
    std::cout << "You are an adult\n";
  }
  
  // if else-if else
  if (age > 10 && age < 20) {
    std::cout << "You are a teen\n";
  } else if (age > 19 && age < 45) {
    std::cout << "You are an adult\n";
  } else {
    std::cout << "You are old\n";
  }
}

void iterative_statement() {
  std::cout << "printing even numbers until 10 using for loop\n";
  for (int i = 0; i < 11; i=i+2) {
    std::cout << i << "\n";
  }
  
  std::cout << "printing even numbers until 10 using while loop\n";
  int j = 0;
  while (j < 11) {
    std::cout << j << "\n";
    j = j + 2;
  }
  
  std::cout << "printing even numbers until 10 using do-while loop\n";
  int k = 0;
  do {
    std::cout << k << "\n";
    k = k + 2;
  } while(k < 11);

  std::cout << "printing even numbers until 10 using while loop and a break statement\n";
  int l = 0;
  while (true) {
    if (l > 10) {
      break;
    }
    
    std::cout << l << "\n";
    l = l + 2;
  }

  std::cout << "printing even numbers until 10 using while loop but skip 6 using continue statement\n";
  int m = 0;
  while (m < 11) {
    if(m == 6) {
      m = m + 2;
      continue;
    }
    std::cout << m << "\n";
    m = m + 2;
  }

  std::cout << "printing even numbers until 10 using for loop but skip 6 using continue statement\n";
  for (int i = 0; i < 11; i=i+2) {
    if(i == 6) {
      continue;
    }
    std::cout << i << "\n";
  }
}

int main() {
  conditional_statements();
  iterative_statement();
  return 0;
}