1. скачать репозиторий. Папка с проектом: С:/Lidia/CPS

2. запустить Qt creator, file->open file or project -> C:/Lidia/CPS/zodiac.pro -> открыть

3. в Qt creator слева: projects-> галочку выставить только где Desktop Qt<version> MinGW 32bit
далее Buld -> build directory (правее) -> С:\Lidia\CPS\zodiac
далее Run -> working directory (правее) -> С:\Lidia\CPS\zodiac

4. в главном окне Qt creator:
Build->clean project "zodiac"
Build->run qmake
Build->Rebuild project "zodiac"

*примечания
слева если выбрать в Qt Creator Debug (под Help), будет работать дебаггер (нужно ткнуть play c жучком) 

Горячие клавиши Qt Creator
F2 - поиск определения функции
F10 - дебаггер пробегается по функциям
F11 - заход дебаггера в функцию
F5 - выполнение до точки останова
Alt + <- (стрелка влево) - вернуться к предыдущему пункту редактирования кода (вправо) - к следующему
