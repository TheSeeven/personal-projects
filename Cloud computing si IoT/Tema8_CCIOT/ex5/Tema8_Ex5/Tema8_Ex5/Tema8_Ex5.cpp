// Tema8_Ex5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct AbstractField {
    virtual ~AbstractField() {}
};

enum class SUBSCRIPTION_CATEGORY{
    MOTNTH1,
    MOTNTH3,
    MOTNTH6,
    MOTNTH12,
};
class YouTube {
private:
    const string name = "YouTube";
    const int pricePerMonth = 7;
    SUBSCRIPTION_CATEGORY category;
public:
    YouTube(SUBSCRIPTION_CATEGORY category) {
        this->category = category;
    }
    ~YouTube() {}

    float getPrice() {
        if ( category == SUBSCRIPTION_CATEGORY::MOTNTH1 ) {
            return 1.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH3 ) {
            return 3.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH6 ) {
            return (6.0 * pricePerMonth) * 0.9;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH12 ) {
            return (12.0 * pricePerMonth) * 0.75;
        }
        return -1;
    }
    string getName() { return this->name; }

};
class Netflix {
private:
    const string name = "Netflix";
    const int pricePerMonth = 6;
    SUBSCRIPTION_CATEGORY category;
public:

    Netflix(SUBSCRIPTION_CATEGORY category) {
        this->category = category;
    }
    ~Netflix() {}
    float getPrice() {
        if ( category == SUBSCRIPTION_CATEGORY::MOTNTH1 ) {
            return 1.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH3 ) {
            return 3.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH6 ) {
            return (6.0 * pricePerMonth) * 0.8;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH12 ) {
            return (12.0 * pricePerMonth) * 0.7;
        }
        return -1;
    }
    string getName() { return this->name; }
};
class HBOGo {
private:
    const string name = "HBOGo";
    const int pricePerMonth = 6;
    SUBSCRIPTION_CATEGORY category;
public:

    HBOGo(SUBSCRIPTION_CATEGORY category) {
        this->category = category;
    }
    ~HBOGo() {}
    float getPrice() {
        if ( category == SUBSCRIPTION_CATEGORY::MOTNTH1 ) {
            return 1.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH3 ) {
            return 3.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH6 ) {
            return (6.0 * pricePerMonth) * 0.9;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH12 ) {
            return (12.0 * pricePerMonth) * 0.75;
        }
        return -1;
    }
    string getName() { return this->name; }
};
class PrimeVideo {
private:
    const string name = "PrimeVideo";
    const int pricePerMonth = 12;
    SUBSCRIPTION_CATEGORY category;
public:

    PrimeVideo(SUBSCRIPTION_CATEGORY category) {
        this->category = category;
    }
    ~PrimeVideo() {}
    float getPrice() {
        if ( category == SUBSCRIPTION_CATEGORY::MOTNTH1 ) {
            return 1.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH3 ) {
            return 3.0 * pricePerMonth;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH6 ) {
            return (6.0 * pricePerMonth) * 0.8;
        }
        else if ( category == SUBSCRIPTION_CATEGORY::MOTNTH12 ) {
            return (12.0 * pricePerMonth) * 0.70;
        }
        return -1;
    }
    string getName() { return this->name; }
};



template <typename StreamingService>
class Subscription : public AbstractField {
private:
    string name = "";
    float price = 0;
    bool active = false;
    int months = 0;
    StreamingService* streamingService;

    int getNumberOfMonths(SUBSCRIPTION_CATEGORY timePeriod) {
        if ( timePeriod == SUBSCRIPTION_CATEGORY::MOTNTH1 ) {
            return 1;
        }
        else if ( timePeriod == SUBSCRIPTION_CATEGORY::MOTNTH3 ) {
            return 3;
        }
        else if ( timePeriod == SUBSCRIPTION_CATEGORY::MOTNTH6 ) {
            return 6;
        }
        else if ( timePeriod == SUBSCRIPTION_CATEGORY::MOTNTH12 ) {
            return 12;
        }
        return -1;
    }

public:
    Subscription() {}
    Subscription(string name, bool active, SUBSCRIPTION_CATEGORY timePeriod) {
        this->name = name;
        this->months = getNumberOfMonths(timePeriod);
        this->active = active;
        this->streamingService = new StreamingService(timePeriod);
        this->price = streamingService->getPrice();
    }
    Subscription(string name, SUBSCRIPTION_CATEGORY timePeriod) {
        this->name = name;
        this->months = getNumberOfMonths(timePeriod);
        this->streamingService = new StreamingService(timePeriod);
        this->price = streamingService->getPrice();

    }
    virtual ~Subscription() {}

