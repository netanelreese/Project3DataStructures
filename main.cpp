// Proejct 3 Spring 2021 Skeleton code

#include<iostream>

using namespace std;

// myString class and corresponding methods come here

class webLinks {

    friend ostream& operator << (ostream& s, webLinks& A);
protected:
    myString URL;
    int numLinks;
    webLinks** hyperLinks;
public:
    webLinks ();
    webLinks (myString& x, int n);
    ~webLinks ();
    int getNumLinks();
    webLinks* getHyperLink(int i);
    myString& getURL();
    void addSite(myString& t);
    void addNeighbor(webLinks& link);
    void setNeighbors(int nei);
};

ostream& operator << (ostream& s, webLinks& A)
{
    //TODO
}

webLinks::webLinks()
{
    //TODO
}

webLinks::webLinks(myString& x, int n)
{
    //TODO
}

myString& webLinks::getURL()
{
    //TODO
}

int webLinks::getNumLinks()
{
    //TODO
}

webLinks* webLinks::getHyperLink(int i)
{
    //TODO
}

webLinks::~webLinks()
{
    //TODO
}

void webLinks::addSite(myString& t)
{
    //TODO
}

void webLinks::setNeighbors(int nei)
{
    //TODO
}

void webLinks::addNeighbor(webLinks& link)
{
    //TODO
}

int main () {

    int numSites;
    int siteNo;
    int numNeighbors;
    int neighbor;

    char* token;
    myString* tokenString;

    cin >> numSites;
    cout << "Number of websites: " << numSites << endl;

    webLinks* myWeb = new webLinks [numSites];
    for (int i=0; i < numSites; i++)
    {
        // read all URL and store them in the myWeb array of webLink objects
    }

    // store the neighbours/hyperlinks
    for (int i = 0; i < numSites; i++)
    {
        cin >> siteNo >> numNeighbors;
        myWeb[i].setNeighbors(numNeighbors);
        for (int j=0; j < numNeighbors; j++)
        {
            cin >> neighbor;
            myWeb[siteNo].addNeighbor ((myWeb[neighbor]));
        }
    }

    // display all webLink objects using the overloaded << operator

    cout << "~~~~~Webpages contained as hyperLinks:" << endl;
    // display all the incoming nodes here

    delete [] myWeb;

    return 0;
}