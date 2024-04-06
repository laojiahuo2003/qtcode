#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("哈夫曼树");
    this->setStyleSheet("QPushButton{color:red;background:rgb(255 222 173)}"
                  "QPushButton::hover{background:rgb(255 222 173);}"
                  "QPushButton::pressed{background:rgb(255 248 220);}");
    this->show();
    ui->label1->setText("");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_BtnI_clicked()
{
    ui->label1->setText("输入n");
    n=0;
}

void Widget::on_okBtn_clicked()
{
    QString inputText=ui->lineEdit->text();
    if(loc==0){
        n=inputText.toInt();
        qDebug()<<n;
        T = new HuffmanTree[n * 2];//从1开始,2n-1结束
        //全部初始化为0
        for (int i = 1; i <= n * 2 - 1; i++)
        {
            T[i].lchild = 0;
            T[i].parent = 0;
            T[i].rchild = 0;
            T[i].weight = 0;
            T[i].ch = '\0';
        }
        loc=1;
        ui->label1->setText("输入第"+QString::number(loc)+"字母与权重");
        return;
    }

        QChar character = inputText.at(0); // 获取第一个字符
        QString numberString = inputText.mid(1); // 获取从第二个字符开始到末尾的子字符串
        int w=numberString.toInt();
        qDebug()<<character<<w;
        T[loc].ch=character;
        T[loc].weight=w;
          loc++;
          ui->label1->setText("输入第"+QString::number(loc)+"字母与权重");
        if(loc>n)
    {
        ui->label1->setText("初始化完成");
        //开始创建哈夫曼树
        for (int k = n + 1; k <= 2 * n - 1; k++)
        {
            //选出没有双亲的两个最小权值的结点
            int lc =searchmin(T,k);
            int rc = searchmin(T,k);
            if (lc > rc)
            {
                int t = lc;
                lc = rc;
                rc = t;
            }
            T[k].lchild = lc;
            T[k].rchild = rc;
            T[k].weight = T[lc].weight + T[rc].weight;
        }
        FILE* f;
        f = fopen("hfmTree.txt", "w");
        fprintf(f, "%d\n", n);
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            fprintf(f, "%d  ", i);
            fprintf(f, "%c  ",T[i].ch);
            fprintf(f, "%d  ", T[i].weight);
            fprintf(f, "%d  ", T[i].parent);
            fprintf(f, "%d  ", T[i].lchild);
            fprintf(f, "%d\n", T[i].rchild);
        }
        fclose(f);
        dialog1->loadFileAndDisplay("C:\\Users\\29443\\Desktop\\qtproject\\build-tree-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\hfmTree.txt");
        dialog1->show();
   }
}

HuffmanTree* Widget::readFromTree(int &n)
{
    FILE* f = fopen("hfmTree.txt", "r");
    fscanf(f, "%d\n", &n);
    HuffmanTree* T = new HuffmanTree[n * 2];
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int j;
        fscanf(f, "%d ", &j);
        fscanf(f, "%c ", &T[i].ch);
        fscanf(f, "%d ", &T[i].weight);
        fscanf(f, "%d ", &T[i].parent);
        fscanf(f, "%d ", &T[i].lchild);
        fscanf(f, "%d\n", &T[i].rchild);
    }
    fclose(f);
    return T;
}
void Widget::createHuffmanCode(HuffmanTree* HT, huffmanCode &HC, int n)
{
    //申请n + 1个huffmanCode大小huffmanCode类型的临时空间
    HC = (huffmanCode)malloc(sizeof(huffmanCode) * n + 1);
    char* cd = (char*)malloc(sizeof(char) * n);
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; i++)//代表叶子结点
    {
        int pre = i;//双亲结点下标
        int pnow = i;
        int st = n - 1;//记录cd字符串数组的当前记录的位置
        while (HT[pre].parent != 0)
        {
            pnow = HT[pre].parent;
            if (HT[pnow].lchild == pre)
            {
                //添加0
                cd[--st] = '0';
            }
            else if (HT[pnow].rchild == pre)
            {
                //添加1
                cd[--st] = '1';
            }
            pre = pnow;
        }
        HC[i] = new char [n - st];
        strcpy(HC[i], &cd[st]);//每个字符串都要复制到HC中
    }
    delete []cd;
    //输出测试
    for (int i = 1; i <= n; i++)
    {
        dialoge->addcode(T[i].ch,HC[i]);
        qDebug() <<T[i].ch <<HC[i];
    }
}
void Widget::Encode(HuffmanTree* HT, huffmanCode HC,int n)
{
    FILE* p = fopen("tobetran.txt", "r");
    FILE* q = fopen("codefile.txt", "w");
    char c;
    fclose(p);
//    cout << "哈夫曼编码为" << endl;
    p = fopen("tobetran.txt", "r");
    while ((c = fgetc(p)) != EOF)
    {
        if (c == ' ')
        {
            fprintf(q, "%c", ' ');
        }
        for (int i = 1; i <= n; i++)
        {
            if (HT[i].ch == c)
            {
                fprintf(q, "%s", HC[i]);
            }
        }
    }
    fclose(p);
    fclose(q);
}
void Widget::on_encodeBtn_clicked()
{
    if (T == NULL)
    {
        qDebug()<<"内存中树为空，在文件hfmTree中读取...." ;
        ui->label1->setText("内存中树为空，在文件hfmTree中读取....");
        T=readFromTree(n);
    }
    createHuffmanCode(T, HC, n);
    Encode(T, HC, n);

    dialoge->Myshow();
    dialoge->show();
}



