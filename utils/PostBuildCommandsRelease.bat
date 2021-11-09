set ProjectDir=%~1
set TargetDir=%~2
set DLLDir=%~3

xcopy "%ProjectDir%resources\" "%TargetDir%resources\" /E /Y
copy "%DLLDir%\openal32.dll" "%TargetDir%openal32.dll" /Y
copy "%DLLDir%\sfml-audio-2.dll" "%TargetDir%sfml-audio-2.dll" /Y
copy "%DLLDir%\sfml-graphics-2.dll" "%TargetDir%sfml-graphics-2.dll" /Y
copy "%DLLDir%\sfml-network-2.dll" "%TargetDir%sfml-network-2.dll" /Y
copy "%DLLDir%\sfml-system-2.dll" "%TargetDir%sfml-system-2.dll" /Y
copy "%DLLDir%\sfml-window-2.dll" "%TargetDir%sfml-window-2.dll" /Y