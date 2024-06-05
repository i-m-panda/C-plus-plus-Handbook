// CONDITIONAL STATEMENTS
// if
/*
if(condition) {

}
*/

// if else
/*
if(condition) {
  
} else {

}
*/

// if else if else
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