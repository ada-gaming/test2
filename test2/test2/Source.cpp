#include <Windows.h>
#include <array>
#include <cstddef>
#include <cstdlib>

void move(int& dir, ::std::size_t& pos, ::std::size_t max)
{
	switch (rand() % 20)
	{
	case 0: dir = 0; return;
	case 5: dir = -1; break;
	case 10: dir = 1; break;
	case 15: dir *= -1; break;
	}
	if (0 < dir)
	{
		if ((max - 1) == pos) pos = 0; else pos += 1;
	}
	else if (dir < 0)
	{
		if (0 == pos) pos = max - 1; else pos -= 1;
	}
}

int wmain(int argc, wchar_t** argv)
{
	constexpr ::std::size_t const width{ 80 };
	constexpr ::std::size_t const height{ 30 };
	::std::array<wchar_t, width* height> buf{};
	for (::std::size_t char_index{}; buf.size() != char_index; ++char_index)
	{
		buf[char_index] = (0 != ((char_index + 1) % width)) ? L' ' : L'\n';
	}
	::std::size_t col_pos{};
	::std::size_t row_pos{};
	int x_dir{};
	int y_dir{};
	::std::array<::std::size_t, 42> tail{};
	::std::size_t cur_tail_end_index{};
	::HANDLE const output{ ::GetStdHandle(STD_OUTPUT_HANDLE) };
	::CONSOLE_CURSOR_INFO cursor_info{ sizeof(cursor_info), FALSE }; // hide cursor
	::SetConsoleCursorInfo(output, ::std::addressof(cursor_info));
	for (;;)
	{
		buf[tail[cur_tail_end_index]] = L'·';
		++cur_tail_end_index;
		cur_tail_end_index %= tail.size();
		buf[tail[cur_tail_end_index]] = L' ';
		::move(x_dir, col_pos, width - 1);
		::move(y_dir, row_pos, height);
		tail[cur_tail_end_index] = width * row_pos + col_pos;
		buf[tail[cur_tail_end_index]] = L'O';
		::SetConsoleCursorPosition(output, {});
		::WriteConsoleW(output, buf.data(), buf.size() - 1, {}, {});
		::Sleep(1000 / 60);
	}
}