/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2020 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_SCROLLABLE_PANEL_HPP
#define TGUI_SCROLLABLE_PANEL_HPP

#include <TGUI/CopiedSharedPtr.hpp>
#include <TGUI/Widgets/Panel.hpp>
#include <TGUI/Widgets/Scrollbar.hpp>
#include <TGUI/Renderers/ScrollablePanelRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Group of widgets that has a background color and optional borders.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ScrollablePanel : public Panel
    {
    public:

        typedef std::shared_ptr<ScrollablePanel> Ptr; //!< Shared widget pointer
        typedef std::shared_ptr<const ScrollablePanel> ConstPtr; //!< Shared constant widget pointer

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        ///
        /// @param size        Size of the panel
        /// @param contentSize Size of the content area for which the scrollbars will appear if larger than the size
        ///
        /// When contentSize is set to (0,0), the content size is determined by the child widgets of the panel.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanel(const Layout2d& size = {"100%", "100%"}, Vector2f contentSize = {0, 0});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanel(const ScrollablePanel& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanel(ScrollablePanel&& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanel& operator= (const ScrollablePanel& other);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of move assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanel& operator= (ScrollablePanel&& other);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new scrollable panel widget
        ///
        /// @param size  Size of the panel
        /// @param contentSize Size of the content area for which the scrollbars will appear if larger than the size
        ///
        /// When contentSize is set to (0,0), the content size is determined by the child widgets of the panel.
        ///
        /// @return The new scrollable panel
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ScrollablePanel::Ptr create(Layout2d size = {"100%", "100%"}, Vector2f contentSize = {0, 0});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another scrollbable panel
        ///
        /// @param panel  The other scrollbable panel
        ///
        /// @return The new scrollbable panel
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ScrollablePanel::Ptr copy(ScrollablePanel::ConstPtr panel);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer that may be shared with other widgets using the same renderer
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanelRenderer* getSharedRenderer();
        const ScrollablePanelRenderer* getSharedRenderer() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer
        /// @warning After calling this function, the widget has its own copy of the renderer and it will no longer be shared.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ScrollablePanelRenderer* getRenderer();
        const ScrollablePanelRenderer* getRenderer() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the panel
        ///
        /// @param size  The new size of the panel
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Widget::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @warning This function does not return the absolute position of the ScrollablePanel. It is implemented in a way
        ///          that allows calling getAbsolutePosition() on a child widget of the ScrollablePanel to work.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getAbsolutePosition() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Adds a widget at the end of the layout
        ///
        /// @param widget      Pointer to the widget you would like to add
        /// @param widgetName  An identifier to access to the widget later
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void add(const Widget::Ptr& widget, const String& widgetName = "") override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes a single widget that was added to the container
        ///
        /// @param widget  Pointer to the widget to remove
        ///
        /// @return True when widget is removed, false when widget was not found
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool remove(const Widget::Ptr& widget) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes all widgets that were added to the container
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeAllWidgets() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Channges the size available for child widgets
        ///
        /// @param size  Inner size of the container
        ///
        /// If the content size is larger than the size of the panel then scrollbars will be displayed.
        ///
        /// When the content size is (0,0), which is the default, then the content size is determined by the child widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setContentSize(Vector2f size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size available for child widgets
        ///
        /// @return Inner size of the container
        ///
        /// If the content size is larger than the size of the panel then scrollbars will be displayed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getContentSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the amount of pixels the child widgets have been shifted to be displayed by the scrollable panel
        ///
        /// @return Value of the scrollbars
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getContentOffset() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the width of the scrollbars
        /// @return Scrollbar width
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getScrollbarWidth() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes when the vertical scrollbar should be displayed
        /// @param policy  The policy for displaying the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalScrollbarPolicy(Scrollbar::Policy policy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns when the vertical scrollbar should be displayed
        /// @return The policy for displaying the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar::Policy getVerticalScrollbarPolicy() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes when the horizontal scrollbar should be displayed
        /// @param policy  The policy for displaying the horizontal scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setHorizontalScrollbarPolicy(Scrollbar::Policy policy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns when the horizontal scrollbar should be displayed
        /// @return The policy for displaying the horizontal scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Scrollbar::Policy getHorizontalScrollbarPolicy() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes how much the value changes when scrolling or pressing one of the arrows of the vertical scrollbar
        ///
        /// @param scrollAmount  How far should the vertical scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalScrollAmount(unsigned int scrollAmount);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns how much the value changes when scrolling or pressing one of the arrows of the vertical scrollbar
        ///
        /// @return How far should the vertical scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getVerticalScrollAmount() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes how much the value changes when scrolling or pressing one of the arrows of the horizontal scrollbar
        ///
        /// @param scrollAmount  How far should the horizontal scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setHorizontalScrollAmount(unsigned int scrollAmount);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns how much the value changes when scrolling or pressing one of the arrows of the horizontal scrollbar
        ///
        /// @return How far should the horizontal scrollbar scroll when an arrow is clicked?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getHorizontalScrollAmount() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the thumb position of the vertical scrollbar
        ///
        /// @param value  New value of the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalScrollbarValue(unsigned int value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the thumb position of the vertical scrollbar
        ///
        /// @return Value of the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getVerticalScrollbarValue() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the thumb position of the horizontal scrollbar
        ///
        /// @param value  New value of the horizontal scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setHorizontalScrollbarValue(unsigned int value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the thumb position of the horizontal scrollbar
        ///
        /// @return Value of the horizontal scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getHorizontalScrollbarValue() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMousePressed(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseReleased(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseMoved(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool mouseWheelScrolled(float delta, Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseNoLongerOnWidget() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseButtonNoLongerDown() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        // Shows the tool tip when the widget is located below the mouse.
        // Returns its tool tip or the tool tip from a child widget if the mouse is on top of the widget.
        // A nullptr is returned when the mouse is not on top of the widget or when the tool tip is empty.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr askToolTip(Vector2f mousePos) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(sf::RenderTarget& target, RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Lowercase name of the property that was changed
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rendererChanged(const String& property) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr clone() const override
        {
            return std::make_shared<ScrollablePanel>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Update the position, size and value of the scrollbars
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateScrollbars();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Find out what the most right and bottom positions are that are in use by the child widgets
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void recalculateMostBottomRightPosition();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Connect the position and size events to recalculate the bottom right position when a widget is updated
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void connectPositionAndSize(Widget::Ptr widget);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Disconnect the position and size events that were connected to keep track of widget changes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void disconnectAllChildWidgets();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        Vector2f         m_contentSize;
        Vector2f         m_mostBottomRightPosition;
        CopiedSharedPtr<ScrollbarChildWidget> m_verticalScrollbar;
        CopiedSharedPtr<ScrollbarChildWidget> m_horizontalScrollbar;

        Scrollbar::Policy m_verticalScrollbarPolicy = Scrollbar::Policy::Automatic;
        Scrollbar::Policy m_horizontalScrollbarPolicy = Scrollbar::Policy::Automatic;

        unsigned int m_verticalScrollAmount = 0;
        unsigned int m_horizontalScrollAmount = 0;

        std::map<Widget::Ptr, unsigned int> m_connectedPositionCallbacks;
        std::map<Widget::Ptr, unsigned int> m_connectedSizeCallbacks;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SCROLLABLE_PANEL_HPP
