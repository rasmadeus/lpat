#ifndef MEDIATOR_H
#define MEDIATOR_H

namespace Mediator
{
    class Dialog
    {
    public:
        virtual ~Dialog() = default;
        virtual void notify(const std::string& msg) = 0;
    };


    class Widget
    {
    public:
        Widget(Dialog& dialog)
            : dialog{dialog}
        {
        }

        virtual ~Widget() = default;

    protected:
        Dialog& dialog;
    };


    class Button : public Widget
    {
    public:
        Button(Dialog& dialog)
            : Widget{dialog}
        {
        }

        void click()
        {
            std::cout << "User clicked on button!" << std::endl;
            dialog.notify("button");
        }
    };


    class Label : public Widget
    {
    public:
        Label(Dialog& dialog)
            : Widget{dialog}
        {
        }

        void setCaption(const std::string& caption)
        {
            this->caption = caption;
            std::cout << "Label caption changed!" << std::endl;
            dialog.notify("label");
        }

        const std::string& getCaption() const
        {
            return caption;
        }

    private:
        std::string caption;
    };


    class PressEventDisplay : public Dialog
    {
    public:
        void notify(const std::string& msg) override
        {
            if (msg == "button")
            {
                label.setCaption("Button clicked");
            }
        }

        void click()
        {
            button.click();
        }

    private:
        Button button{*this};
        Label label{*this};
    };


    void test()
    {
        PressEventDisplay display;
        display.click();
    }
}

#endif // MEDIATOR_H
