#include <iostream>
#include <fstream>

#include "envire/Core.hpp"
#include "envire/maps/TriMesh.hpp"
#include "envire/maps/MLSGrid.hpp"
#include <boost/scoped_ptr.hpp>

using namespace envire;

int main(int argc, char** argv)
{
    boost::scoped_ptr<Environment> env(Environment::unserialize( argv[1] ));
    env->updateOperators();

    MLSGrid const& grid = *env->getItem<MLSGrid>("/4");
    std::cout << grid.getOffsetX() << " " << grid.getScaleX() << " " << grid.getOffsetY() << " " << grid.getScaleY() << "\n";

    for (unsigned y = 0; y < grid.getCellSizeY(); ++y)
    {
        std::cout << "YBEGIN " << y;
        for (unsigned x = 0; x < grid.getCellSizeX(); ++x)
        {
            MLSGrid::const_iterator it = grid.beginCell(x, y);
            if (it != grid.endCell())
            {
                std::cout << " CELLBEGIN " << x << " " << y;
                for (; it != grid.endCell(); ++it)
                {
                    if (it->isHorizontal())
                        std::cout << " H " << it->getMean() << " " << it->getStdev();
                    else if (it->isVertical())
                        std::cout << " V " << it->getMean() << " " << it->getHeight();
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}
