#include<iostream>
using namespace std;

class queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        queue()
        {
            front =-1;
            rear = -1;
            for(int i = 0; i<5; i++)
            {
                arr[i]=0;
            }
        }

        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if(rear==4)
                return true;
            else
                return false;          
        }

        void Enqueue(int value)
        {
            if (isFull())
            {
                cout << "Queue is Full" <<endl;
                return;
            }

            else if (isEmpty())
            {
                rear=0;
                front=0;
                arr[rear]=value;
            }

            else
            {
                rear++;
                arr[rear]=value;
            }
        }

        int Dequeue()
        {
            int x;
            if (isEmpty())
            {
                cout << "Queue is empty" <<endl;
                return 0;
            }

            else if(front==rear)
            {
                x = arr[front];
                arr[front] = 0;
                rear =-1;
                front =-1;
                return x;
            }

            else
            {
                x= arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        int count()
        {
            return (rear-front+1);
        }

        void display()
        {
            cout << "All values in the queue are - " <<endl;
            for(int i =0; i<5; i++)
            {
                cout <<arr[i]<<" ";
            }
        }
};

int main() {

    queue q1;
    int option, value;

    do
    {
        cout << "\n\n what operation do you want to pefrform? select option number. Enter 0 to exit." <<endl;
        cout << "1. Enqueue()" <<endl;
        cout << "2. Dequeue()" <<endl;
        cout << "3. isEmpty()" <<endl;
        cout << "4. isFull()" <<endl;
        cout << "5. count()" <<endl;
        cout << "6. display()" <<endl;
        cout << "7. clear Screen()" <<endl <<endl;

        cin >> option;

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "Enqueue Operation"<<endl;
                cin >> value;
                q1.Enqueue(value);
                break;

            case 2:
                cout << "Dequeue Operation" <<endl;
                cout << q1.Dequeue() <<endl;
                break;

            case 3:
                if(q1.isEmpty())
                    cout << "Queue is empty" <<endl;
                else
                    cout << "Queue is not empty" <<endl;
                break;

            case 4:
                if(q1.isFull())
                    cout << "Queue is Full" <<endl;
                else
                    cout << "Queue is not Full" <<endl;
                break;

            case 5:
                cout << "count operation : " <<q1.count() <<endl;
                break;

            case 6:
                cout << "Display function called" <<endl;
                q1.display();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Invalid option number" <<endl;
                break;  
        } 
    }

    while (option!=0);

    return 0;
}