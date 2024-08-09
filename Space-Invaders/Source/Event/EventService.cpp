#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event
{

    EventService::EventService() { game_window = nullptr; }

    EventService::~EventService() = default; //calls the default destructor

    using namespace Global;

    void EventService::initialize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update()
    {
        updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
        updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
        updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
        updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
        updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
        updateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
    }

    void EventService::processEvents()
    {
        if (isGameWindowOpen()) {
            while (game_window->pollEvent(game_event)) {
                // Check for window closure
                if (gameWindowWasClosed() || hasQuitGame())
                {
                    game_window->close();
                }
            }
        }
    }

    void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
    {
        if (sf::Mouse::isButtonPressed(mouse_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
    {
        if (sf::Keyboard::isKeyPressed(keyboard_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); } // only true if the ESC key is pressed and a keyboard event has been registered

    //checks for if a keyboard key has been pressed
    bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }

    //control click on the SFML functions to see what they do internally
    bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }
    bool EventService::isGameWindowOpen() { return game_window != nullptr; }
    bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

    // Player inputs
    bool EventService::pressedLeftKey() { return left_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedRightKey() { return right_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedAKey() { return A_button_state == ButtonState::HELD; }

    bool EventService::pressedDKey() { return D_button_state == ButtonState::HELD; }

    bool EventService::pressedLeftMouseButton() { return left_mouse_button_state == ButtonState::PRESSED; }

    bool EventService::pressedRightMouseButton() { return right_mouse_button_state == ButtonState::PRESSED; }

    /*bool EventService::pressedLeftKey() { return game_event.key.code == sf::Keyboard::Left; }
    bool EventService::pressedRightKey() { return game_event.key.code == sf::Keyboard::Right; }
    bool EventService::pressedLeftMouseButton()
    {
        // check if a mouse button was pressed and which mouse button it was
        return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left;
    }

    bool EventService::pressedRightMouseButton()
    {
        return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
    }*/
}