void Widget::Decode(HuffmanTree* T,int n) {
    FILE* p = fopen("TextFile.txt", "w");
    FILE*code= fopen("codefile.txt", "r");
    char c;
    int i = 2 * n - 1;
    while ((c = fgetc(code)) != EOF)
    {
        if (c == '0')
        {
            i = T[i].lchild;
        }
        else if (c == '1')
        {
            i = T[i].rchild;
        }
        if (T[i].ch != '\0')
        {
            fprintf(p, "%c", T[i].ch);
            i = 2 * n - 1;
        }
    }
    fclose(code);
    fclose(p);
}

void Widget::on_decodeBtn_clicked()
{
    if(T==NULL) {qDebug()<<"当前无哈夫曼树信息，解码失败";
                ui->label1->setText("当前无哈夫曼树信息，解码失败");
        return;}
    Decode(T,n);
    dialogd->Myshow();
    dialogd->show();
}


//突入表形式(i代表当前哈夫曼树下标，t代表空格数量)
void Widget::turu(HuffmanTree* T, int i, int t)
{
    FILE* Tp = fopen("TreePrint.txt", "a");
    if (i == 0) return;
    for (int j = 0; j < t; j++)
    {
        fprintf(Tp, "%c", '\t');
    }
    fprintf(Tp, "%d\n", T[i].weight);
    fclose(Tp);
    turu(T, T[i].lchild, t + 1);
    turu(T, T[i].rchild, t + 1);
}
//树状形式
void Widget::shuform(HuffmanTree* T, int i, int t)
{
    FILE* Tp = fopen("TreePrint.txt", "a+");
    if (i == 0) return;
    for (int j = 0; j < t; j++)
    {
        fprintf(Tp, "%c", '\t');
    }
    fprintf(Tp, "%d\n", T[i].weight);
    fclose(Tp);
    shuform(T, T[i].lchild, t - 1);
    shuform(T, T[i].rchild, t + 1);
}
//队列实现树状打印
void Widget::shuform2(HuffmanTree* T, int n,Queue &Q)
{
    FILE* Tp = fopen("TreePrint.txt", "a+");
    int sbloc = 0;
    Q.data[Q.tail].enter = n;
    Q.data[Q.tail++].loc = 2*n-1;//储存T的下标
    while (Q.tail - Q.front != 0)
    {
        int size = Q.tail - Q.front;//代表每层的个数
        for (int i = 0; i < size; i++)
        {
            //双亲结点
            int enter_num = Q.data[Q.front].enter;
            int par = Q.data[Q.front++].loc;
            //空格数量
            for (int j = sbloc;j < enter_num; j++)
            {
                fprintf(Tp, "%c", ' ');
                sbloc++;
            }
            fprintf(Tp, "%d", T[par].weight);
            sbloc++;
            //双亲结点出队，孩子节点入队
            if (T[par].lchild != 0)
            {
                Q.data[Q.tail].enter = enter_num - 4;
                Q.data[Q.tail++].loc = T[par].lchild;
            }
            if (T[par].rchild != 0)
            {
                Q.data[Q.tail].enter = enter_num + 4;
                Q.data[Q.tail++].loc = T[par].rchild;
            }
        }
        fprintf(Tp, "%c", '\n');
        sbloc = 0;
    }
    fclose(Tp);
}
//打印内存中的哈夫曼树,以直观的方式显示，同时存入TreePrint.txt中
void Widget::TreePrint(HuffmanTree* &T,int n)
{
    if (T == NULL)
    {
        ui->label1->setText("读取文件中的树...");
        FILE* hfmT = fopen("hfmTree.txt", "r");
        fscanf(hfmT, "%d", &n);
        T = new HuffmanTree[n * 2];
        //哈夫曼数组全部初始化为0
        for (int i = 1; i <= n * 2 - 1; i++)
        {
            T[i].lchild = 0;
            T[i].parent = 0;
            T[i].rchild = 0;
            T[i].weight = 0;
            T[i].ch = '\0';
        }
        //读取哈夫曼树
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int j;//吸收字符
            fscanf(hfmT, "%d ", &j);
            fscanf(hfmT, "%c ", &T[i].ch);
            fscanf(hfmT, "%d ", &T[i].weight);
            fscanf(hfmT, "%d ", &T[i].parent);
            fscanf(hfmT, "%d ", &T[i].lchild);
            fscanf(hfmT, "%d\n", &T[i].rchild);
        }
        fclose(hfmT);
    }
    else    ui->label1->setText("读取内存中的树");

    FILE* Tp = fopen("TreePrint.txt", "w");
    fclose(Tp);
//    cout << "哈夫曼树凹入表" << endl;
    Tp = fopen("TreePrint.txt", "a+");
    fprintf(Tp,"%s","哈夫曼树凹入表\n");
    fclose(Tp);
    //存入TreePrint.txt
    turu(T, 2*n-1,0);
//    cout << "递归打印树" << endl;
    Tp = fopen("TreePrint.txt", "a+");
    fprintf(Tp,"%s","递归打印树\n");
    fclose(Tp);
    shuform(T, 2 * n - 1, n / 2+1);
    Queue Q;    Q.data = new Data[n]; Q.front = 0; Q.tail = 0;
//    cout << "队列打印树" << endl;
    Tp = fopen("TreePrint.txt", "a+");
    fprintf(Tp,"%s","队列打印树\n");
    fclose(Tp);
    shuform2(T, n, Q);
}

void Widget::on_printBtn_clicked()
{
    if(T==NULL) {qDebug()<<"当前无哈夫曼树信息，打印失败";
        ui->label1->setText("当前无哈夫曼树信息，打印失败");
        return;}
    TreePrint(T,n);
    dialogt->Myshow();
    dialogt->show();
}

