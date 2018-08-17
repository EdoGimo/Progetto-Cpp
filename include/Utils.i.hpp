/**
 * @copyright MyProject
 * license MIT
 * @author Edoardo Righi
 * @version v1.0
 * @date August, 2018
 * @file Utils.i.hpp
 */

constexpr bool differentCols(unsigned row, unsigned col, unsigned num) {
  return (row > 0) && (num != col);
}
