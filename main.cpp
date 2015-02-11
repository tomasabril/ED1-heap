#include <iostream>

#include <cstdlib>

#include <vector>

#include <iterator>

using namespace std;

/*

 * Class Declaration

 */

class BinaryHeap

{

protected:

    vector <int> heap;

    vector <int> matriz;

    int left(int parent);

    int right(int parent);

    int parent(int child);

    int left1(int parent);

    int right1(int parent);

    int parent1(int child);


public:

    BinaryHeap()

    {}

    void Insert(int element);

    void Insertmatriz(int elementmatriz);

    void DeleteMin();

    void DisplayHeap();

    int Size();

    int Sizem();

    void Down(int i , int n);

    void Builheap();

    void up(int i);

    void DisplayHeap1();

    void Down1(int i , int n );

    int findout(int element);



};

/*

 * Return Heap Size

 */

int BinaryHeap::Size()

{

    return heap.size();


}
int BinaryHeap::Sizem()

{

    return matriz.size();


}


/*

 * Insert Element into matriz
 */


void BinaryHeap::Insertmatriz(int elementmatriz)

{

    matriz.push_back(elementmatriz);



    /*

     * Reorganize Matriz down to up

     */
}

void BinaryHeap::Down(int i , int n )

{


    int child;

    if(right(i)<= n && (matriz[right(i)] > matriz[left(i)]))

    {

        child = right(i);

    }
    else
    {
        child = left(i);
    }

    if (child < n && matriz[child]> matriz[i])

    {

        int temp = matriz[i];

        matriz[i] = matriz[child];

        matriz[child] = temp;

        Down(child, n);

    }

}
/*

 * Reorganize heap down to up

 */
void BinaryHeap::Down1(int i , int n )

{


    int child;

    if(right1(i)<= n && (heap[right1(i)] > heap[left1(i)]))

    {

        child = right1(i);

    }
    else
    {
        child = left1(i);
    }

    if (child < n && (heap[child]> heap[i]))

    {

        int temp = heap[i];

        heap[i] = heap[child];

        heap[child] = temp;

        Down1(child, n);

    }

}

/*

 *  Build heap using method Down

 */


void  BinaryHeap::Builheap()
{
   /* vector <int> tmp ;
    tmp= matriz;
    int n =  matriz.size();

    for(int i = (n /2)-1; i >= 0 ; i--)
    {
        Down(i, n);
    }
    heap = matriz;
    matriz=tmp;
    */
    int n =  matriz.size();

    for(int i =0; i <n ; i++){
        Insert(matriz[i]);
    }
}

/*
 * Insert Element into a Heap
 */

void BinaryHeap::Insert(int element)

{

    heap.push_back(element);

    up(heap.size()- 1);

}

/*

 * Reorganize heap up to down

 */

void  BinaryHeap:: up( int i)
{

    if(i >= 1 &&(heap[parent(i)]<heap[i]))
    {
        int temp = heap[i];

        heap[i] = heap[parent1(i)];

        heap[parent1(i)] = temp;

        up(parent(i));

    }




}

/*

 * Return left Child heap

 */


int BinaryHeap::left1(int parent)

{

    int l = 2 * parent + 1;

    if (l < heap.size())

        return l;

    else

        return -1;

}

/*

 * Return parent heap

 */

int BinaryHeap::parent1(int child)

{

    int p = (child - 1)/2;

    if (child == 0)

        return -1;

    else

        return p;

}



/*

 * Return Right Child heap

 */

int BinaryHeap::right1(int parent)

{

    int r = 2 * parent + 2;

    if (r < heap.size())

        return r;

    else

        return -1;

}

/*

 * Delete root heap

 */

void BinaryHeap::DeleteMin()

{

    if (heap.size() == 0)

    {

        cout<<"Heap is Empty"<<endl;

        return;

    }

    heap[0] = heap.at(heap.size() - 1);

    heap.pop_back();

    Down1(0, heap.size());



    cout<<"Element Deleted"<<endl;

}

