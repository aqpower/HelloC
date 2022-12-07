// 做一个成绩管理小系统，具备基础的增删查改功能
#include <stdlib.h>

#include <cstring>
#include <iostream>
using namespace std;

typedef struct {
    int id;
    char name[15];
    int sex;
    int Gaoshu;
    int Daying;
    int Programing;
    double aveScore;
} student;

typedef struct {
    student *elem;
    int length;
    int listsize;
} sqlist;

void CreateStudentList(sqlist &L, int length) {
    L.elem = (student *)malloc(sizeof(student) * length * 2);
    L.listsize = length * 2;
    L.length = length;
    for (int i = 0; i < length; i++) {
        cin >> L.elem[i].id >> L.elem[i].name >> L.elem[i].sex >>
            L.elem[i].Gaoshu >> L.elem[i].Daying >> L.elem[i].Programing;
        L.elem[i].aveScore =
            (L.elem[i].Gaoshu + L.elem[i].Daying + L.elem[i].Programing) * 1.0 /
            3;
    }
}

bool FindbyID(sqlist L, int id, student &stu) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].id == id) {
            stu = L.elem[i];
            return true;
        }
    }
    return false;
}

void PrintStuElem(student stu) {
    printf("%d\t%s\t%d\t%d\t%d\t%.2lf\n", stu.id, stu.name, stu.Gaoshu,
           stu.Daying, stu.Programing, stu.aveScore);
}

void PrintList(sqlist L) {
    cout << "打印成绩表：" << endl;
    printf("ID    Name   高数 大英 程序 平均分\n");
    for (int i = 0; i < L.length; i++) {
        PrintStuElem(L.elem[i]);
    }
    cout << endl;
}

// 通过学号改变某科目成绩
// k表示学科，1表示高等数学，2表示大学英语，3表示程序设计基础
bool ChangeScorebyID(sqlist &L, int id, int k, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].id == id) {
            if (k == 1) {
                L.elem[i].Gaoshu = e;
            } else if (k == 2) {
                L.elem[i].Daying = e;
            } else if (k == 3) {
                L.elem[i].Programing = e;
            }
            L.elem[i].aveScore =
                (L.elem[i].Gaoshu + L.elem[i].Daying + L.elem[i].Programing) *
                1.0 / 3;
            return true;
        }
    }
    return false;
}

bool InsertStudent(sqlist &L, int id, char *name, int sex, int gaoshu,
                   int daying, int programing) {
    if (L.listsize < L.length + 1) {
        L.elem = (student *)realloc(L.elem, sizeof(student) * 100);
        L.listsize = L.length + 100;
    }
    L.elem[L.length].id = id;
    strcpy(L.elem[L.length].name, name);
    L.elem[L.length].sex = sex;
    L.elem[L.length].Gaoshu = gaoshu;
    L.elem[L.length].Daying = daying;
    L.elem[L.length].Programing = programing;
    L.elem[L.length].aveScore =
        (L.elem[L.length].Gaoshu + L.elem[L.length].Daying +
         L.elem[L.length].Programing) *
        1.0 / 3;
    L.length++;
    return true;
}

bool DeleteStudentbyID(sqlist &L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].id == id) {
            for (int j = i + 1; j < L.length; j++) {
                L.elem[j - 1] = L.elem[j];
            }
        }
    }
    L.length--;
    return true;
}

// 按学号查找学生
void function1(sqlist &L) {
    student IDfind;
    int idfind;
    cout << "请输入需要查找的学生的学号；" << endl;
    scanf("%d", &idfind);
    if (FindbyID(L, idfind, IDfind)) {
        printf("找到学号为%d的学生: ", idfind);
        PrintStuElem(IDfind);
    } else {
        cout << "Not found" << endl;
    }
    cout << endl;
}

// 按学号修改学生成绩
void function2(sqlist &L) {
    cout << "请输入需要修改的学生学号和科目，并输入修改后的成绩" << endl;
    int id, sub, e;
    cin >> id >> sub >> e;
    if (ChangeScorebyID(L, id, sub, e)) {
        cout << "修改成功" << endl;
    } else {
        cout << "未找到该学生，修改失败" << endl;
    }
    PrintList(L);
}

// 增加新学生的信息
void function3(sqlist &L) {
    cout << "请按学号、姓名、性别(男为1女为0)"
            "、高数成绩，大英成绩，程序成绩的顺序输入学生信息"
         << endl;
    int id, sex, gaoshu, daying, programing;
    char name[15];
    cin >> id >> name >> sex >> gaoshu >> daying >> programing;
    InsertStudent(L, id, name, sex, gaoshu, daying, programing);
    cout << "Success" << endl;
    PrintList(L);
}

// 按学号删除已退学的学生信息
void function4(sqlist &L) {
    cout << "请输入要删除的学生学号" << endl;
    int id;
    cin >> id;
    if (DeleteStudentbyID(L, id)) {
        cout << "Success" << endl;
    } else {
        cout << "Error" << endl;
    }
    PrintList(L);
}

int main() {
    sqlist L;
    /*  int n;
     cin >> n;
     PrintList(L); */
    CreateStudentList(L, 0);
    InsertStudent(L, 1, "张三", 1, 98, 98, 100);
    InsertStudent(L, 2, "李明", 0, 94, 89, 100);
    InsertStudent(L, 3, "王五", 1, 65, 76, 100);
    cout << "初始成绩单" << endl;
    PrintList(L);
    while (true) {
        int sec;
        printf("-----------------MENU-----------\n");
        printf("1.按学号查询学生信息\n");
        printf("2.按学号修改学生学科成绩,1为高数,2为大学英语,3为程序设计\n");
        printf("3.增加新学生的信息\n");
        printf("4.按学号删除已退学的学生的信息\n");
        printf("5.退出程序\n");
        printf("Please enter your choice:\n");
        scanf("%d", &sec);
        if (sec == 1) {
            function1(L);
        } else if (sec == 2) {
            function2(L);
        } else if (sec == 3) {
            function3(L);
        } else if (sec == 4) {
            function4(L);
        } else if (sec == 5) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Unknown!" << endl;
        }
    }

    return 0;
}