    string getName() { return this->name; }
    float getPrice() { return this->price; }
    bool isActive() { return this->active; }
    int getMonths() { return this->months; }
    string getSubscriptionName() { return this->streamingService->getName(); }

    friend ostream& operator << (ostream& out, Subscription<StreamingService>& obj) {
        return out << "Name: " << obj.getName() << " | Months: " << obj.getMonths() << " | Price: $" << obj.getPrice() << " | Subscription: " << obj.getSubscriptionName() << " | Active: " << obj.isActive();
    }

    virtual string test() { return "test"; }

};

void printSubscriptionList(vector<AbstractField*> &subscriptionList) {
    for ( AbstractField* i: subscriptionList ) {
        Subscription<YouTube>* youtube = NULL;
        Subscription<PrimeVideo>* primeVideo = NULL;
        Subscription<HBOGo>* hbo = NULL;
        Subscription<Netflix>* netflix = NULL;

        youtube = dynamic_cast<Subscription<YouTube>*>(i);
        primeVideo = dynamic_cast<Subscription<PrimeVideo>*>(i);
        hbo = dynamic_cast<Subscription<HBOGo>*>(i);
        netflix = dynamic_cast<Subscription<Netflix>*>(i);
        if ( youtube != NULL ) {
            cout << *youtube;
        }
        else if ( primeVideo != NULL ) {
            cout << *primeVideo;
        }
        else if ( hbo != NULL ) {
            cout << *hbo;
        }
        else if ( netflix != NULL ) {
            cout << *netflix;
        }
        cout << endl;
    }
}

void printCheapestService(vector<AbstractField*>& subscriptionList) {
    unsigned int min = ~0;
    int counter = 0;
    int arrsize = subscriptionList.size();
    AbstractField* temp = NULL;
    for ( AbstractField* i : subscriptionList ) {
        
        Subscription<YouTube>* youtube = NULL;
        Subscription<PrimeVideo>* primeVideo = NULL;
        Subscription<HBOGo>* hbo = NULL;
        Subscription<Netflix>* netflix = NULL;

        youtube = dynamic_cast<Subscription<YouTube>*>(i);
        primeVideo = dynamic_cast<Subscription<PrimeVideo>*>(i);
        hbo = dynamic_cast<Subscription<HBOGo>*>(i);
        netflix = dynamic_cast<Subscription<Netflix>*>(i);
        if ( youtube != NULL ) {
            if ( youtube->getPrice() < min ) {
                temp = i;
                min = youtube->getPrice();
            }
        }
        else if ( primeVideo != NULL ) {
            if ( primeVideo->getPrice() < min ) {
                temp = i;
                min = primeVideo->getPrice(); 
            }
        }
        else if ( hbo != NULL ) {
            if ( hbo->getPrice() < min ) {
                temp = i;
                min = hbo->getPrice();
            }

        }
        else if ( netflix != NULL ) {
            if ( netflix->getPrice() < min ) {
                temp = i;
                min = netflix->getPrice();
            }
        }

        counter++;

        if ( counter == arrsize - 1 ) {
            netflix = dynamic_cast<Subscription<Netflix>*>(temp);
            youtube = dynamic_cast<Subscription<YouTube>*>(temp);
            hbo = dynamic_cast<Subscription<HBOGo>*>(temp);
            primeVideo = dynamic_cast<Subscription<PrimeVideo>*>(temp);
            if( netflix != NULL)
                cout << "The service " << *netflix << " is the cheapest with price: " << min << endl;
            else if(youtube!=NULL)
                cout << "The service " << *youtube << " is the cheapest with price: " << min << endl;
            else if(hbo != NULL)
                cout << "The service " << *hbo << " is the cheapest with price: " << min << endl;
            else if(primeVideo!=NULL)
                cout << "The service " << *primeVideo << " is the cheapest with price: " << min << endl;
        }

    }
}

