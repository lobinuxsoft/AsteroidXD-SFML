set ProjectDir=%~1
set TargetDir=%~2
set DLLDirSFML=%~3

xcopy "%ProjectDir%resources\" "%TargetDir%resources\" /E /Y
copy "%DLLDirSFML%\openal32.dll" "%TargetDir%openal32.dll" /Y
copy "%DLLDirSFML%\sfml-audio-2.dll" "%TargetDir%sfml-audio-2.dll" /Y
copy "%DLLDirSFML%\sfml-graphics-2.dll" "%TargetDir%sfml-graphics-2.dll" /Y
copy "%DLLDirSFML%\sfml-network-2.dll" "%TargetDir%sfml-network-2.dll" /Y
copy "%DLLDirSFML%\sfml-system-2.dll" "%TargetDir%sfml-system-2.dll" /Y
copy "%DLLDirSFML%\sfml-window-2.dll" "%TargetDir%sfml-window-2.dll" /Y