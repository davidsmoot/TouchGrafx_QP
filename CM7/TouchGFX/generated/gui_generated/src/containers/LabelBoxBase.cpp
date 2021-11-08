/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/LabelBoxBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LabelBoxBase::LabelBoxBase()
{
    setWidth(200);
    setHeight(80);
    border.setPosition(0, 0, 200, 80);
    border.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setPosition(1, 1, 198, 78);
    background.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    text.setPosition(1, 1, 198, 79);
    text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text.setLinespacing(0);
    text.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5));

    add(border);
    add(background);
    add(text);
}

void LabelBoxBase::initialize()
{

}

