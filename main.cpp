// Proejct 3 Spring 2021 Skeleton code

#include<iostream>

using namespace std;

// myString class and corresponding methods come here
// used to empty a given string A of length n
void emptyString (char* A, int n) {
    for (int i=0; i < n; i++) {
        A[i] = '\0';
    }
}

// copy a string A to B of length n
void stringCopy (char* A, int n, char* B) {
    for (int i=0; i < n; i++) {
        B[i] = A[i];
    }
}

// return the length of a given string A
int stringLength (char* A) {
    int size = 0;
    while (A[size] != '\0') size++;
    return size; //size is the last index position
}

class myString;

class myString {
    friend ostream& operator << (ostream& s, myString& A);
protected:
    char* strArray;
    int size;
public:
    myString (); //default constructor
    myString(char* inpStr); //copy constructor from char array
    myString (myString& B); //copy constructor from myString object
    int Size(); //returns the size of this string object
    char* getWord(); //returns the strArray object
    bool operator == (myString& B); //operator to see if two strings are equal
    bool operator > (myString& B); //operator to see if this string is greater than the input string
    bool operator < (myString& B); //operator to see if this string is less than the input string
    myString& operator = (myString& B); //assignment operator from myString object
    myString& operator = (char* B); //assignment operator from char array object
    ~myString(); //destructor
};

// outputs a given string A
ostream& operator << (ostream& s, myString& A) {
    s << A.strArray;
    return s;
}

// default constructor - initializes with a NULL as the first character
myString::myString () {
    size = 0;
    strArray = new char[0];
    strArray[0] = ' ';
}

// non default constructor - initialize object with an existing string
myString::myString (char* inpStr) {
    int i = 0;
    while (inpStr[i] != '\0')
        i++;
    size = i;
    strArray = new char[size];
    emptyString (strArray, size+1);
    for (int j=0; j < size; j++)
        strArray[j] = inpStr[j];
}

// non default constructor - initialize object with an existing mystring object
myString::myString (myString& B) {
    strArray = nullptr; //setting the strArray to null
    size = B.size; //setting size equals to input object size
    strArray = new char[size+1]; //initializing the new array object
    emptyString(strArray, size+1); //emptying string
    stringCopy (B.strArray, size, strArray); //copying string ovwer
}

char* myString::getWord()
{
    return strArray; //returns the char array that represents the string of this object
}

// getter for size of myString
int myString::Size () {
    return size; //returns sizze of this string object
}

// overloading = operator - initialize object with an existing string
myString& myString::operator = (char* B) {
    size = stringLength(B);
    strArray = new char[size];
    for(int i = 0; i < size; i++) {
        strArray[i] = B[i];
    }
    return *this; //returning the output object
}

// overloading = operator - initialize object with an existing mystring object
myString& myString::operator = (myString& B) {
    if(this == &B) {
        return *this; //if the two strings are equals to eachother dont bother with copying it over
    }
    strArray = nullptr; //set the array equals to null
    size = B.size; //set sizes equals to eachother
    strArray = new char[size+1]; //initializing the array to miss out on all the garbage in the string
    emptyString(strArray, size+1); //empty this sttring
    stringCopy(B.strArray, size, strArray); //copy the string over

    return *this; //returning the output object
}

// checking if two myString objects are the same - return true or false
bool myString::operator==(myString& B) {
    if (this->Size() != B.Size()) {
        return false; //if the sizes do not equal eachother automatically return false
    }
    else {
        for (int i = 0; i < Size(); ++i) {
            if (B.getWord()[i] != this->getWord()[i]) {
                return false; //if any of the characters dont equal eachother return false
            }
        }
    }
    return true; //else return true
}

