#include <iostream>
#include <array>
//----------------------------
#if __has_include(<conio.h>)
#include <conio.h>
#else
#include <curses.h>
#endif
//----------------------------


bool GetKey(int KEYCODE){
    return getch()==KEYCODE;
}




#if 0
int main() {
    
    int i=key::put();
    key kk;
    kk.put();


    initscr(); // ncursesの初期化
    noecho();  // キー入力を表示しない
    keypad(stdscr, TRUE); // 特殊キーを有効にする

    char c;
    while ((c = getch()) != 'q') {
        std::cout << "\r'" << c << "'が押されました。"<<std::endl;
        refresh(); // 画面を更新
    }

    endwin(); // ncursesの終了
    std::cout << "終了" << std::endl;
    
    return 0;
}
#endif