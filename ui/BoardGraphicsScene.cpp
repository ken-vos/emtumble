#include "BoardGraphicsScene.h"
#include "../common.hpp"

BoardGraphicsScene::BoardGraphicsScene(QObject *parent) : QGraphicsScene(parent), board(nullptr) 
{
    current_mode = Mode::SELECT_ITEM;
}

void BoardGraphicsScene::load_board(std::string fname)
{
    if (board != nullptr) delete board;
    std::vector<std::string> board_str = common::read_file(fname);
    board = new BoardGUI(board_str);
    board->lever_pulled(BLUE);
    update_graphics();
}

void BoardGraphicsScene::update_graphics()
{
    if (board == nullptr) return;
    clear();
    board->draw(this, as_image);
}

void BoardGraphicsScene::step()
{
    if (board == nullptr) return;
    board->step();
    update_graphics();
}

void BoardGraphicsScene::set_as_image(bool _as_image)
{
    as_image = _as_image;
    update_graphics();
}

void BoardGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF scene_pos = event->scenePos();
    QGraphicsItem *item = itemAt(scene_pos, QTransform());

    switch (current_mode) {
    case Mode::SELECT_ITEM:
        if (item != nullptr) {
            board->item_clicked(item);
            update_graphics();
        }
        break;

    case Mode::INSERT_ITEM:
        break;
    }
}
