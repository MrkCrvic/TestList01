#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H

#include <QDebug>
//#include <assert.h>
#include <cassert>
#include <QtGlobal>

template <class T>
class TemplateList
{
private:
    T data;
    TemplateList * next;

public:
    TemplateList(T dataa)
        : data(dataa), next(NULL)
    {}

    void append(T _data)
    {
        TemplateList * newNode = new TemplateList(_data);
        TemplateList * pom = this;
        while(pom->next!=NULL)
            pom = pom->next;
        pom->next = newNode;
        //qDebug() << pom->next->getData();

    }

    T getData()
    {
        return this->data;
    }

    T at(int index)
    {
        // ako se stavi assert ovdje onda nam nije potrebno try-catch


        //qDebug() << "Number is:";
        try
        {
            TemplateList * pom = this;
            for(int i = 0; i < index; i++)
            {
                pom = pom->next;
                if(pom == NULL)
                    throw 9;
            }
            //qDebug() << "Number is:";
            return pom->data;
        }
        catch(int e)
        {
            qFatal("ASSERT failure in TemplateList<T>::at : 'Index out of range'");
            //qDebug() << ;
            assert (false);
        }
    }

    void printList()
    {
        TemplateList * pom = this;
        while(pom != NULL)
        {
            qDebug() << pom->data;
            pom = pom->next;
        }
    }

    int list_length()
    {
        int m = 1;
        TemplateList * pom = this;
        while(pom->next != NULL)
        {
            pom = pom->next;
            m++;
        }
        return m;
    }

    int index(T t)
    {
        // returns -1 if element is not in the list
        TemplateList * pom = this;
        int k = -1;
        while(pom != NULL)
        {
            k++;
            if(pom->data == t)
                return k;
            pom = pom->next;
        }
        k = -1;
        return k;
    }

    void pop()
    {
        TemplateList * pom = this;
        // tester zna da imaju minimum 2 elementa kada krene da radi pop()
        while(pom->next->next != NULL)
        {
            pom = pom->next;
        }

        delete pom->next;
        pom->next = NULL;

    }


};

#endif // TEMPLATELIST_H
