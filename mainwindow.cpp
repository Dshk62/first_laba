#include "mainwindow.h"
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputA = new QLineEdit(this);
    inputA->setPlaceholderText("Введи A,ну пж");
    inputB = new QLineEdit(this);
    inputB->setPlaceholderText("Ну и B тогда уже");

    inputLayout->addWidget(inputA);
    inputLayout->addWidget(inputB);

    calculateButton = new QPushButton("Друзья ли???", this);
    resultLabel = new QLabel(this);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(resultLabel);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_calculateButton_clicked()
{
    bool okA, okB;
    int A = inputA->text().toInt(&okA);
    int B = inputB->text().toInt(&okB);

    if (!okA || !okB) {
        QMessageBox::warning(this, "Input Error", "Please enter valid integers for A and B.");
        return;
    }

    int sum_a = 0, sum_b = 0;

    for (int i = 1; i < A; i++) {
        if (A % i == 0) sum_a += i;
    }

    for (int i = 1; i < B; i++) {
        if (B % i == 0) sum_b += i;
    }

    if (A == sum_b && B == sum_a) {
        resultLabel->setText("A и B пидружки");
    } else {
        resultLabel->setText("A и B не слошлись характерами");
    }
}
