/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 YOUR_NAME <YOUR_EMAIL>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `buffer.h`.
 */

// TODO: `#include`s for system headers, if necessary

#include "buffer.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

Buffer::Buffer(unsigned int size_x, unsigned int size_y)
	:size_x(size_x), size_y(size_y)
{
	data_ = new char[size_x * size_y];
	for (unsigned int i = 0; i < size_x * size_y; i++)
		data_[i] = ' ';
}
/**
* The constructor.
*
* Must initialize `size_x` and `size_y`, and allocate memory for (and
* initialize) `data_`.
*
* Notes:
* - Since `size_x` and `size_y` are constant, they must be initialized
*   in the initialization list, rather than set in the constructor
*   body.
* - You may assume that the dynamic memory allocation succeeds.
*/

Buffer::~Buffer()
{
	delete[] data_;
}
/**
* The destructor.
*
* Must free the memory that the constructor allocated to `data_`.
*/


char Buffer::get(unsigned int x, unsigned int y) const
{
	return data_[ y * size_x + x ];

	if (y > size_y && x > size_x) {
		cerr << "Error: 'Buffer::get': indext out of bounds\n";

		exit(1);
	}
	
}
/**
* Return the character at `data_[ y * size_x + x ]`.
*
* If `x` or `y` is out of bounds, should write
* ```
* "ERROR: `Buffer::get`: index out of bounds\n"
* ```
* to `cerr` and `exit(1)`.
*/

void Buffer::set(unsigned int x, unsigned int y, char c)
{
	data_[ y * size_x + x] = c ;
	if (x > size_x && y > size_y) {
		cerr << "Error: 'Buffer::set': index out of bounds \n";

		exit(1);
	}
	
}
/**
* Set the character at `data_[ y * size_x + x ]` to `c`.
*
* If `x` or `y` is out of bounds, should write
* ```
* "ERROR: `Buffer::set`: index out of bounds\n"
* ```
* to `cerr` and `exit(1)`.
*/

void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
{

}
/**
* Overlay `s` onto `data_`.
*
* For example, if this buffer is representing an array that looks like
* ```
* *******
* *******
* *******
* *******
* *******
* ```
* and we call `set(1, 2, "hello\nworld")`, the buffer's contents
* should now be
* ```
* *******
* *******
* *hello*
* *world*
* *******
* ```
*
* Notes:
* - This function may call the other `set` (which takes a `char` as
*   its last argument), if you like.  In that case, you may leave the
*   index error checking to the other `set`.  Otherwise, you should
*   have checks in this function to make sure you're not putting
*   characters where they don't belong.
* - This function will be useful when implementing the `Shape` class.
* - If you can't think of a way to do this, see
*   `hint--implementation-of-Buffer-set.md`.
*/


void Buffer::draw() const
{
	for (unsigned int y = 0; y < size_y; y++) {
		for (unsigned int x = 0; x < size_x; x++) {
			cout << get(x, y);
		}
		cout << endl;
	}
}
/**
* Output the contents of the buffer to `cout`.
*/

void Buffer::clear()
{
	for (unsigned int i = 0; i < size_x * size_y; i++)
		data_[i] = ' ';
}
/**
* Set each element `data_` to ' '.
*/
