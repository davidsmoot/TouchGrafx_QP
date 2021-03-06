/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) //Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x55, 0x6e, 0x64, 0x65, 0x72, 0x73, 0x74, 0x61, 0x6e, 0x64, 0x69, 0x6e, 0x67, 0x20, 0x4d, 0x56, 0x50, 0xa, 0xa, 0x54, 0x68, 0x69, 0x73, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x77, 0x69, 0x6c, 0x6c, 0x20, 0x68, 0x65, 0x6c, 0x70, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x75, 0x6e, 0x64, 0x65, 0x72, 0x73, 0x74, 0x61, 0x6e, 0x64, 0xa, 0x74, 0x68, 0x65, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x2c, 0x20, 0x76, 0x69, 0x65, 0x77, 0x2c, 0x20, 0x70, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x20, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x75, 0x72, 0x65, 0x20, 0xa, 0x6f, 0x66, 0x20, 0x54, 0x6f, 0x75, 0x63, 0x68, 0x47, 0x46, 0x58, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0xa, 0xa, 0x4d, 0x6f, 0x76, 0x65, 0x20, 0x6c, 0x65, 0x66, 0x74, 0x20, 0x6f, 0x72, 0x20, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x62, 0x79, 0x20, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x68, 0x65, 0x20, 0x61, 0x72, 0x72, 0x6f, 0x77, 0x73, 0x0, // @0 "Understanding MVP??This application will help you understand?the model, view, presenter structure ?of TouchGFX applications??Move left or right by using the arrows"
    0x56, 0x69, 0x65, 0x77, 0x73, 0x20, 0x64, 0x65, 0x73, 0x63, 0x72, 0x69, 0x62, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x76, 0x69, 0x73, 0x75, 0x61, 0x6c, 0x20, 0x61, 0x70, 0x70, 0x65, 0x61, 0x72, 0x61, 0x6e, 0x63, 0x65, 0x20, 0x6f, 0x66, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x75, 0x69, 0x2e, 0xa, 0x56, 0x69, 0x65, 0x77, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x69, 0x73, 0x74, 0x20, 0x6f, 0x66, 0x20, 0x77, 0x69, 0x64, 0x67, 0x65, 0x74, 0x73, 0x20, 0x2d, 0x20, 0x62, 0x6f, 0x78, 0x65, 0x73, 0x2c, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x73, 0x2c, 0x20, 0x62, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x73, 0x2c, 0x20, 0x2e, 0x2e, 0x2e, 0xa, 0x56, 0x69, 0x65, 0x77, 0x73, 0x20, 0x68, 0x61, 0x76, 0x65, 0x20, 0x68, 0x61, 0x6e, 0x64, 0x6c, 0x65, 0x72, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x72, 0x65, 0x61, 0x63, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x6f, 0x20, 0x75, 0x73, 0x65, 0x72, 0x20, 0x65, 0x76, 0x65, 0x6e, 0x74, 0x73, 0x0, // @164 "Views describe the visual appearance of your ui.?Views consist of widgets - boxes, images, buttons, ...?Views have handlers for reacting to user events"
    0x54, 0x68, 0x65, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x20, 0x68, 0x6f, 0x6c, 0x64, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x74, 0x61, 0x74, 0x65, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x75, 0x69, 0xa, 0x54, 0x68, 0x65, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x20, 0x6f, 0x66, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0xa, 0x59, 0x6f, 0x75, 0x20, 0x77, 0x72, 0x69, 0x74, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6f, 0x64, 0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x63, 0x6f, 0x6d, 0x6d, 0x75, 0x6e, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x0, // @316 "The model holds the state of the ui?The model is the point of integration with your system?You write the code for communicating with your system"
    0x54, 0x68, 0x65, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x69, 0x73, 0x20, 0x65, 0x76, 0x65, 0x72, 0x79, 0x74, 0x68, 0x69, 0x6e, 0x67, 0x20, 0x6f, 0x75, 0x74, 0x73, 0x69, 0x64, 0x65, 0x20, 0x54, 0x6f, 0x75, 0x63, 0x68, 0x47, 0x46, 0x58, 0xa, 0x54, 0x68, 0x65, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x68, 0x61, 0x73, 0x20, 0x6d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x6c, 0x69, 0x6e, 0x67, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x68, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0xa, 0x54, 0x68, 0x65, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x63, 0x61, 0x6e, 0x20, 0x62, 0x65, 0x20, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x65, 0x64, 0x20, 0x69, 0x6e, 0x20, 0x43, 0x20, 0x6f, 0x72, 0x20, 0x43, 0x2b, 0x2b, 0x0, // @461 "The system is everything outside TouchGFX?The system has methods for controlling your hardware?The system can be implemented in C or C++"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x3a, 0x3a, 0x74, 0x69, 0x63, 0x6b, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x5f, 0x72, 0x65, 0x61, 0x64, 0x5f, 0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x5f, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x3b, 0xa, 0x20, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x4c, 0x69, 0x73, 0x74, 0x65, 0x6e, 0x65, 0x72, 0x2d, 0x3e, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x28, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x29, 0x3b, 0xa, 0x7d, 0x0, // @598 "void Model::tick() {?  temperature = control_read_current_temperature();?  modelListener->updateCurrent(temperature);?}"
    0x50, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x73, 0x20, 0x6d, 0x65, 0x64, 0x69, 0x61, 0x74, 0x65, 0x20, 0x62, 0x65, 0x74, 0x77, 0x65, 0x65, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x76, 0x69, 0x65, 0x77, 0x73, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0xa, 0x50, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x62, 0x65, 0x68, 0x61, 0x76, 0x69, 0x6f, 0x75, 0x72, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x75, 0x69, 0x20, 0x0, // @718 "Presenters mediate between the views and the model?Presenters contain the behaviour of the ui "
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x50, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x3a, 0x3a, 0x62, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x43, 0x6c, 0x69, 0x63, 0x6b, 0x65, 0x64, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x2d, 0x3e, 0x72, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x41, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x3b, 0xa, 0x7d, 0xa, 0x0, // @813 "void TemperaturePresenter::buttonClicked() {?  model->requestAdjustTemperature();?}?"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x56, 0x69, 0x65, 0x77, 0x3a, 0x3a, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x28, 0x69, 0x6e, 0x74, 0x20, 0x74, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x57, 0x69, 0x64, 0x67, 0x65, 0x74, 0x2e, 0x73, 0x65, 0x74, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x28, 0x74, 0x29, 0x3b, 0xa, 0x7d, 0x0, // @898 "void TemperatureView::updateCurrent(int t) {?  temperatureWidget.setValue(t);?}"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x3a, 0x3a, 0x72, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x41, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x5f, 0x73, 0x65, 0x74, 0x5f, 0x72, 0x6f, 0x6f, 0x6d, 0x5f, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x3b, 0xa, 0x7d, 0xa, 0x0, // @978 "void Model::requestAdjustTemperature() {?  control_set_room_temperature();?}?"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x50, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x3a, 0x3a, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x28, 0x69, 0x6e, 0x74, 0x20, 0x74, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x76, 0x69, 0x65, 0x77, 0x2e, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x28, 0x74, 0x29, 0x3b, 0xa, 0x7d, 0x0, // @1056 "void TemperaturePresenter::updateCurrent(int t) {?  view.updateCurrent(t);?}"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x56, 0x69, 0x65, 0x77, 0x3a, 0x3a, 0x62, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x43, 0x6c, 0x69, 0x63, 0x6b, 0x65, 0x64, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x70, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x2d, 0x3e, 0x62, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x43, 0x6c, 0x69, 0x63, 0x6b, 0x65, 0x64, 0x28, 0x29, 0x3b, 0xa, 0x7d, 0x0, // @1133 "void TemperatureView::buttonClicked() {?  presenter->buttonClicked();?}"
    0x69, 0x6e, 0x74, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x5f, 0x72, 0x65, 0x61, 0x64, 0x5f, 0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x5f, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x2f, 0x2f, 0x2e, 0x2e, 0x2e, 0xa, 0x7d, 0x0, // @1205 "int control_read_current_temperature() {?  //...?}"
    0x76, 0x6f, 0x69, 0x64, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x5f, 0x73, 0x65, 0x74, 0x5f, 0x72, 0x6f, 0x6f, 0x6d, 0x5f, 0x74, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x28, 0x29, 0x20, 0x7b, 0xa, 0x20, 0x20, 0x2f, 0x2f, 0x2e, 0x2e, 0x2e, 0xa, 0x7d, 0x0, // @1256 "void control_set_room_temperature() {?  //...?}"
    0x4d, 0x56, 0x50, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x73, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x55, 0x49, 0x20, 0x74, 0x6f, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x0, // @1304 "MVP connects your UI to your system"
    0x45, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0xa, 0x49, 0x6e, 0x70, 0x75, 0x74, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x0, // @1340 "Example?Input from system"
    0x45, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0xa, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x74, 0x6f, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x0, // @1366 "Example?Output to system"
    0x55, 0x6e, 0x64, 0x65, 0x72, 0x73, 0x74, 0x61, 0x6e, 0x64, 0x69, 0x6e, 0x67, 0x20, 0x4d, 0x56, 0x50, 0x0, // @1391 "Understanding MVP"
    0x6f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x2b, 0x20, 0x31, 0x30, 0x0, // @1409 "output + 10"
    0x50, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0x65, 0x72, 0x0, // @1421 "Presenter"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @1431 "New Text"
    0x2, 0x0, // @1440 "<>"
    0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x0, // @1442 "System"
    0x69, 0x6e, 0x70, 0x75, 0x74, 0x0, // @1449 "input"
    0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x0, // @1455 "Model"
    0x56, 0x69, 0x65, 0x77, 0x0, // @1461 "View"
    0x44, 0x65, 0x6d, 0x6f, 0x0, // @1466 "Demo"
    0x55, 0x49, 0x0 // @1471 "UI"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            //dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            //compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
