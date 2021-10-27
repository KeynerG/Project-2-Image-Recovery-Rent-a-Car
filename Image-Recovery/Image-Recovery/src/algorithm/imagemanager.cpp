#include <QDir>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QRgb>
#include <QVector>
#include <QVector2D>

class MainScreen;

/*!
 * \struct Pixel
 * \brief
 */
struct Pixel {
public:
    /*!
     * \brief Pixel struct default constructor.
     */
    Pixel() = default;

    /*!
     * \brief Pixel struct constructor.
     * \param pixelPosition 2D Vector as pixel position (x, y).
     * \param colorCode Vector as pixel color code (int R, int G, int B, int A). A as transparent flag.
     * \param transparentPixel Boolean as a transparent pixel identifier (default = false).
     */
    Pixel(QVector2D pixelPosition, QVector<QRgb> colorCode, bool transparentPixel = false) {
        position = pixelPosition;
        color = colorCode;
        transparent = transparentPixel;
    }

    QVector2D position; /*!< Pixel position (x, y). */
    QVector<QRgb> color; /*!< Pixel color code (int R, int G, int B, int A). A as transparent flag. */
    bool transparent; /*!< Transparent pixel identifier. */


    const QVector2D &getPosition() const {
        return position;
    }

    void setPosition(const QVector2D &position) {
        Pixel::position = position;
    }

    const QVector<QRgb> &getColor() const {
        return color;
    }

    void setColor(const QVector<QRgb> &color) {
        Pixel::color = color;
    }

    bool isTransparent() const {
        return transparent;
    }

    void setTransparent(bool transparent) {
        Pixel::transparent = transparent;
    }
};

/*!
 * \struct Image
 * \brief
 */
struct Image {
public:
    /*!
     * \brief Image struct default constructor.
     */
    Image() = default;

    /*!
     * \brief Image struct constructor.
     * \param generationID
     * \param referenceFilePath
     * \param solidImage
     */
    Image(int generationID, QString referenceFilePath, bool solidImage = false) {
        genID = generationID;
        image.load(referenceFilePath);
        height = image.height();
        weight = image.width();
        solid = solidImage;
        pixmap.fromImage(image);
        genFilePath = "..src/generations/" + QString(QString::fromStdString(std::to_string(generationID)));
    }

    int genID;
    QImage image;
    int height;
    int weight;
    bool solid;
    QPixmap pixmap;
    QString genFilePath;


    int getGenId() const {
        return genID;
    }

    void setGenId(int genId) {
        genID = genId;
    }

    const QImage &getImage() const {
        return image;
    }

    void setImage(const QImage &image) {
        Image::image = image;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Image::height = height;
    }

    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        Image::weight = weight;
    }

    bool isSolid() const {
        return solid;
    }

    void setSolid(bool solid) {
        Image::solid = solid;
    }

    const QPixmap &getPixmap() const {
        return pixmap;
    }

    void setPixmap(const QPixmap &pixmap) {
        Image::pixmap = pixmap;
    }

    const QString &getGenFilePath() const {
        QDir genDir(genFilePath);
        if (!genDir.exists()) {
            genDir.mkdir(genFilePath);
        }
        return genFilePath;
    }

    void setGenFilePath(const QString &genFilePath) {
        Image::genFilePath = genFilePath;
    }
};