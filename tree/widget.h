#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"dialog1.h"
#include"dialoge.h"
#include"dialogd.h"
#include"dialogt.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//自己定义的数据结构
typedef struct {
    QChar ch;
    int weight;
    int parent, lchild, rchild;
}HuffmanTree;

typedef struct {
    int loc;
    int enter;
}Data;

typedef struct{
    Data *data;
    int front;
    int tail;
}Queue;

typedef char** huffmanCode;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_BtnI_clicked();

    void on_okBtn_clicked();

//    void on_finishBtn_clicked();

    void on_encodeBtn_clicked();

    void on_decodeBtn_clicked();

    void on_printBtn_clicked();

private:
    HuffmanTree* readFromTree(int &n);
    void turu(HuffmanTree* T, int i, int t);
    void shuform(HuffmanTree* T, int i, int t);
    void shuform2(HuffmanTree* T, int n,Queue &Q);
    void TreePrint(HuffmanTree* &T,int n);
    void Encode(HuffmanTree* HT, huffmanCode HC,int n);
    void createHuffmanCode(HuffmanTree* HT, huffmanCode &HC, int n);
    void Decode(HuffmanTree* T,int n);
    int searchmin(HuffmanTree* T,int k)
    {
        int min = 99999;
        int loc = 0;
        for (int i = 1; i < k; i++)
        {
            if (T[i].parent == 0 && T[i].weight < min)
            {
                min = T[i].weight;
                loc = i;
            }
        }
        T[loc].parent = k;
        return loc;
    }
    Ui::Widget *ui;
    DialogT*dialogt=new DialogT;
    Dialog1 *dialog1=new Dialog1;
    DialogE *dialoge=new DialogE;
    DialogD*dialogd=new DialogD;
    HuffmanTree*T=NULL;
    huffmanCode HC;
    int n=0;
    int InputStatus=0;
    int loc=0;
};
#endif // WIDGET_H