void printLongestSubscription(vector<AbstractField*>& subscriptionList) {
    unsigned int max = 0;
    int counter = 0;
    int arrsize = subscriptionList.size();
    AbstractField* temp = NULL;
    for ( AbstractField* i : subscriptionList ) {
        Subscription<YouTube>* youtube = NULL;
        Subscription<PrimeVideo>* primeVideo = NULL;
        Subscription<HBOGo>* hbo = NULL;
        Subscription<Netflix>* netflix = NULL;

        youtube = dynamic_cast<Subscription<YouTube>*>(i);
        primeVideo = dynamic_cast<Subscription<PrimeVideo>*>(i);
        hbo = dynamic_cast<Subscription<HBOGo>*>(i);
        netflix = dynamic_cast<Subscription<Netflix>*>(i);
        if ( youtube != NULL ) {
            if ( youtube->isActive()) {
                if ( youtube->getMonths() > max ) {
                    max = youtube->getMonths();
                    temp = i;
                }
            }  
        }
        else if ( primeVideo != NULL ) {
            if ( primeVideo->isActive() ) {
                if ( primeVideo->getMonths() > max ) {
                    max = primeVideo->getMonths();
                    temp = i;
                }
            }
        }
        else if ( hbo != NULL ) {
            if ( hbo->isActive() ) {
                if ( hbo->getMonths() > max ) {
                    max = hbo->getMonths();
                    temp = i;
                }
            }
        }
        else if ( netflix != NULL ) {
            if ( netflix->isActive() ) {
                if ( netflix->getMonths() > max ) {
                    max = netflix->getMonths();
                    temp = i;
                }
            }
        }
        if ( counter == arrsize - 1 ) {
            netflix = dynamic_cast<Subscription<Netflix>*>(temp);
            youtube = dynamic_cast<Subscription<YouTube>*>(temp);
            hbo = dynamic_cast<Subscription<HBOGo>*>(temp);
            primeVideo = dynamic_cast<Subscription<PrimeVideo>*>(temp);
            if ( netflix != NULL )
                cout << "The user with the longest subscription: " << netflix->getName() << endl;
            else if ( youtube != NULL )
                cout << "The user with the longest subscription: " << youtube->getName() << endl;
            else if ( hbo != NULL )
                cout << "The user with the longest subscription: " << hbo->getName() << endl;
            else if ( primeVideo != NULL )
                cout << "The user with the longest subscription: " << primeVideo->getName() << endl;
        }
        counter++;

    }
}

int main()
{

    vector<AbstractField*> subscriptionList;
    subscriptionList.push_back(new Subscription<YouTube>("Mircea Cosbuc", true, SUBSCRIPTION_CATEGORY::MOTNTH6));
    subscriptionList.push_back(new Subscription<Netflix>("Mihai Eminem", false, SUBSCRIPTION_CATEGORY::MOTNTH12));
    subscriptionList.push_back(new Subscription<HBOGo>("Dimitri Stovaiov", true, SUBSCRIPTION_CATEGORY::MOTNTH3));
    subscriptionList.push_back(new Subscription<PrimeVideo>("Nichita Stanescu", true, SUBSCRIPTION_CATEGORY::MOTNTH12));
    subscriptionList.push_back(new Subscription<YouTube>("Aline Bony", true, SUBSCRIPTION_CATEGORY::MOTNTH1));
    subscriptionList.push_back(new Subscription<Netflix>("George Hertzevan", true, SUBSCRIPTION_CATEGORY::MOTNTH6));
    subscriptionList.push_back(new Subscription<YouTube>("Kamill Petrescu", true, SUBSCRIPTION_CATEGORY::MOTNTH3));
    subscriptionList.push_back(new Subscription<YouTube>("Esperanzo Espreso", true, SUBSCRIPTION_CATEGORY::MOTNTH6));
    subscriptionList.push_back(new Subscription<HBOGo>("Adriana Popescu", true, SUBSCRIPTION_CATEGORY::MOTNTH1));
    subscriptionList.push_back(new Subscription<PrimeVideo>("Maria Chistoc", false, SUBSCRIPTION_CATEGORY::MOTNTH12));
    
    
    
    printSubscriptionList(subscriptionList);
    printCheapestService(subscriptionList);
    printLongestSubscription(subscriptionList);
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
