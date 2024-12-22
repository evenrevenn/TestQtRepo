#include <QDialog>

class Window : public QDialog
{
public:
    Window();
    ~Window() noexcept;

private:
    class QListWidgetItem * addNewItem(const QString &text) noexcept;

    void restoreSettings() noexcept;
    void saveSettings() const noexcept;

    class QGridLayout *layout_;

    class QListWidget *list_widget_;
    class QPushButton *add_button_;
    class QPushButton *remove_button_;
    class QLineEdit *line_edit_;
};