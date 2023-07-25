# m_include
### my standard library
---
* "I'm too good for the standard library"

<br>

## Updates:
* moved `vector Vector` to `vector.c`
* moved `complex_Class Complex` to `comp.c`
* `vector.c` now includes `m_math.h`
* `m_math.c` new functions
	* `map` and `imap`
	* `max`, `imax`, `amax`, and `iamax` from `vector.c`
* `str.h`: `charisof` decleration
* `fatstr.h`: `fstn` decleration

<br>

### Files and their functions:
---
```
> Bool.h:		True & False enums
> bytes.h:		Structs for manipulating strings
> comp.c:		Complex number data type and functions
> fatstr.c:		Fat string data type and functions
> m_malloc.c:	My malloc implementation
> m_math.c:		My math functions
> nodes.c:		Tree Node data type
> random.c:		Pseudo-random number table
> s_m_math.c:	Slow Math functions with varied precision
> str.c:		String functions
> vector.c:		Vector data type
```
