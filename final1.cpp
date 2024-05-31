
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void onMouse(int event, int x, int y, int flags, void* userdata);
void Set(Mat& canvas);
void Clear(int x, int y, Mat& canvas);
Mat canvas(500, 700, CV_8UC3, Scalar(255, 255, 255));// windows img
int main() {
    namedWindow("windows", WINDOW_AUTOSIZE);// window named set
    setMouseCallback("windows", onMouse, &canvas);// mouse call back
    while (true) {
        Set(canvas);
        char key = waitKey(10);
    }
    return 0;
}
void onMouse(int event, int x, int y, int flags, void* userdata) {// Mouse event function
    static bool drawing = false;
    static Point prevPoint(-1, -1);
    Mat& canvas = *(Mat*)userdata;
    Rect area(0, 0, 500, 500);// img area
    string Name = "";
    switch (event) {
    case EVENT_LBUTTONDOWN:// mouse L down
        prevPoint = Point(x, y);
        if (area.contains(Point(x, y))) { drawing = true; }// 500,500 area inspect
        if (500 < x) {// draw area
            if (y > 400) { exit(1); }// exit area
            else if (y > 300) { // run area

            }
            else if (y > 200) { Clear(x, y, canvas); }// clear area
            else if (y > 100) { // load area
                cout << "load file name: ";
                cin >> Name;
                Mat number = imread(Name);
                number.copyTo(canvas(Rect(0, 0, 500, 500)));
            }
            else if (y > 0) { // save area
                Mat save = canvas(Rect(1, 1, 498, 498)).clone();
                resize(save, save, Size(500, 500));
                cout << "save file name : ";
                cin >> Name;
                imwrite(Name, save);
                cout << Name << " file saved" << endl;
            }
        }
    case EVENT_MOUSEMOVE:// mouse move
        if (drawing) {
            if (500 > x) {
                line(canvas, prevPoint, Point(x, y), Scalar(0, 0, 0), 10);
                prevPoint = Point(x, y);
            }
        }
        break;
    case EVENT_LBUTTONUP:// mouse L up
        drawing = false;
        break;
    }
}
void Set(Mat& canvas) { // interface function
    imshow("windows", canvas); // img print
    Rect saveButton(500, 0, 200, 100);// button
    Rect loadButton(500, 100, 200, 100);
    Rect clearButton(500, 200, 200, 100);
    Rect runButton(500, 300, 200, 100);
    Rect exitButton(500, 400, 200, 100);
    rectangle(canvas, saveButton, Scalar(0, 0, 0), 2);// text
    putText(canvas, "Save", Point(saveButton.x + 10, saveButton.y + 50), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 0), 3);
    rectangle(canvas, loadButton, Scalar(0, 0, 0), 2);
    putText(canvas, "Load", Point(loadButton.x + 10, loadButton.y + 50), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 0), 3);
    rectangle(canvas, clearButton, Scalar(0, 0, 0), 2);
    putText(canvas, "Clear", Point(clearButton.x + 10, clearButton.y + 50), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 0), 3);
    rectangle(canvas, runButton, Scalar(0, 0, 0), 2);
    putText(canvas, "Run", Point(runButton.x + 10, runButton.y + 50), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 0), 3);
    rectangle(canvas, exitButton, Scalar(0, 0, 0), 2);
    putText(canvas, "Exit", Point(exitButton.x + 10, exitButton.y + 50), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 0), 3);
}
void Clear(int x, int y, Mat& canvas) {// clear function
    Rect clearButton(500, 200, 200, 100);
    if (clearButton.contains(Point(x, y))) {
        canvas = (500, 700, CV_8UC3, Scalar(255, 255, 255));
        cout << "windows Clear" << endl;
        Set(canvas);
    }
}
/*
1. �ʱ�ȭ �� ������ ���� 500x700 ũ���� ��� ĵ������ �����մϴ�.
"windows"��� �̸��� �����츦 �����մϴ�. ���콺 �ݹ� �Լ��� �����Ͽ� ���콺 �̺�Ʈ�� ó���մϴ�.

2.���� ���� ���� �������� Set(canvas);�� ȣ���Ͽ� ��ư�� ĵ������ ȭ�鿡 ǥ���մϴ�.

3. ���콺 �̺�Ʈ ó�� (onMouse �Լ�) 

���콺 ���� ��ư�� ������ ��.
�Է� ����(500x500) ������ ����� ��带 Ȱ��ȭ�մϴ�.
��ư ����(500 �̻�)���� ������ �۾�(����, �ҷ�����, ����, ����, ����)�� �����մϴ�.

���콺 �̵� ��. ���� ��尡 Ȱ��ȭ�� ���, ���� �׸��ϴ�.

���콺 ���� ��ư�� ���� ��. ����� ��带 ��Ȱ��ȭ�մϴ�.

4. �������̽� ���� (Set �Լ�): ĵ������ ǥ���մϴ�.
��ư ������ �����ϰ� �簢���� �ؽ�Ʈ�� �׷� ����� �������̽��� �����մϴ�.
Save, Load, Clear, Run, Exit ��ư�� �����մϴ�.

5. ĵ���� ����� (Clear �Լ�):Clear ��ư�� Ŭ���Ǿ��� ��, ĵ������ �ʱ� ���·� �ǵ����ϴ�.
�ܼ�â�� "windows Clear" �޽����� ����մϴ�.

6.�� ��ư�� ���
���� ���(save) Save ��ư Ŭ�� ��, �ܼ�â���� ���ϸ��� �Է� �޾� ���� �Է�â�� ������ ���Ϸ� �����մϴ�.
������ ������ 3ä�� �÷� �������� ����˴ϴ�.

���� ���(Clear)Clear ��ư Ŭ�� ��, �Է�â�� ������ �����մϴ�.
Rect contains �Լ��� ����Ͽ� Ŭ���� ������ Ȯ���ϰ� ���콺 �̺�Ʈ�� ó���մϴ�.

�ҷ����� ���(load)Load ��ư Ŭ�� ��, �ܼ�â���� ���ϸ��� �Է� �޾� ������ �ҷ��� �Է�â�� ����մϴ�.

������(Exit) Exit ��ư Ŭ�� ��, ���α׷��� �����մϴ�.
    */