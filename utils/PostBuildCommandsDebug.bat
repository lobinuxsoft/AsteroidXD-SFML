set ProjectDir=%~1
set TargetDir=%~2
set DLLDirSFML=%~3

xcopy "%ProjectDir%resources\" "%TargetDir%resources\" /E /Y
copy "%DLLDirSFML%\openal32.dll" "%TargetDir%openal32.dll" /Y
copy "%DLLDirSFML%\sfml-audio-d-2.dll" "%TargetDir%sfml-audio-d-2.dll" /Y
copy "%DLLDirSFML%\sfml-graphics-d-2.dll" "%TargetDir%sfml-graphics-d-2.dll" /Y
copy "%DLLDirSFML%\sfml-network-d-2.dll" "%TargetDir%sfml-network-d-2.dll" /Y
copy "%DLLDirSFML%\sfml-system-d-2.dll" "%TargetDir%sfml-system-d-2.dll" /Y
copy "%DLLDirSFML%\sfml-window-d-2.dll" "%TargetDir%sfml-window-d-2.dll" /Y