#ifndef ZIPPER_HH
# define ZIPPER_HH

# include <QThread>

class Zipper : public QThread
{
    Q_OBJECT

private:

public:
    Zipper();
};

#endif // ZIPPER_HH
