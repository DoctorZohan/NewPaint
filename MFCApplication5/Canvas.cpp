#include "pch.h"
#include "Canvas.h"


Canvas::Canvas(int m, int n)
{
    m_num_columns = m;
    m_num_rows = n;
    m_init_color = 0xFFFFFF;
    m_cell_size = 10;
    m_map.resize(m);
    for (int i = 0; i < m_num_columns; i++)
    {
        m_map[i].resize(m_num_rows);
        for (int j = 0; j < m_num_rows; j++)
            setColor(i, j, m_init_color);
    }
}



Canvas::~Canvas()
{
    for (int i = 0; i < m_num_columns; i++)
    {
        m_map[i].clear();
    }
    m_map.clear();
}

bool Canvas::addObject(Shape* obj)
{
    if (!obj->check_availability(this))
        return false;
    obj->fill_cells(this);
    std::map<std::pair<int, int>, int>::iterator it;
    std::map<std::pair<int, int>, int>* map = obj->get_cells();
    for (it = map->begin(); it != map->end(); it++)
    {
        std::pair<int, int> cell = it->first;
        if ( getBusy(cell.first, cell.second) )
            return false;
    }
    for (it = map->begin(); it != map->end(); it++)
    {
        std::pair<int, int> cell = it->first;
        setColor(cell.first, cell.second, obj->color());
        setBusy(cell.first, cell.second, true);
    }
    m_objects.insert (obj);
    return true;
}

void Canvas::removeObject(Shape* obj)
{
    std::map<std::pair<int, int>, int>::iterator it;
    std::map<std::pair<int, int>, int>* map = obj->get_cells();
    for (it = map->begin(); it != map->end(); it++)
    {
        std::pair<int, int> cell = it->first;
        setColor(cell.first, cell.second, m_init_color);
        setSelect(cell.first, cell.second, false);
        setBusy(cell.first, cell.second, false);
    }
    obj->is_selected(false);
    m_objects.erase(obj);
    delete obj;
}

void Canvas::setColor(int x, int y, int color)
{
    m_map[x][y].m_color = color;
}

int Canvas::getColor(int x, int y)
{
    return m_map[x][y].m_color;
}

void Canvas::setBusy(int x, int y, int busy)
{
    m_map[x][y].m_is_busy = busy;
}

int Canvas::getBusy(int x, int y)
{
    return m_map[x][y].m_is_busy;
}

void Canvas::setSelect(int x, int y, bool select)
{
    m_map[x][y].m_selected = select;
}

bool Canvas::getSelect(int x, int y)
{
    return m_map[x][y].m_selected;
}

bool Canvas::redraw_canvas(int sizeX, int sizeY, int initColor)
{
    if (sizeX >= m_num_columns && sizeY >= m_num_rows)
    {
        m_map.resize(sizeX);
        for (int i = 0; i < m_num_columns; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = m_num_rows; j < sizeY; j++)
            {
                    setColor(i, j, initColor);
            }
        }
        for (int i = m_num_columns; i < sizeX; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = 0; j < m_num_rows; j++)
            {
                    setColor(i, j, initColor);
            }
        }
        for (int i = m_num_columns; i < sizeX; i++)
        {
            for (int j = m_num_rows; j < sizeY; j++)
            {
                setColor(i, j, initColor);
            }
        }
        for (int i = 0; i < m_num_columns; i++)
        {
            for (int j = 0; j < m_num_rows; j++)
            {
                if (!getBusy(i, j))
                    setColor(i, j, initColor);
            }
        }
    }
    else if (sizeX >= m_num_columns && sizeY < m_num_rows)
    {
        for (int i = 0; i < m_num_columns; i++)
        {
            for (int j = sizeY; j < m_num_rows; j++)
            {
                Shape* obj = get_shape_with_current_point(i, j);
                if (obj)
                    removeObject(obj);
            }
        }
        m_map.resize(sizeX);
        for (int i = 0; i < m_num_columns; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = 0; j < sizeY; j++)
            {
                if(!getBusy(i, j))
                    setColor(i, j, initColor);
            }
        }
        for (int i = m_num_columns; i < sizeX; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = 0; j < sizeY; j++)
            {
                setColor(i, j, initColor);
            }
        }
    }
    else if (sizeX < m_num_columns && sizeY >= m_num_rows)
    {
        for (int i = sizeX; i < m_num_columns; i++)
        {
            for (int j = 0; j < m_num_rows; j++)
            {
                Shape* obj = get_shape_with_current_point(i, j);
                if (obj)
                    removeObject(obj);
            }
        }
        m_map.resize(sizeX);
        for (int i = 0; i < sizeX; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = 0; j < m_num_rows; j++)
            {
                if (!getBusy(i, j))
                    setColor(i, j, initColor);
            }
            for (int j = m_num_rows; j < sizeY; j++)
            {
                setColor(i, j, initColor);
            }
        }
    }
    else if (sizeX < m_num_columns && sizeY < m_num_rows)
    {
        for (int i = sizeX; i < m_num_columns; i++)
        {
            for (int j = sizeY; j < m_num_rows; j++)
            {
                Shape* obj = get_shape_with_current_point(i, j);
                if (obj)
                    removeObject(obj);
            }
        }
        for (int i = 0; i < sizeX; i++)
        {
            for (int j = sizeY; j < m_num_rows; j++)
            {
                Shape* obj = get_shape_with_current_point(i, j);
                if (obj)
                    removeObject(obj);
            }
        }
        for (int i = sizeX; i < m_num_rows; i++)
        {
            for (int j = 0; j < sizeY; j++)
            {
                Shape* obj = get_shape_with_current_point(i, j);
                if (obj)
                    removeObject(obj);
            }
        }
        m_map.resize(sizeX);
        for (int i = 0; i < sizeX; i++)
        {
            m_map[i].resize(sizeY);
            for (int j = 0; j < sizeY; j++)
            {
                if (!getBusy(i, j))
                    setColor(i, j, initColor);
            }
        }
    }
    m_num_columns = sizeX;
    m_num_rows = sizeY;
    m_init_color = initColor;
    return true;
}

Shape* Canvas::get_shape_with_current_point(int x, int y)
{
    for (auto obj : m_objects)
        if (obj->find_map(x, y))
            return obj;
    return nullptr;
}

void Canvas::select_object(Shape* object, bool select)
{
    std::map<std::pair<int, int>, int>::iterator it;
    std::map<std::pair<int, int>, int>* map = object->get_cells();
    for (it = map->begin(); it != map->end(); it++)
    {
        std::pair<int, int> cell = it->first;
        m_map[cell.first][cell.second].m_selected = select;
    }
    object->is_selected(select);
}

Shape* Canvas::get_current_select_object()
{
    for (auto obj : m_objects)
        if (obj->is_selected())
            return obj;
    return nullptr;
}