/*

 * Display Matriz

 */

void BinaryHeap::DisplayHeap()

{
    vector <int>::iterator pos = matriz.begin();

    cout<<"Matriz -->  ";

    while (pos != matriz.end())

    {

        cout<<*pos<<" ";

        pos++;

    }

    cout<<endl;



}

/*

 * Displayed heap

 */
void BinaryHeap::DisplayHeap1()

{
    int i =0;

    //cout<<"Heap -->  ";
    cout<<endl;

    cout<<"Raiz: "<< heap[i];
    cout<<" FD:"<< heap[right1(i)];
    cout<<" FE:"<< heap[left1(i)];
    cout<<endl;
    i++;
    for(; i < heap.size() ; i ++)
    {

        cout<<" Nó : "<< heap[i];
        cout<<" FD:"<< heap[right1(i)];
        cout<<" FE:"<< heap[left1(i)];
        cout<<endl;

    }


}



/*

 * Return Left Child matriz

 */

int BinaryHeap::left(int parent )

{

    int l = 2 * parent + 1;

    if (l < matriz.size())

        return l;

    else

        return -1;

}



/*

 * Return Right Child matriz
 */

int BinaryHeap::right(int parent)

{

    int r = 2 * parent + 2;

    if (r < matriz.size())

        return r;

    else

        return -1;

}




/*

 * Return Parent Matriz

 */

int BinaryHeap::parent(int child)

{

    int p = (child - 1)/2;

    if (child == 0)

        return -1;

    else

        return p;

}

/*

 * search element heap

 */

int BinaryHeap::findout(int element)
{

    for(int i = 0; i <= heap.size() -1 ; i++)
    {
        if(heap[i] == element)
        {
            cout<<"Element found "<< heap[i]<<endl;
            cout<<"Index of element:"<<i<<endl;
            cout<<"Child right"<< heap[right1(i)]<<endl;
            cout<<"Child left "<< heap[left1(i)]<<endl;



            break;
        }
        if(i == heap.size()-1)
        {
            cout<< "Element does not exist"<<endl;
            break ;

        }
    }



}







/*

 * Main Contains Menu

 */

int main()

{

    BinaryHeap h;

    while (1)

    {

        cout<<"------------------"<<endl;

        cout<<"------------------"<<endl;

        cout<<"1.Inserir elementos em uma matriz unidimensional"<<endl;

        cout<<"2.Inserir elementos na heap"<<endl;

        cout<<"3.busca de elementos "<<endl;

        cout<<"4.Remocao de elemenntos "<<endl;

        cout<<"5.criar uma heap "<<endl;

        cout<<"6.exit "<<endl;

        cout<<"7.Apresentação da árvore heap "<<endl;

        cout<<"8.Apresentação da matriz unidimensional "<<endl;

        cout<<"------------------"<<endl;

        cout<<"------------------"<<endl;


        int choice, element, elementmatriz;

        cout<<"Enter your choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Enter the element to be inserted : ";

            cin>>elementmatriz;

            h.Insertmatriz(elementmatriz);

            break;


        case 2:

            cout<<"Enter the element to be inserted : ";

            cin>>element;

            h.Insert(element);

            break;
        case 3:

            cout << "Enter the element to be search :";

            cin>>element;

            h.findout(element);

            break;

        case 4:

            h.DeleteMin();

            break;

        case 5:

            h.Builheap();

            break;

        case 6:

            exit(1);

            break;


        case 7:

            if (h.Size() == 0)

            {

                cout<<"Heap is Empty"<<endl;

            }

            else
            {

                cout<<"Displaying elements of Heap:  ";


                h.DisplayHeap1();


            }
            break;


        case 8:

            if (h.Sizem() == 0)

            {

                cout<<" Matriz is Empty"<<endl;

            }

            else
            {
                cout<<"Displaying elements of matriz Unidimensional:  ";

                h.DisplayHeap();

            }
            break;

        default:

            cout<<"Enter Correct Choice"<<endl;


        }



    }
    return 0;
}