// comparison of myString A if less than myString B - return true or false
bool myString::operator<(myString& B) {
    if (Size() == B.Size()) {
        for (int i = 0; i < Size(); ++i) {
            if (getWord()[i]<B.getWord()[i]) {
                return true; //if any character is less than return true
            }
            else if(getWord()[i] > B.getWord()[i]) {
                return false; //else return false
            }
        }
        return false; //else return false
    }
    else if (Size() < B.Size() || Size() > B.Size()) { //if the sizes do not equal you wanna iterate over the smaller ones size
        int smaller;
        if (Size() < B.Size()) { //setting smaller size equal to smaller
            smaller = Size();
        }
        else {
            smaller = B.Size();
        }
        for (int i = 0; i < smaller; ++i) { //iterating over the two words
            if(getWord()[i] < B.getWord()[i]) {
                return true; //if any character is less than return true
            }
            else if(getWord()[i] > B.getWord()[i]) {
                return false; //else return false
            }
        }
        return (Size() < B.Size()); //if all of the characters of the smaller string is equal to the first few
        //characters of the bigger string return which one is smaller (true if this* is smaller, false if not)
    }
    else {
        return false; //failsafe return false
    }
}

// comparison of myString A if greater than myString B - return true or false
bool myString::operator>(myString& B) { //the methodology for this operator is the same as the previous
    if (Size() == B.Size()) {
        for (int i = 0; i < Size(); ++i) {
            if (getWord()[i]<B.getWord()[i]) {
                return false; //if any character is less than return true
            }
            else if(getWord()[i] > B.getWord()[i]) {
                return true; //else return false
            }
        }
        return true; //else return false
    }
    else if (Size() < B.Size() || Size() > B.Size()) { //if the sizes do not equal you wanna iterate over the smaller ones size
        int smaller;
        if (Size() < B.Size()) { //setting smaller size equal to smaller
            smaller = Size();
        }
        else {
            smaller = B.Size();
        }
        for (int i = 0; i < smaller; ++i) { //iterating over the two words
            if(getWord()[i] < B.getWord()[i]) {
                return false; //if any character is less than return true
            }
            else if(getWord()[i] > B.getWord()[i]) {
                return true; //else return false
            }
        }
        return (Size() < B.Size()); //if all of the characters of the smaller string is equal to the first few
        //characters of the bigger string return which one is smaller (true if this* is smaller, false if not)
    }
    else {
        return true; //failsafe return false
    }
}
myString::~myString() {
    if (strArray != NULL) delete [] strArray; //deleting the array
    size = 0; //setting the size to 0
    //cout << "myString object destroyed." << endl; //confirmation that object is destroyed
}

// get one token from redirected input and return that string (alphanumeric)
char* getNextToken () {
    char* str = new char[30]; //assumes a max token size of 20
    emptyString (str, 30);

    char c;
    int i = 0;
    while (!cin.eof()) {
        cin.get(c);
        if (!cin.eof ()) {
            if ((c != '\n') && (c != ' ')) {
                if ( ((c >= 'a') && (c <= 'z')) ||
                     ((c >= 'A') && (c <= 'Z')) ||
                     ((c >= '0') && (c <= '9')) ||
                     (c == '-') || (c == '.' )  ||
                        (c =='_'))
                    str[i++] = c;
            }
            else if ((c == '\n') && (i > 0))
                return str;
            else if ((c == ' ') && (i > 0))
                return str;
        }
    }
    if (i > 0) return str;
    else return NULL;
}

class webLinks {

    friend ostream& operator << (ostream& s, webLinks& A);
protected:
    myString URL; //url, the name of this object
    int numLinks; //number of neighbors
    webLinks** hyperLinks; //"neighbors" to the link
    int counter = 0; //counter to index the hyperlinks thing
    int frequency; //frequency this object is in other hyperLink arrays
public:
    webLinks ();
    webLinks (myString& x, int n);
    ~webLinks ();
    int getNumLinks();
    webLinks* getHyperLink(int i);
    myString& getURL();
    void addSite(myString& t);
    void addNeighbor(webLinks& link);
    void setNumNeighbors(int nei);
    void incrementFrequency();
    int getFreq();
};
ostream& operator << (ostream& s, webLinks& A){
    s << A.URL.getWord() << ":" << endl; //displays the URL with the operator so we dont have to do .getURL() to display the object
    for (int i = 0; i < A.getNumLinks(); ++i) s << "** " << A.getHyperLink(i)->getURL().getWord() << endl; //displaying hyperlinks
    return s; //returning the output stream object
}


webLinks::webLinks() //default constructor
{
    URL = *new myString();
    numLinks = 0;
    hyperLinks = new webLinks *[0];
    frequency = 0;
}

