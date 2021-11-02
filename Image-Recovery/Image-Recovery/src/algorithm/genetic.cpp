#include "genetic.h"

void Genetic::geneticAlgorithm() {

    //while(precision != 100){ //Generations

        if(firstTime) { //first generation - random
            //int n = DataManager::getInstance()->getColorTableReference().size(); //Amount of colors
            int pixels = DataManager::getInstance()->getReference().size(); //Amount of pixels

            for(int i = 0 ; i < 10 ; i++){ //10 subjects per generation

                QVector<QRgb> tmp = DataManager::getInstance()->getReference();

                Subject individualSubject;

                QVector<QRgb> subjectFrame;

                for(int p = 0 ; p < pixels ; p++){ // "image", reference size of pixels
                    int remainingPixels = tmp.size();
                    int actualPixel = rand() % (remainingPixels);
                    subjectFrame.push_back(tmp[actualPixel]);
                    tmp.removeAt(actualPixel);
                }
                individualSubject.id = i;
                individualSubject.frame = subjectFrame;
                individualSubject.similarity = 0;
                qDebug() << subjectFrame;
                generation.addNodeAtEnd(individualSubject);
            }
            generationsList.addNodeAtEnd(generation);
            firstTime = false;
        }else{
            cout << "Hola" << endl;
        }

    //}
}

//rand() % (n) + 1; <- Numero aleatorio

void Genetic::fitness(SimpleList<SimpleList<Subject>> gens) {


}

void Genetic::selection() {

}

void Genetic::crossover() {

}

void Genetic::mutation() {

}

bool Genetic::checkGenerationNumber(int &generationID) {
    if ((generationID % DataManager::getInstance()->getUserNGenerations()) == 0 || generationID == DataManager::getInstance()->getLastGenerationFile()) {
        return true;
    } else {
        return false;
    }
}

void Genetic::createXML() {

}

void Genetic::createImage(int &generationNumber, QImage &image) {
    bool saveStatement = checkGenerationNumber(generationNumber);
    if (saveStatement) {
        DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() + 1);
        QString path = "../src/generations/" + QString(QString::fromStdString(std::to_string(DataManager::getInstance()->getCurrentFileGeneration()))) + ".png";
        bool saved = image.save(path);
        if (!saved) {
            qDebug() << "ERROR: The image of generation " << DataManager::getInstance()->getCurrentFileGeneration() << " was not successfully saved.";
            if (DataManager::getInstance()->getCurrentFileGeneration() != 0) {
                DataManager::getInstance()->setCurrentFileGeneration(DataManager::getInstance()->getCurrentFileGeneration() - 1);
            }
        }
    }
}