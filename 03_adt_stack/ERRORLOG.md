## Error Log

## September 14, 2026

## Error 1 

**Undefined symbols for architecture arm64:
"Stack::isFull() const", referenced from:
Stack::push(int) in Stack.cpp.o
ld: symbol(s) not found for architecture arm64
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [03_adt_stack] Error 1
make[2]: *** [CMakeFiles/03_adt_stack.dir/all] Error 2
make[1]: *** [CMakeFiles/03_adt_stack.dir/rule] Error 2
make: *** [03_adt_stack] Error 2**

**Cause:**

I declared isFull() in Stack.h and used it in push(), but I had not defined Stack::isFull()
in Stack.cpp. The linker therefore could not find the implementation of the function.

**Fix:**

I added the definition of isFull() to Stack.cpp. It checks whether topIndex is 99,
which is the final valid index of my 100-element array.

## Error 2

**Cause:** 

I accidentally had a mismatch between my method header and my implementation.

**Fix:**

Rather than keeping the pop() method as type void, I changed it to type int to prevent a mismatch error.

**/Users/isabellainio/CS210CPPRepo-A2/03_adt_stack/Stack.cpp:21:12: error: return type of out-of-line definition of 'Stack::pop' differs from that in the declaration
21 | int Stack::pop() {
| ~~~        ^
/Users/isabellainio/CS210CPPRepo-A2/03_adt_stack/Stack.h:7:10: note: previous declaration is here
7 |     void pop();              // remove the top (does nothing if empty)
|     ~~~~ ^
/Users/isabellainio/CS210CPPRepo-A2/03_adt_stack/main.cpp:16:29: error: invalid operands to binary expression ('basic_ostream<char, char_traits<char>>' and 'void')
16 |     std::cout << "Popped: " << s.pop() << std::endl;
|     ~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:698:55: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'char' for 2nd argument
698 | _LIBCPP_HIDE_FROM_ABI basic_ostream<_CharT, _Traits>& operator<<(basic_ostream<_CharT, _Traits>& __os, char __cn) {
|                                                       ^                                                ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:725:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'char' for 2nd argument
725 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, char __c) {
|                                                     ^                                              ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:730:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'signed char' for 2nd argument
730 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, signed char __c) {
|                                                     ^                                              ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:735:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'unsigned char' for 2nd argument
735 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, unsigned char __c) {
|                                                     ^                                              ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:747:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const char *' for 2nd argument
747 | operator<<(basic_ostream<_CharT, _Traits>& __os, const char* __strn) {
| ^                                                ~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:786:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const char *' for 2nd argument
786 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, const char* __str) {
|                                                     ^                                              ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:792:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const signed char *' for 2nd argument
792 | operator<<(basic_ostream<char, _Traits>& __os, const signed char* __str) {
| ^                                              ~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:799:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const unsigned char *' for 2nd argument
799 | operator<<(basic_ostream<char, _Traits>& __os, const unsigned char* __str) {
| ^                                              ~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:937:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const error_code' for 2nd argument
937 | operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __ec) {
| ^                                                ~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:693:55: note: candidate template ignored: deduced conflicting types for parameter '_CharT' ('char' vs. 'void')
693 | _LIBCPP_HIDE_FROM_ABI basic_ostream<_CharT, _Traits>& operator<<(basic_ostream<_CharT, _Traits>& __os, _CharT __c) {
|                                                       ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/cstddef:111:38: note: candidate template ignored: requirement 'is_integral<void>::value' was not satisfied [with _Integer = void]
111 | _LIBCPP_HIDE_FROM_ABI constexpr byte operator<<(byte __lhs, _Integer __shift) noexcept {
|                                      ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__random/uniform_int_distribution.h:234:1: note: candidate template ignored: could not match 'uniform_int_distribution<_IT>' against 'void'
234 | operator<<(basic_ostream<_CharT, _Traits>& __os, const uniform_int_distribution<_IT>& __x) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:741:1: note: candidate template ignored: could not match 'const _CharT *' against 'void'
741 | operator<<(basic_ostream<_CharT, _Traits>& __os, const _CharT* __str) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:925:1: note: candidate template ignored: could not match 'basic_string<_CharT, _Traits, _Allocator>' against 'void'
925 | operator<<(basic_ostream<_CharT, _Traits>& __os, const basic_string<_CharT, _Traits, _Allocator>& __str) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:931:1: note: candidate template ignored: could not match 'basic_string_view<_CharT, _Traits>' against 'void'
931 | operator<<(basic_ostream<_CharT, _Traits>& __os, basic_string_view<_CharT, _Traits> __sv) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:943:1: note: candidate template ignored: could not match 'shared_ptr<_Yp>' against 'void'
943 | operator<<(basic_ostream<_CharT, _Traits>& __os, shared_ptr<_Yp> const& __p) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:963:1: note: candidate template ignored: could not match 'bitset<_Size>' against 'void'
963 | operator<<(basic_ostream<_CharT, _Traits>& __os, const bitset<_Size>& __x) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:918:33: note: candidate template ignored: substitution failure [with _Stream = basic_ostream<char, char_traits<char>> &, _Tp = void]: cannot form a reference to 'void'
917 |           __enable_if_t<_And<is_base_of<ios_base, _Stream>, __is_ostreamable<_Stream&, const _Tp&> >::value, int> = 0>
|                                                                                                 ~
918 | _LIBCPP_HIDE_FROM_ABI _Stream&& operator<<(_Stream&& __os, const _Tp& __x) {
|                                 ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:957:1: note: candidate template ignored: could not match 'unique_ptr<_Yp, _Dp>' against 'void'
957 | operator<<(basic_ostream<_CharT, _Traits>& __os, unique_ptr<_Yp, _Dp> const& __p) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:241:56: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'ostream &(*)(ostream &)' for 1st argument
241 |   inline _LIBCPP_HIDE_FROM_ABI_AFTER_V1 basic_ostream& operator<<(basic_ostream& (*__pf)(basic_ostream&)) {
|                                                        ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:246:3: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'basic_ios<char_type, traits_type> &(*)(basic_ios<char_type, traits_type> &)' (aka 'basic_ios<char, std::char_traits<char>> &(*)(basic_ios<char, std::char_traits<char>> &)') for 1st argument
246 |   operator<<(basic_ios<char_type, traits_type>& (*__pf)(basic_ios<char_type, traits_type>&)) {
|   ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:251:56: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'ios_base &(*)(ios_base &)' for 1st argument
251 |   inline _LIBCPP_HIDE_FROM_ABI_AFTER_V1 basic_ostream& operator<<(ios_base& (*__pf)(ios_base&)) {
|                                                        ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:256:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'bool' for 1st argument
256 |   basic_ostream& operator<<(bool __n);
|                  ^          ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:257:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'short' for 1st argument
257 |   basic_ostream& operator<<(short __n);
|                  ^          ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:258:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned short' for 1st argument
258 |   basic_ostream& operator<<(unsigned short __n);
|                  ^          ~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:259:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'int' for 1st argument
259 |   basic_ostream& operator<<(int __n);
|                  ^          ~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:260:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned int' for 1st argument
260 |   basic_ostream& operator<<(unsigned int __n);
|                  ^          ~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:261:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long' for 1st argument
261 |   basic_ostream& operator<<(long __n);
|                  ^          ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:262:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned long' for 1st argument
262 |   basic_ostream& operator<<(unsigned long __n);
|                  ^          ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:263:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long long' for 1st argument
263 |   basic_ostream& operator<<(long long __n);
|                  ^          ~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:264:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned long long' for 1st argument
264 |   basic_ostream& operator<<(unsigned long long __n);
|                  ^          ~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:265:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'float' for 1st argument
265 |   basic_ostream& operator<<(float __f);
|                  ^          ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:266:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'double' for 1st argument
266 |   basic_ostream& operator<<(double __f);
|                  ^          ~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:267:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long double' for 1st argument
267 |   basic_ostream& operator<<(long double __f);
|                  ^          ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:268:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'const void *' for 1st argument
268 |   basic_ostream& operator<<(const void* __p);
|                  ^          ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:276:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'basic_streambuf<char_type, traits_type> *' (aka 'basic_streambuf<char, std::char_traits<char>> *') for 1st argument
276 |   basic_ostream& operator<<(basic_streambuf<char_type, traits_type>* __sb);
|                  ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:281:40: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'nullptr_t' (aka 'std::nullptr_t') for 1st argument
281 |   _LIBCPP_HIDE_FROM_ABI basic_ostream& operator<<(nullptr_t) { return *this << "nullptr"; }
|                                        ^          ~~~~~~~~~
/Users/isabellainio/CS210CPPRepo-A2/03_adt_stack/main.cpp:26:44: error: invalid operands to binary expression ('basic_ostream<char, char_traits<char>>' and 'void')
26 |     std::cout << "\nPopping empty stack: " << emptyStack.pop() << std::endl;
|     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:698:55: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'char' for 2nd argument
698 | _LIBCPP_HIDE_FROM_ABI basic_ostream<_CharT, _Traits>& operator<<(basic_ostream<_CharT, _Traits>& __os, char __cn) {
|                                                       ^                                                ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:725:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'char' for 2nd argument
725 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, char __c) {
|                                                     ^                                              ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:730:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'signed char' for 2nd argument
730 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, signed char __c) {
|                                                     ^                                              ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:735:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'unsigned char' for 2nd argument
735 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, unsigned char __c) {
|                                                     ^                                              ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:747:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const char *' for 2nd argument
747 | operator<<(basic_ostream<_CharT, _Traits>& __os, const char* __strn) {
| ^                                                ~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:786:53: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const char *' for 2nd argument
786 | _LIBCPP_HIDE_FROM_ABI basic_ostream<char, _Traits>& operator<<(basic_ostream<char, _Traits>& __os, const char* __str) {
|                                                     ^                                              ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:792:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const signed char *' for 2nd argument
792 | operator<<(basic_ostream<char, _Traits>& __os, const signed char* __str) {
| ^                                              ~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:799:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const unsigned char *' for 2nd argument
799 | operator<<(basic_ostream<char, _Traits>& __os, const unsigned char* __str) {
| ^                                              ~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:937:1: note: candidate function template not viable: cannot convert argument of incomplete type 'void' to 'const error_code' for 2nd argument
937 | operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __ec) {
| ^                                                ~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:693:55: note: candidate template ignored: deduced conflicting types for parameter '_CharT' ('char' vs. 'void')
693 | _LIBCPP_HIDE_FROM_ABI basic_ostream<_CharT, _Traits>& operator<<(basic_ostream<_CharT, _Traits>& __os, _CharT __c) {
|                                                       ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/cstddef:111:38: note: candidate template ignored: requirement 'is_integral<void>::value' was not satisfied [with _Integer = void]
111 | _LIBCPP_HIDE_FROM_ABI constexpr byte operator<<(byte __lhs, _Integer __shift) noexcept {
|                                      ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/__random/uniform_int_distribution.h:234:1: note: candidate template ignored: could not match 'uniform_int_distribution<_IT>' against 'void'
234 | operator<<(basic_ostream<_CharT, _Traits>& __os, const uniform_int_distribution<_IT>& __x) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:741:1: note: candidate template ignored: could not match 'const _CharT *' against 'void'
741 | operator<<(basic_ostream<_CharT, _Traits>& __os, const _CharT* __str) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:925:1: note: candidate template ignored: could not match 'basic_string<_CharT, _Traits, _Allocator>' against 'void'
925 | operator<<(basic_ostream<_CharT, _Traits>& __os, const basic_string<_CharT, _Traits, _Allocator>& __str) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:931:1: note: candidate template ignored: could not match 'basic_string_view<_CharT, _Traits>' against 'void'
931 | operator<<(basic_ostream<_CharT, _Traits>& __os, basic_string_view<_CharT, _Traits> __sv) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:943:1: note: candidate template ignored: could not match 'shared_ptr<_Yp>' against 'void'
943 | operator<<(basic_ostream<_CharT, _Traits>& __os, shared_ptr<_Yp> const& __p) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:963:1: note: candidate template ignored: could not match 'bitset<_Size>' against 'void'
963 | operator<<(basic_ostream<_CharT, _Traits>& __os, const bitset<_Size>& __x) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:918:33: note: candidate template ignored: substitution failure [with _Stream = basic_ostream<char, char_traits<char>> &, _Tp = void]: cannot form a reference to 'void'
917 |           __enable_if_t<_And<is_base_of<ios_base, _Stream>, __is_ostreamable<_Stream&, const _Tp&> >::value, int> = 0>
|                                                                                                 ~
918 | _LIBCPP_HIDE_FROM_ABI _Stream&& operator<<(_Stream&& __os, const _Tp& __x) {
|                                 ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:957:1: note: candidate template ignored: could not match 'unique_ptr<_Yp, _Dp>' against 'void'
957 | operator<<(basic_ostream<_CharT, _Traits>& __os, unique_ptr<_Yp, _Dp> const& __p) {
| ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:241:56: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'ostream &(*)(ostream &)' for 1st argument
241 |   inline _LIBCPP_HIDE_FROM_ABI_AFTER_V1 basic_ostream& operator<<(basic_ostream& (*__pf)(basic_ostream&)) {
|                                                        ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:246:3: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'basic_ios<char_type, traits_type> &(*)(basic_ios<char_type, traits_type> &)' (aka 'basic_ios<char, std::char_traits<char>> &(*)(basic_ios<char, std::char_traits<char>> &)') for 1st argument
246 |   operator<<(basic_ios<char_type, traits_type>& (*__pf)(basic_ios<char_type, traits_type>&)) {
|   ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:251:56: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'ios_base &(*)(ios_base &)' for 1st argument
251 |   inline _LIBCPP_HIDE_FROM_ABI_AFTER_V1 basic_ostream& operator<<(ios_base& (*__pf)(ios_base&)) {
|                                                        ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:256:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'bool' for 1st argument
256 |   basic_ostream& operator<<(bool __n);
|                  ^          ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:257:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'short' for 1st argument
257 |   basic_ostream& operator<<(short __n);
|                  ^          ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:258:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned short' for 1st argument
258 |   basic_ostream& operator<<(unsigned short __n);
|                  ^          ~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:259:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'int' for 1st argument
259 |   basic_ostream& operator<<(int __n);
|                  ^          ~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:260:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned int' for 1st argument
260 |   basic_ostream& operator<<(unsigned int __n);
|                  ^          ~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:261:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long' for 1st argument
261 |   basic_ostream& operator<<(long __n);
|                  ^          ~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:262:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned long' for 1st argument
262 |   basic_ostream& operator<<(unsigned long __n);
|                  ^          ~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:263:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long long' for 1st argument
263 |   basic_ostream& operator<<(long long __n);
|                  ^          ~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:264:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'unsigned long long' for 1st argument
264 |   basic_ostream& operator<<(unsigned long long __n);
|                  ^          ~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:265:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'float' for 1st argument
265 |   basic_ostream& operator<<(float __f);
|                  ^          ~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:266:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'double' for 1st argument
266 |   basic_ostream& operator<<(double __f);
|                  ^          ~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:267:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'long double' for 1st argument
267 |   basic_ostream& operator<<(long double __f);
|                  ^          ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:268:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'const void *' for 1st argument
268 |   basic_ostream& operator<<(const void* __p);
|                  ^          ~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:276:18: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'basic_streambuf<char_type, traits_type> *' (aka 'basic_streambuf<char, std::char_traits<char>> *') for 1st argument
276 |   basic_ostream& operator<<(basic_streambuf<char_type, traits_type>* __sb);
|                  ^          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/ostream:281:40: note: candidate function not viable: cannot convert argument of incomplete type 'void' to 'nullptr_t' (aka 'std::nullptr_t') for 1st argument
281 |   _LIBCPP_HIDE_FROM_ABI basic_ostream& operator<<(nullptr_t) { return *this << "nullptr"; }
|                                        ^          ~~~~~~~~~
1 error generated.
make[3]: *** [CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.o] Error 1
make[3]: *** Waiting for unfinished jobs....
2 errors generated.
make[3]: *** [CMakeFiles/03_adt_stack.dir/03_adt_stack/main.cpp.o] Error 1
make[2]: *** [CMakeFiles/03_adt_stack.dir/all] Error 2
make[1]: *** [CMakeFiles/03_adt_stack.dir/rule] Error 2
make: *** [03_adt_stack] Error 2**