webLinks::webLinks(myString& x, int n) //non-default constructor
{
    URL = x; //initialize url to input
    numLinks = n; //numLinks to input
    hyperLinks = new webLinks *[numLinks]; //hyperLinks to size of input n
    frequency = 0; //frequency to 0
}

myString& webLinks::getURL()
{
    return URL; //getter for url
}

int webLinks::getNumLinks()
{
    return numLinks; //getter for number of neighbors
}

webLinks* webLinks::getHyperLink(int i)
{
    return hyperLinks [i]; //getter for hyperlink at a certain index
}

webLinks::~webLinks() ///GARBAGE COLLECTOR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    //if (URL.getWord() != NULL) URL = NULL;
    numLinks = 0;
    if (hyperLinks != NULL) delete [] hyperLinks;
    //URL = NULL;
    hyperLinks = NULL;
}

void webLinks::addSite(myString& input)
{
    URL = input; //sets the URL variable equal to input
}
int webLinks::getFreq() {
    return frequency; //getter for frequency
}
void webLinks::incrementFrequency() {
    frequency++; //increments frequency variable
}

void webLinks::setNumNeighbors(int nei)
{
    numLinks = nei; //setting number of neighbors
    hyperLinks = new webLinks *[numLinks]; //initializing the hyperlinks array to number of neighbors
}

void webLinks::addNeighbor(webLinks& link)
{
    hyperLinks[counter] = new webLinks(link); //adding the neighbor into hyperLinks array
    counter++; //incrementing the counter so no neighbor is overwritten
}


int main () {

    int numSites;
    int siteNo;
    int numNeighbors;
    int neighbor;

    char* token;
    myString* tokenString;

    cin >> numSites;
    cout << "Number of websites: " << numSites << endl; //displaying the number of websites

    webLinks* myWeb = new webLinks [numSites]; //initializing the array

    token = getNextToken(); //priming the token to read into the for loop

    for (int i=0; i < numSites -1; i++) //numSites - 1 because if i dont do this itll grab the 0 at the beginning of the neighbors line in the input
    {
        tokenString = new myString(token); //making a string out of the char array token
        myWeb[i].addSite(*tokenString); //addding the site to the weblink array
        token = getNextToken(); //getting the next token
    }
    tokenString = new myString(token); //because of the numsites - 1 the last link gets trapped so this will make sure it's added to the array
    myWeb[numSites - 1].addSite(*tokenString); //adding to the array


    // store the neighbours/hyperlinks
    for (int i = 0; i < numSites; i++)
    {
        cin >> siteNo >> numNeighbors;
        myWeb[i].setNumNeighbors(numNeighbors);
        for (int j=0; j < numNeighbors; j++)
        {
            cin >> neighbor;
            myWeb[siteNo].addNeighbor ((myWeb[neighbor]));
        }
    }

    //display all weblink objects normally
    cout << "~~~~~WebLinks:" << endl;
    for(int i = 0; i < numSites; ++i) {
        cout << myWeb[i] << endl;
    }



    // display all webLink objects using the overloaded << operator



    cout << "~~~~~Webpages contained as hyperLinks:" << endl;
    // display all the incoming nodes here
    for (int i = 0; i < numSites; ++i) {
        for(int k = 0; k < numSites; ++k) { //this for loop increments the frequency variable for each link object for each time it's in another links hyperlink array
            for(int l = 0; l < myWeb[k].getNumLinks(); ++l) {
                if (myWeb[i].getURL() == myWeb[k].getHyperLink(l)->getURL()) {
                    myWeb[i].incrementFrequency(); //calling the incrementation method
                }
            }
        }
        cout << myWeb[i].getURL() << ": " << myWeb[i].getFreq() << endl; //this displays the link with the frequency in it using the << operator
        for(int k = 0; k < numSites; ++k) { //this for loop displays each link that has myWeb[i] hyperlinked into it
            for(int l = 0; l < myWeb[k].getNumLinks(); ++l) {
                if (myWeb[i].getURL() == myWeb[k].getHyperLink(l)->getURL()) {
                    cout << "** " << myWeb[k].getURL() << endl; //displaying each link using the overloaded << operator
                }
            }
        }
        cout << endl; //adding a newline after each link displays
    }

    delete [] myWeb; //deleting the myweb array
    //delete [] tokenString;

    return 0;
}